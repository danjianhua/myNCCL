
/*
homework2.�޸Ĵ��룬ͨ��ǿ������ת������ӡһ�� &global + 1 ��ֵ�Ƕ��٣�
ֵΪ��ԭ���Ļ����ϼ�4
homework3.�޸Ĵ��룬��������� global ����Ϊ char, short, float ���ͻ���ʲô��ͬ��
��ӡ���Ϊ��
global:422a30 422a31  422a32 422a34 422a34 422a38

���ۣ�1.&global+1�Ľ��Ϊԭ�����ĵ�ַ���ϵ�ַ��ƫ����������ַ��ƫ������ԭ���������;����ġ�
2.global2����ʼ��ַΪ422a32������422a31������ڴ�����йأ�Ϊ����߳����Ч��
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