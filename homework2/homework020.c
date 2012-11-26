
/*
homework2.修改代码，通过强制类型转换，打印一下 &global + 1 的值是多少？
值为在原来的基础上加4
homework3.修改代码，看看如果把 global 定义为 char, short, float 类型会有什么不同？
打印结果为：
global:422a30 422a31  422a32 422a34 422a34 422a38

结论：1.&global+1的结果为原变量的地址加上地址的偏移量，而地址的偏移量由原变量的类型决定的。
2.global2的起始地址为422a32而不是422a31，这和内存对齐有关，为了提高程序的效率
*/


#include <stdio.h>

char   global1	= 'f';
short  global2	= 20;
float  global3	= 60.5f;


int main(void)
{

	char local1 = 1;
	int local2 = 2;
	int local3 = 3;
	printf("global1 address   -- %p\n", &global1);
	printf("global1 address+1 -- %p\n", &global1+1);
	printf("global2 address   -- %p\n", &global2);
	printf("global2 address+1 -- %p\n", &global2+1);
	printf("global3 address   -- %p\n", &global3);
	printf("global3 address+1 -- %p\n", &global3+1);
	
	return 0;
}