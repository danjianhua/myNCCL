/****************************5.1***********************************/
/*输入5个数，计算平均数,并打印*/
#include <stdio.h>

#define INPUT_AMOUNT   5

int main(void)
{
	int   sum, i, input_num;

	printf ("Please input five number:\n");
	for (i=0,sum = 0; i<INPUT_AMOUNT; i++)
	{
		printf ("%d number:", i+1);
		scanf("%d", &input_num);

		sum += input_num;
	}

	printf("The average number = %f\n", sum*1.0/INPUT_AMOUNT);
	
	return 0;
}
/*****************************************************************
Please input five number:
1 number:12
2 number:45
3 number:32
4 number:45
5 number:67
The average number = 40.200000
******************************************************************/


/****************************5.2**********************************/
/*输入5个数，找出最大的数，并打印*/
#include <stdio.h>

#define INPUT_AMOUNT 5

int main(void)
{
	int i;
	int input_num;
	int max_num  = 0;

	printf("Please input five number:\n");
	for (i=0; i<INPUT_AMOUNT; i++)
	{
		printf("%d number:", i+1);
		scanf("%d", &input_num);

		max_num = max_num>input_num ? max_num : input_num;
	}

	printf ("The max number = %d\n", max_num);

	return 0;
}
/*****************************************************************
Please input five number:
1 number:4
2 number:7
3 number:4
4 number:9
5 number:7
The max number = 9
******************************************************************/


/****************************5.3**********************************/
/*已知11月1日星期四，打印出11月份的月历*/
#include <stdio.h>

int main(void)
{
	int first_day = 4;
	int day_amount = 30;
	int i;

	printf (" 日  一  二  三  四  五  六 ");

	for (i=0; i<day_amount+first_day; i++)
	{
		if (i%7 == 0)
			printf("\n");

		if (i < first_day)
			printf("    ");
		else 
			printf(" %2d ", i-first_day+1);
	}

	printf ("\n");

	return 0;
}
/*****************************************************************
 日  一  二  三  四  五  六 
                  1   2   3 
  4   5   6   7   8   9  10 
 11  12  13  14  15  16  17 
 18  19  20  21  22  23  24 
 25  26  27  28  29  30 
******************************************************************/


