#include <stdio.h>
#include <time.h>

int main(void)
{
	int i;
	srand((unsigned)time(NULL));

	for (i=0; i<10; i++)
	{
		printf("%d\n", rand());
	}

	return 0;
}
