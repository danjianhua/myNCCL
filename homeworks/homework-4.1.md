##code

#include <stdio.h>
#include <time.h>

int main(void)
{
	int iGuessNum = 0;
	int iInputNum = 0;
	
	srand((unsigned)time(NULL));
	iGuessNum = (int)rand()%1000;
	printf("rand num %d", iGuessNum);
	while (1)
	{
		printf("please input a num to guess:");
		scanf("%d", &iInputNum);
		if (iInputNum > iGuessNum)
		{
			printf("input number is bigger than guess number\n");
		}
		else if (iInputNum < iGuessNum)
		{
			printf("input number is little than guess number\n");
		}
		else 	
		{
			printf("congratulation! you are right\n");
			break;
		}
	}

	return 0;
}


##result:
please input a num to guess:500
input number is little than guess number
please input a num to guess:800
input number is little than guess number
please input a num to guess:900
input number is bigger than guess number
please input a num to guess:850
input number is bigger than guess number
please input a num to guess:810
input number is bigger than guess number
please input a num to guess:808
congratulation! you are right







