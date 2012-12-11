/*****************************7.1***********************************/
/*5*5 的棋盘，用户输入两个位置坐标，统计这两个位置之间有多少个子？*/
#include <stdio.h>

#define ROW_AMOUNT	5
#define COL_AMOUNT    	5

int main(void)
{
	int fir_row, fir_col, sec_row, sec_col;
	int i, j, counter, count_status;

	printf ("Please input two location\n");
	printf ("first location (rownum, colnum):");
	scanf ("%d, %d", &fir_row, &fir_col);
	printf ("second location (rownum, colnum):");
	scanf ("%d, %d", &sec_row, &sec_col);


	counter = 0;
	count_status = 0;

	for (i = 0; i < ROW_AMOUNT; i++)
	{
		if (i < fir_row)
			continue;

		for (j = 0; j < COL_AMOUNT; j++)
		{
			if (i == sec_row && j == sec_col)
			{
				count_status = -1;
				break;
			}

			if (count_status == 1)
				counter++;

			if (i == fir_row && j == fir_col)
				count_status = 1;
		}
		if (count_status == -1)
			break;
	}
	
	printf ("The number of pieces is %d between first location and second location\n", counter);

	return 0;
}
/*******************************************************************
Please input two location
first location (rownum, colnum):1,1
second location (rownum, colnum):2,3
The number of pieces is 6 between first location and second location
********************************************************************/

/*****************************7.2***********************************/
/*在上图所示的棋盘中，用户任意输入一个位置，放置国际象棋中的皇后，请输出所有皇后能够吃到的位置*/
#include <stdio.h>
#include <stdlib.h>

#define COL_AMOUNT	5
#define ROW_AMOUNT	5

int main(void)
{
	int i, j, queen_row, queen_col;

	printf ("Please input the Queen location (rownum, colnum):");
	scanf ("%d, %d", &queen_row, &queen_col);

	for (i = 0; i < ROW_AMOUNT; i++)
	{
		for (j = 0; j < COL_AMOUNT; j++)
		{
			if ((i == queen_row || j == queen_col || abs(i - queen_row) == abs(j - queen_col))
				&& (i != queen_row || j != queen_col))
				printf (" 1 ");
			else
				printf (" 0 ");
		}
		printf ("\n");
	}

	return 0;
}

/*******************************************************************
Please input the Queen location (rownum, colnum):3,2
 0  0  1  0  0 
 1  0  1  0  1 
 0  1  1  1  0 
 1  1  0  1  1 
 0  1  1  1  0 
********************************************************************/


/*****************************7.3***********************************/
/*请打印杨辉三角形的前10行。*/
#include <stdio.h>

#define PRINT_ROW  10

int main(void)
{
	unsigned int a, b;
	int i, j, k;

	for (i = 0; i < PRINT_ROW; i++)
	{
		int l;
		for (l = 0; l < PRINT_ROW-i-1; l++)
			printf("   ");
		for (j = 0; j < i + 1; j++)
		{
			a = b = 1;
			if (j >= 1)
			{
				for (k = i; k > (i-j); k--)
					a *= k;
				for (k = 1; k <= j; k++)
					b *= k;
			}
		//	printf ("A:%d B:%d\n", a, b);
			printf("  %d  ", (int)a/b);
		}

		printf("\n");
	}

	return 0;
}

/*******************************************************************
                             1  
                          1    1  
                       1    2    1  
                    1    3    3    1  
                 1    4    6    4    1  
              1    5    10    10    5    1  
           1    6    15    20    15    6    1  
        1    7    21    35    35    21    7    1  
     1    8    28    56    70    56    28    8    1  
  1    9    36    84    126    126    84    36    9    1  

********************************************************************/


/*****************************7.4***********************************/
/*猜数游戏：电脑随机产生2位数，然后用户输入2位数，电脑告诉你是?A?B*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int guess_num;
	int input_num;
	int a_counter, b_counter;
	int i, digit_num = 2;
	
	srand(time(NULL));
	guess_num = rand() % (int)pow(10, digit_num);
	//printf("%d\n", guess_num);

	while (1)
	{
		int tmp_guess_num = guess_num;

		a_counter = 0;
		b_counter = 0;
		printf("Please input %d-digit number:", digit_num);
		scanf("%d", &input_num);

		for (i = 0; i < digit_num; i++)
		{
			int guess_digit = tmp_guess_num % 10;
			int j;
			int tmp_input_num = input_num;

			for (j = 0; j < digit_num; j++)
			{
				int input_digit = tmp_input_num % 10;
				//printf ("test %d, %d\n", guess_digit, input_digit);
				if (guess_digit == input_digit && i == j)
					a_counter++;
				else if (guess_digit == input_digit && i != j)
					b_counter++;

				tmp_input_num /= 10;
			}

			tmp_guess_num /= 10;
		}

		if (a_counter == digit_num)
		{
			printf ("congratulation! you are right\n");
			break;
		}
		else 
			printf ("A:%d, B:%d\n", a_counter, b_counter);
	}

	return 0;
}

/*******************************************************************
Please input 2-digit number:45
A:0, B:1
Please input 2-digit number:57
A:1, B:0
Please input 2-digit number:56
congratulation! you are right
********************************************************************/


