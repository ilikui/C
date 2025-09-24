#include "DataCfg.h"
#include <stdbool.h>
#include <math.h>
#include <stddef.h>

#include <stdio.h>


#define bool	_Bool
// 查表数据结构
typedef struct {
    uint16 adc_value;
    float sensor_value;
} LookupTable;

// 车内温度传感器查表数据（ADC值从大到小排列）
static const LookupTable incar_temp_table[] = {
    {3736, -40.0f}, {3731, -39.0f}, {3726, -38.0f}, {3720, -37.0f}, {3715, -36.0f},
    {3700, -30.0f}, {3650, -20.0f}, {3600, -10.0f}, {3550, 0.0f}, {3500, 10.0f},
    {3450, 20.0f}, {3400, 30.0f}, {3350, 40.0f}, {3300, 50.0f}
};

// 出风口温度传感器查表数据
static const LookupTable outlet_temp_table[] = {
    {3700, -30.0f}, {3650, -20.0f}, {3600, -10.0f}, {3550, 0.0f}, {3500, 10.0f},
    {3450, 20.0f}, {3400, 30.0f}, {3350, 40.0f}, {3300, 50.0f}
};

// 高压压力传感器查表数据（单位：MPa，ADC值从小到大排列）
static const LookupTable high_pressure_table[] = {
    {1000, 0.0f}, {1500, 0.5f}, {2000, 1.0f}, {2500, 1.5f}, 
    {3000, 2.0f}, {3500, 2.5f}, {4000, 3.0f}
};

// 低压压力传感器查表数据（单位：MPa）
static const LookupTable low_pressure_table[] = {
    {1000, 0.0f}, {1200, 0.2f}, {1400, 0.4f}, {1600, 0.6f}, 
    {1800, 0.8f}, {2000, 1.0f}, {2200, 1.2f}, {2400, 1.4f}
};

// 各通道的ADC范围配置
static const struct {
    uint16 min_adc;
    uint16 max_adc;
    bool is_temperature;  // true=温度传感器, false=压力传感器
} channel_config[CHANNEL_COUNT] = {
    [CHANNEL_INCAR_TEMP]    = {3300, 3736, true},
    [CHANNEL_OUTLET_TEMP]   = {3300, 3700, true},
    [CHANNEL_HIGH_PRESSURE] = {1000, 4000, false},
    [CHANNEL_LOW_PRESSURE]  = {1000, 2400, false}
};

// 精度处理（四舍五入到0.1）
static float round_to_01(float value) {
    return roundf(value * 10.0f) / 10.0f;
}

// 在查表中查找ADC值对应的索引
static int find_table_index(const LookupTable* table, uint16 table_size, uint16 adc_value, bool is_temperature_table) {
    // 温度表是降序排列，压力表是升序排列
    if (is_temperature_table) {
        // 温度表：ADC值从大到小
        if (adc_value >= table[0].adc_value) return 0;
        if (adc_value <= table[table_size-1].adc_value) return table_size-1;
        
        for (int i = 0; i < table_size - 1; i++) {
            if (adc_value <= table[i].adc_value && adc_value >= table[i+1].adc_value) {
                return i;
            }
        }
    } else {
        // 压力表：ADC值从小到大
        if (adc_value <= table[0].adc_value) return 0;
        if (adc_value >= table[table_size-1].adc_value) return table_size-1;
        
        for (int i = 0; i < table_size - 1; i++) {
            if (adc_value >= table[i].adc_value && adc_value <= table[i+1].adc_value) {
                return i;
            }
        }
    }
    return -1; // 未找到
}

// 核心查表函数：传入ADC值和通道，返回物理值和有效性
SensorResult GetSensorValue(SensorChannel channel, uint16 adc_value) {
    SensorResult result = {0};
    
    // 检查通道有效性
    if (channel >= CHANNEL_COUNT) {
        result.is_valid = false;
        result.sensor_value = 0.0f;
        return result;
    }
    
    // 检查ADC值是否在有效范围内
    if (adc_value < channel_config[channel].min_adc || adc_value > channel_config[channel].max_adc) {
        result.is_valid = false;
        // 设置无效值：温度=-40℃，压力=0MPa
        result.sensor_value = channel_config[channel].is_temperature ? -40.0f : 0.0f;
        return result;
    }
    
    // 选择对应的查表数据
    const LookupTable* table = NULL;
    uint16 table_size = 0;
    bool is_temperature_table = false;
    
    switch (channel) {
        case CHANNEL_INCAR_TEMP:
            table = incar_temp_table;
            table_size = sizeof(incar_temp_table) / sizeof(incar_temp_table[0]);
            is_temperature_table = true;
            break;
        case CHANNEL_OUTLET_TEMP:
            table = outlet_temp_table;
            table_size = sizeof(outlet_temp_table) / sizeof(outlet_temp_table[0]);
            is_temperature_table = true;
            break;
        case CHANNEL_HIGH_PRESSURE:
            table = high_pressure_table;
            table_size = sizeof(high_pressure_table) / sizeof(high_pressure_table[0]);
            is_temperature_table = false;
            break;
        case CHANNEL_LOW_PRESSURE:
            table = low_pressure_table;
            table_size = sizeof(low_pressure_table) / sizeof(low_pressure_table[0]);
            is_temperature_table = false;
            break;
        default:
            result.is_valid = false;
            result.sensor_value = 0.0f;
            return result;
    }
    
    // 查找ADC值在表中的位置
    int index = find_table_index(table, table_size, adc_value, is_temperature_table);
    if (index == -1) {
        result.is_valid = false;
        result.sensor_value = channel_config[channel].is_temperature ? -40.0f : 0.0f;
        return result;
    }
    
    // 精确匹配
    if (table[index].adc_value == adc_value) {
        result.sensor_value = table[index].sensor_value;
        result.is_valid = true;
        return result;
    }
    
    // 线性插值
    int next_index = (is_temperature_table) ? index + 1 : index + 1;
    if (next_index >= table_size) {
        result.sensor_value = table[index].sensor_value;
        result.is_valid = true;
        return result;
    }
    
    // 计算插值比例
    float ratio;
    if (is_temperature_table) {
        // 温度表：ADC值递减
        ratio = (float)(adc_value - table[next_index].adc_value) / 
               (table[index].adc_value - table[next_index].adc_value);
    } else {
        // 压力表：ADC值递增
        ratio = (float)(adc_value - table[index].adc_value) / 
               (table[next_index].adc_value - table[index].adc_value);
    }
    
    // 计算插值结果
    float raw_value;
    if (is_temperature_table) {
        raw_value = table[next_index].sensor_value + 
                   ratio * (table[index].sensor_value - table[next_index].sensor_value);
    } else {
        raw_value = table[index].sensor_value + 
                   ratio * (table[next_index].sensor_value - table[index].sensor_value);
    }
    
    result.sensor_value = round_to_01(raw_value);
    result.is_valid = true;
    return result;
}



int main() {
    printf("=== System  ===\n\n");
    
    // 测试用例
    struct {
        SensorChannel channel;
        uint16 adc_value;
        const char* name;
    } test_cases[] = {
        {CHANNEL_INCAR_TEMP, 3720, "1"},
        {CHANNEL_OUTLET_TEMP, 3550, "2"},
        {CHANNEL_HIGH_PRESSURE, 2500, "3"},
        {CHANNEL_LOW_PRESSURE, 1600, "4"},
        {CHANNEL_INCAR_TEMP, 1000, "5"} // 无效数据测试
    };
    
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        SensorResult result = GetSensorValue(test_cases[i].channel, test_cases[i].adc_value);
        
        const char* unit = (test_cases[i].channel == CHANNEL_HIGH_PRESSURE || 
                           test_cases[i].channel == CHANNEL_LOW_PRESSURE) ? "MPa" : "℃";
        
        printf("%s: ADC=%d -> %.1f%s [%s]\n", 
               test_cases[i].name,
               test_cases[i].adc_value,
               result.sensor_value, 
               unit,
               result.is_valid ? "valid" : "invalid");
    }
    
    return 0;
}

