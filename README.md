## C 语言学习

>月牙博客



# 目录

---

* [C语言基础部分](#C语言基础部分)

  * [第一章 C语言概述](#第一章 C语言概述)
    * [1.1 C语言发展](#1.1 C语言发展)
  * [第二章 算法](#第二章 算法)
  * [第三章 语句](#第三章 语句)

  

  

  

  

  

  

  

  

  

  

  

  

  

  ---

  

  



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

```markdown
(1)算法是一系列解决问题的清晰指令，也就是说，能够对一定规范的输入，在有限时间内获得所要求的输出。算法常常含有重复的步骤和一些比较或逻辑判断。如果一个算法有缺陷，或不适合于某个问题，执行这个算法将不会解决这个问题。不同的算法可能用不同的时间、空间或效率来完成同样的任务。一个算法的优劣可以用空间复杂度与时间复杂度来衡量。
(2)算法的时间复杂度是指算法需要消耗的时间资源。一般来说，计算机算法是问题规模n 的函数f(n)，算法执行的时间的增长率与f(n) 的增长率正相关，称作渐进时间复杂度（Asymptotic Time Complexity）。时间复杂度用“O（数量级）”来表示，称为“阶”。常见的时间复杂度有： O（1）常数阶；O（log2n）对数阶；O（n）线性阶；O（n2）平方阶。
(3)算法的空间复杂度是指算法需要消耗的空间资源。其计算和表示方法与时间复杂度类似，一般都用复杂度的渐近性来表示。同时间复杂度相比，空间复杂度的分析要简单得多。
```



#### 2.2 简单的算法举例

#### 2.3 三种基本结构和改进的流程图



### 第三章 语句

#### 3.1 表达式语句

> 表达式语句(expression statement)是后面跟着一个分号的表达式

#### 3.2 语句块

#### 3.3 循环

#### 3.4 选择语句

#### 3.5 无条件跳转





### 第四章 类型转换



### 第五章 表达式和运算符



### 第六章 函数

### 第七章 数组

### 第八章 指针

> 指针(pointer)是对数据对象或函数的一种引用。指针有多种用途，例如定义"传址调用"函数，它还可以实现动态数据结构，例如链表和树。

#### 8.1 声明指针



#### 8.2 指针运算



#### 8.3 数组的指针和指针的数组



#### 8.4 指向函数的指针



### 第九章 结构、联合与位字段



















