#include <stdio.h>

#define PRINTD(x) printf("<%s>line - %d" #x "= %d\n",__FUNCTION__,__LINE__, x)

int main(void)
{
	int i;

	for (i=0; i<10; i++)
	{
		PRINTD(i);
	}

	return 0;
}
