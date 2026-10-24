# C Language Learning Resources · 优质学习资源库

> 本文整理公开可访问的 C 语言课程、练习、项目教程与系统编程资料。优先链接原始项目，方便长期维护和追踪上游更新。外部仓库的内容、许可证与活跃度会变化，开始学习前请阅读各项目的 README、LICENSE 和贡献说明。

## 1. 零基础与系统课程

| 资源 | 类型 | 推荐用法 | 链接 |
| --- | --- | --- | --- |
| CS50x | 大学课程 | 从问题求解与编程基础开始，按课程周次完成练习集 | https://cs50.harvard.edu/x/ |
| learn-c.org | 交互式教程 | 快速练习语法、指针、结构体和函数 | https://www.learn-c.org/ |
| Beej's Guide to C Programming | 在线教材 | 作为从基础到中级的实践参考，边读边写 | https://beej.us/guide/bgc/ |
| C-from-Scratch | 学习路线 | 参考从 C 基础继续深入汇编与操作系统的路线设计 | https://github.com/theokwebb/C-from-Scratch |
| K&R exercises and examples | 经典教材练习索引 | 配合《The C Programming Language》逐章练习，不要只看答案 | https://github.com/caisah/K-and-R-exercises-and-examples |

## 2. 练习、算法与反馈

| 资源 | 训练方向 | 建议任务 | 链接 |
| --- | --- | --- | --- |
| Exercism C Track | 小步练习与测试 | 每道题先独立实现，再比较反馈与其他实现 | https://github.com/exercism/c |
| TheAlgorithms/C | 算法实现 | 阅读排序、查找和数学算法，分析复杂度及边界 | https://github.com/TheAlgorithms/C |
| project-based-tutorials-in-c | 项目驱动学习 | 选择 Shell、内存分配器、模拟器、解释器等项目逐步实践 | https://github.com/7etsuo/project-based-tutorials-in-c |
| KofiWoodlock/LearningC | 分阶段路线 | 参考阶段目标、项目验收和 K&R 章节映射 | https://github.com/KofiWoodlock/LearningC |

## 3. 系统编程与底层原理

| 资源 | 学习方向 | 适用场景 | 链接 |
| --- | --- | --- | --- |
| angrave/SystemProgramming | Linux 系统编程 | 学习进程、内存分配、IPC、线程、同步和调试 | https://github.com/angrave/SystemProgramming |
| Beej's Guide to Network Programming | Socket 网络编程 | 学习 TCP/UDP、客户端/服务端和网络 API | https://beej.us/guide/bgnet/ |
| Compiler Explorer | 编译器与汇编观察 | 比较编译器输出，观察优化，但不要将某次汇编结果当作语言保证 | https://godbolt.org/ |
| cppreference: C | 语言与标准库参考 | 查阅标准库接口、语言规则及版本差异 | https://en.cppreference.com/w/c |
| CERT C Coding Standard | 安全编码 | 识别整数溢出、内存安全、输入验证等常见风险 | https://wiki.sei.cmu.edu/confluence/display/c |

## 4. 真实世界的 C 工程

| 项目 | 建议阅读主题 | 阅读策略 | 链接 |
| --- | --- | --- | --- |
| SQLite | 数据库内核、测试、可移植性 | 从一个 SQL 功能追踪解析、执行、存储与测试路径 | https://github.com/sqlite/sqlite |
| Redis | 事件循环、数据结构、内存管理 | 先研究一个命令的调用链，再查看数据结构与测试 | https://github.com/redis/redis |
| musl libc | C 标准库实现 | 从熟悉的标准库函数追踪到平台实现 | https://git.musl-libc.org/cgit/musl/ |
| FreeRTOS-Kernel | RTOS 内核与移植层 | 观察任务调度、同步原语、配置与端口层 | https://github.com/FreeRTOS/FreeRTOS-Kernel |
| Zephyr | 嵌入式系统与驱动模型 | 研究设备模型、构建系统、驱动接口和测试 | https://github.com/zephyrproject-rtos/zephyr |
| Linux Kernel | 操作系统与大型 C 工程 | 从一个子系统入手，结合文档、测试和代码规范阅读 | https://github.com/torvalds/linux |

## 5. 与本仓库配套的学习路径

建议以本仓库材料作为中文主线，外部资源作为补充，而不是同时开启十几套课程。

1. **先建立主线：** 阅读 STUDY_PLAN.md，按周安排学习。
2. **逐节学习：** 使用 Doc/细致小节/README.md，完成示例和练习。
3. **按主题查漏：** 使用 Doc/Topics/README.md，把疑问映射到具体知识专题。
4. **练习并验证：** 对练习启用编译警告，加入正常输入、边界输入和错误输入测试。
5. **做工程项目：** 完成 examples/automotive_c_demo/README.md 中的主机端构建与测试。
6. **阅读真实代码：** 选择一个成熟项目的小功能，记录入口、调用链、数据结构、错误处理和测试。

## 6. 推荐的工具链检查项

GCC/Clang 下可从以下参数开始，按目标平台调整：

~~~bash
cc -std=c11 -Wall -Wextra -Wpedantic -Wconversion -Wshadow \
  -g -O0 main.c -o app
~~~

开发阶段可以按环境使用 AddressSanitizer、UndefinedBehaviorSanitizer、Valgrind、GDB 或 LLDB。工具支持因操作系统、编译器版本和目标平台而异；在目标板上还需要独立进行平台验证。

## 7. 资源维护原则

- 优先保留原始项目链接，不复制未经许可的教材或代码。
- 对课程资源标明适用阶段和学习目标，避免只堆积链接。
- 定期检查链接是否可访问、项目是否归档、许可证是否清晰。
- 推荐资源应服务于课程阶段与实践任务，而不是仅依据 Star 数量排序。
- 外部示例仅用于学习参考，不应未经审查直接用于安全关键或量产系统。
