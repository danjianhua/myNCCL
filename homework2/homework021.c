/*
*output:
*global:422a30 422a34 422a38
*local: 12ff44 12ff40 12ff3c
*conclusion:
*1.ȫ�ֱ�����ĵ�ַ������ɣ��������ɱ���������˳���ַ�������
*2.�ֲ�������ĵ�ַ������ɣ��������ɱ���������˳���ַ����ݼ�
*3.ȫ�ֱ����;ֲ�������Ĺ��ɣ�û�й���
*/

#include <stdio.h>

int global1 = 10;
int global2 = 20;
int global3 = 30;

int main(void)
{

	int local1 = 1;
	int local2 = 2;
	int local3 = 3;
	printf("global1 address -- %x\n", &global1);
	printf("global2 address -- %x\n", &global2);
	printf("global3 address -- %x\n", &global3);
	printf("-------------------------\n");
	printf("local1 address -- %x\n", &local1);
	printf("local2 address -- %x\n", &local2);
	printf("local3 address -- %x\n", &local3);
	
	return 0;
}