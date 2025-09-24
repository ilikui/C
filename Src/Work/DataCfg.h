#ifndef DATA_CFG_H
#define DATA_CFG_H  
#include <stdbool.h>
typedef unsigned int uint16;

// 传感器通道枚举
typedef enum {
    CHANNEL_INCAR_TEMP,      // 车内温度传感器
    CHANNEL_OUTLET_TEMP,     // 出风口温度传感器
    CHANNEL_HIGH_PRESSURE,   // 高压压力传感器
    CHANNEL_LOW_PRESSURE,    // 低压压力传感器
    CHANNEL_COUNT            // 通道数量
} SensorChannel;

// 传感器查询结果结构体
typedef struct {
    float sensor_value;      // 传感器物理值（温度℃/压力MPa）
    bool is_valid;           // 数据有效性
} SensorResult;

#endif