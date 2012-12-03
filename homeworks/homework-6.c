/*****************************6.1***********************************/
/*打印1个 5*5 的棋盘(0表示空，1表示有子)，用户输入1个位置坐标落子后，重
新打印棋盘。*/
#include <stdio.h>

#define ROW_AMOUNT	  5
#define COL_AMOUNT    	  5

int input_num(int max_index)
{
	int num;

	while(1)
	{
		printf("Please enter the number between 0 and %d:", max_index);
		scanf("%d", &num);
		if (num >= max_index)
			printf("You input number is too big\n");
		else if (num < 0)
			printf ("You input number is too small");
		else 
			return num;
	}
}

int main(void)
{
	int arr[ROW_AMOUNT][COL_AMOUNT] = {0};
	int input_x;
	int input_y;
	int i, j;

	for (i=0; i<ROW_AMOUNT; i++)
	{   
		for (j=0; j<COL_AMOUNT; j++)
           printf(" %d ", arr[i][j]);
           printf("\n");
	}

	while (1)
	{
		printf("please input rownum\n");
		input_x = input_num(ROW_AMOUNT);
		printf("please input colnum\n");
		input_y = input_num(COL_AMOUNT);
	
		arr[input_x][input_y] = 1;

		for (i=0; i<ROW_AMOUNT; i++)
		{
			for (j=0; j<COL_AMOUNT; j++)
				printf(" %d ", arr[i][j]);
			printf("\n");
		}
	}

	return 0;
}
/******************************************************************
 0  0  0  0  0 
 0  0  0  0  0 
 0  0  0  0  0 
 0  0  0  0  0 
 0  0  0  0  0 
please input rownum
Please enter the number between 0 and 5:0 
please input colnum
Please enter the number between 0 and 5:0
 1  0  0  0  0 
 0  0  0  0  0 
 0  0  0  0  0 
 0  0  0  0  0 
 0  0  0  0  0 
please input rownum
Please enter the number between 0 and 5:0
please input colnum
Please enter the number between 0 and 5:5
You input number is too big
Please enter the number between 0 and 5:3
 1  0  0  1  1 
 0  0  0  0  0 
 0  0  0  0  0 
 0  0  0  0  0 
 0  0  0  0  0 
please input rownum
Please enter the number between 0 and 5:4
please input colnum
Please enter the number between 0 and 5:4
 1  0  0  1  1 
 0  0  0  0  0 
 0  0  0  0  0 
 0  0  0  0  0 
 0  0  0  0  1 
please input rownum
Please enter the number between 0 and 5:
********************************************************************/


/*****************************6.2***********************************/
/*一个数各个约数（真约数）的和等于它本身的自然数叫做完全数
（Perfect number）。(例如：6 = 1 + 2 + 3)请找出1-1000以内的完全数。*/
#include <stdio.h>

int main(void)
{
	int i, j, sum;

	printf("Perfect number:");

	for (i=1; i<=1000; i++)
	{
		for (j=1,sum=0; j<=i/2+1; j++)
		{
			if (i%j == 0)
				sum += j;
		}
		if (sum == i)
			printf("%d, ", sum);
	}

	printf ("\n");

	return 0;
}
/******************************************************************
Perfect number:1, 6, 28, 496, 
*******************************************************************/


/*****************************6.3***********************************/
/*一个 n 位数 ( n≥3 ) 每个位上的数字的 n 次幂之和等于它本身的数叫做水仙花数。(例如：1^3 + 5^3 + 3^3 = 153)请找出 n = 3 的水仙花数。*/
#include <stdio.h>
//#include <math.h>

#define N 	3

int power(int x, int y)
{
	int i, result;

	result = 1;
	for (i=0; i<y; i++)
		result *= x;

	return result;
}

int main(void)
{
	int i, sum;

	for (i=100; i<1000; i++)
	{
		int result = i;
		sum = 0;
		while (result != 0)
		{
//			sum += (int)pow(result%10, N);
//gcc homeworks-6.c -lm ??
			sum += power(result%10, N);

			result /= 10;
		}

		if (sum == i)
			printf ("%d, ", i);
	}

	printf ("\n");

	return 0;
}
/******************************************************************
153, 370, 371, 407, 
*******************************************************************/
