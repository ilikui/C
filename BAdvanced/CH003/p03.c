#include <stdio.h>

#define FUNC(type, memclass)           type
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const
#define CONST(consttype, memclass)     const consttype
#define VAR( type, memclass )          type

FUNC(int, memclass) TestFunction() {
  return 0;
}

int main(void) {
  VAR(int, memclass) testVariable = 10;
  CONST(int, memclass) testConst = 20;

  P2VAR(int, memclass, ptrclass) testPointer = &testVariable;
  CONSTP2VAR(int, memclass, ptrclass) testConstPointer = &testVariable;
  CONSTP2CONST(int, memclass, ptrclass) testConstPointerConst = &testConst;

  printf("Test variable value: %d\n", testVariable);
  printf("Test constant value: %d\n", testConst);
  printf("Test pointer value: %d\n", *testPointer);
  printf("Test constant pointer value: %d\n", *testConstPointer);
  printf("Test constant pointer to constant value: %d\n", *testConstPointerConst);
  printf("Test function return value: %d\n", TestFunction());

  return 0;
}

/**
 
这些是宏定义，它们用于在编译时将宏名称替换为宏定义的内容。它们主要用于程序编码风格和类型规范。

FUNC(type, memclass) 定义一个类型为“type”的函数。
P2VAR(ptrtype, memclass, ptrclass) 定义一个类型为指向“ptrtype”的指针的变量。
P2CONST(ptrtype, memclass, ptrclass) 定义一个类型为指向常量“ptrtype”的指针的变量。
CONSTP2VAR(ptrtype, memclass, ptrclass) 定义一个常量指针，指向类型为“ptrtype”的变量。
CONSTP2CONST(ptrtype, memclass, ptrclass) 定义一个常量指针，指向类型为常量“ptrtype”的变量。
CONST(consttype, memclass) 定义一个类型为常量“consttype”的变量。
VAR(type, memclass) 定义一个类型为“type”的变量。
请注意，在这些宏定义中，第二个和第三个参数“memclass”和“ptrclass”并不被使用，因此它们可能是没有意义的。


*/