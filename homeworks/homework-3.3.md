##code:

	#include <stdio.h>

	int main(void)
	{
		int iNum = 0;
	
		do{
			printf("please input a positive number:\n");
			scanf("%d", &iNum);
		}while(iNum < 0);

		while (iNum != 0)
		{
			printf("%d, ", iNum % 10);
			iNum /= 10;
		}

		printf("\n");

		return 0;
	}

##result
	please input a positive number:
	12345
	5, 4, 3, 2, 1, 


