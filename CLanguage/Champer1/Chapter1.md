> **C 语言简介**
>
> 作者:月牙博客
>
> 来源：`www.yueya.info`



#### 1.1 C 语言简介

```markdown
C语言是一门面向过程的计算机编程语言，与C++、Java等面向对象编程语言有所不同。
C语言的设计目标是提供一种能以简易的方式编译、处理低级存储器、仅产生少量的机器码以
及不需要任何运行环境支持便能运行的编程语言。C语言描述问题比汇编语言迅速，工作量小、
可读性好，易于调试、修改和移植，而代码质量与汇编语言相当。
C语言一般只比汇编语言代码生成的目标程序效率低10%～20%。因此，C语言可以编写系统软件。
```

#### 1.2 C语言的发展历史

```markdown
1.C语言之所以命名为C，是因为 C语言源自Ken Thompson发明的B语言，而 B语言则源自BCPL语言。

2.20世纪60年代，美国AT&T公司贝尔实验室（AT&T Bell Laboratory）的研究员Ken Thompson闲来无事，手痒难耐，想玩一个他自己编的，模拟在太阳系航行的电子游戏——Space Travel。他背着老板，找到了台空闲的机器——PDP-7。但这台机器没有操作系统，而游戏必须使用操作系统的一些功能，于是他着手为PDP-7开发操作系统。后来，这个操作系统被命名为——UNIX。

3.1970年，美国贝尔实验室的 Ken Thompson，以BCPL语言为基础，设计出很简单且很接近硬件的B语言（取BCPL的首字母）。并且他用B语言写了第一个UNIX操作系统。

4.1971年，同样酷爱Space Travel的Dennis M.Ritchie为了能早点儿玩上游戏，加入了Thompson的开发项目，合作开发UNIX。他的主要工作是改造B语言，使其更成熟。

5.1972年，美国贝尔实验室的 D.M.Ritchie 在B语言的基础上最终设计出了一种新的语言，他取了BCPL的第二个字母作为这种语言的名字，这就是C语言。
```



#### 1.3 编程开发

* 编译器

  ```markdown
  GCC，GNU组织开发的开源免费的编译器
  
  MinGW，Windows操作系统下的GCC
  
  Clang，开源的BSD协议的基于LLVM的编译器
  
  Visual C++:: cl.exe，Microsoft VC++自带的编译器
  ```

* 集成开发环境

  ```markdown
  Code::Blocks，开源免费的C/C++ IDE
  
  CodeLite，开源、跨平台的C/C++集成开发环境
  
  OrwellDev-C++，可移植的C/C++IDE
  
  C-Free
  
  Light Table
  
  Visual Studio系列
  ```

  

#### 1.4 第一个程序

```c
#include <stdio.h>
int main(void)
{
    printf("Hello World!");
    return 0;
}
```



#### 1.5 语言标准

* `C99`标准
* `C11`标准

#### 1.6 语言特点

* 高效性
* 灵活性
* 功能丰富
* 表达力强
* 移植性好

