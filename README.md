## C 语言学习

>月牙博客

[TOC]



![](Image/C.png)

### C语言基础部分






#### 第一章 C语言概述

#### 1.1 C语言发展
`计算机语言`

- 机器语言
- 汇编语言
- 高级语言


#### 1.2 C语言特点

- 语言简洁
- 运算符丰富
- 具有结构化的控制语句
- 语法限制不太严格
`高级语言的发展`
1. 非结构化语言
2. 结构化语言
3. 面向对象语言

#### 1.3 最简单的C语言

```c
#include <stdio.h>
int main(void)
{
    printf("Hello World!\n);
    return 0;
}
```
#### 1.4 注释

```c
#include <stdio.h>
int main(void)
{
    /*
    There will be not output  Hello World!
    */
    //printf("Hello World!\n);
    return 0;
}
```

#### 1.5 数据类型

> 程序必须使用不同的方式来存储和处理不同类型的数据

* 基本类型
  * 标准整数类型
  * 实数浮点类型
  
* 枚举类型

* void类型

  > void 类型修饰符(type specifier)表示"没有值可以获得"。因此，不可以采用这个类型声明变量或常量。

  * void用于函数声明

    > void类型表达式指的是没有值的表达式。
    >
    > void 类型的表达式
    >
    > ```c
    > char filrename[] = "momo.txt"
    >  if(fopen(filename,"r") == NULL)
    >  {
    >      perros(filename);//void表达式
    >  }
    > ```
    >
    > 类型转换(cast)运算(void)表达式显式地将表达式的返回值丢弃
    >
    > ```c
    > (void)printf("I do not need this function's return value!\n");
    > ```
    >
    > 

  * void类型表达式

  * 指向void的指针

* 派生类型

* 联合类型

* 函数类型





### 第二章 算法

#### 2.1 什么是算法

#### 2.2 简单的算法举例

#### 2.3 三种基本结构和改进的流程图



### 第三章 语句

#### 3.1 表达式语句

#### 3.2 语句块

#### 3.3 循环



### 第四章 类型转换



### 第五章 表达式和运算符



### 第六章 函数

### 第七章 数组

### 第八章 指针



### 第九章 结构、联合与位字段



















