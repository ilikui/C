# Automotive C Demo：分层传感器服务

这是一个可在主机端构建的 C11 教学示例，演示如何把应用逻辑与硬件访问隔离。它不绑定特定 MCU，也不替代目标板、时序或功能安全验证。

## 目录

- `include/sensor_port.h`：平台传感器读取契约。
- `include/sensor_service.h`：数据质量与服务 API。
- `src/sensor_service.c`：范围检查、数据转换和新鲜度处理。
- `src/app.c`：简化的应用状态更新。
- `platform/host/fake_sensor.c`：主机端 Fake 驱动。
- `tests/test_main.c`：正常、过期、回绕、I/O 故障、越界与降级测试。
- `Makefile` / `CMakeLists.txt`：两种构建入口。

## 使用 Make

需要可用的 C11 编译器（例如 GCC 或 Clang）：

```sh
make test
make clean
```

## 使用 CMake

```sh
cmake -S . -B build-cmake
cmake --build build-cmake
ctest --test-dir build-cmake --output-on-failure
```

## 接口与行为约定

- Fake 或目标驱动成功时才写入原始采样值；失败时不写入输出参数。
- 服务层将原始值限制在配置范围内，并将 `raw * 10` 转为 milli-units。该比例只是演示值，真实项目必须使用传感器规格和标定数据。
- 每次读取失败或越界时，当前样本标记为无效，不能把上一次成功的值冒充成新样本。
- 数据年龄使用无符号 tick 差值，适用于同一单调计数器且比较间隔小于其完整回绕周期的场景。
- 应用状态仅演示 NORMAL/DEGRADED 路径，不构成安全机制或量产诊断策略。

## 扩展练习

1. 将硬编码的转换比例替换为有溢出分析的标定函数。
2. 增加一阶 IIR 或滑动平均，并测试滤波器初始化和异常样本策略。
3. 为传感器错误增加分类与计数，并定义恢复条件。
4. 为目标 MCU 实现新的 `sensor_read_raw_fn` 适配器，业务层不直接包含寄存器头文件。
5. 将主机测试、静态分析与目标工具链构建加入 CI。
