/*****************************8.1***********************************/
/*求1-100以内最大的素数，要求用设计一个函数实现。*/
#include <stdio.h>
#include <math.h>

int is_prime(int num)
{
	int i;
	int tmp = (int)sqrt(num);
	
	for (i = 2; i <= tmp; i++)
	{
		if (num % i == 0)
			break ;
	}

	if (i == tmp + 1)
		return num;
	else
		return 0;
}

int main(void)
{
	int begin = 2;
	int end   = 100;
	int max_prime;
	int i;

	for (i = begin; i < end; i++)
		{
			int tmp_prime = is_prime(i);
			if (tmp_prime != 0)
				max_prime = tmp_prime;
		}

	printf ("the max prime = %d between 1 and 100\n", max_prime);
		
	return 0;
}

/*******************************************************************
the max prime = 97 between 1 and 100
********************************************************************/


/*****************************8.2***********************************/
/*用户输入两个数字，按从个位对齐的方式，找出这2个数在相同位置处数字也相同的个数。
例如：123 和 5173 这2个数字，位置相同数字也相同的个数是 2*/

#include <stdio.h>

int compare_num(int fir_num, int sec_num)
{
	if (fir_num == sec_num)
		return fir_num;
	else
		return -1;
}

int main(void)
{
	int fir_num, sec_num;
	int counter = 0;

	printf ("Please input two number(fir, sec):");
	scanf ("%d, %d", &fir_num, &sec_num);

	while (fir_num != 0 && sec_num != 0)
	{
		if (compare_num(fir_num % 10, sec_num % 10) != -1)
			counter++;

		fir_num /= 10;
		sec_num /= 10;
	}
	
	printf ("The position and the digit are the same number is %d\n", counter);

	return 0;
}

/*******************************************************************
Please input two number(fir, sec):12356, 82346
The position and the digit are the same number is 3

********************************************************************/
