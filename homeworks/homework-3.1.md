##code

	#include <stdio.h>

	int main(void)
	{
		int iCounter;

		iCounter = 10;
		while (iCounter >= 0)
		{
			printf("counter = %d\n", iCounter);
			iCounter--;
		}

		return 0;
	}


##result:
	counter = 10
	counter = 9
	counter = 8
	counter = 7
	counter = 6
	counter = 5
	counter = 4
	counter = 3
	counter = 2
	counter = 1
	counter = 0


