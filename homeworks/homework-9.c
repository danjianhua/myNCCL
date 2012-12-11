/*****************************9.1***********************************/
/*用户任意输入一个字符串，判断这个字符串是否为“回文”(回文即按正反顺序读都一样)。例如 “abcba” 就是回文。*/
#include <stdio.h>
#include <string.h>

#define MAX_COUNT   100

int main(void)
{
	char buf[MAX_COUNT];
	int len, i;

	printf("Please input string:");
	scanf("%s", buf);

	len = strlen(buf);
	
	for (i = 0; i < len / 2; i++)
	{
		if (buf[i] != buf[len - i - 1])
			break;
	}
	if (i == len/2)
		printf("YES\n");
	else 
		printf("NO\n");

	return 0;
}
/*******************************************************************
Please input string:abcbc
NO
liubin@liubin-virtual-machine:~/github/myNCCL/code/homework9$ ./a.out 
Please input string:abcba
YES
********************************************************************/

/*****************************9.2***********************************/
/*使用字符数组实现基于数字字符串的加减法。例如"123" + "45" = "168" , "456"-"13"="443"*/
#include <stdio.h>
#include <string.h>

#define MAX_NUM 10
#define SWAP(a, b)   { a = a + b;  b = a - b;  a = a - b; }

void reverse_str(char buf[]);

void add(char fir[], char sec[])
{
    char result[MAX_NUM] = {0};
    int i, counter = 0;
	int pos_fir, pos_sec;

    pos_fir = strlen(fir) - 1;
    pos_sec = strlen(sec) - 1;

	i = 0;
    while (pos_fir >=0 || pos_sec >= 0)
	{
		int tmp_fir_digit = pos_fir >= 0 ? fir[pos_fir]-'0' : 0;
		int tmp_sec_digit = pos_sec >= 0 ? sec[pos_sec]-'0' : 0;
        int tmp_digit = tmp_fir_digit + tmp_sec_digit + counter;
        
		//printf ("fir -- %d, sec --%d, sum -- %d\n", tmp_fir_digit, tmp_sec_digit, tmp_digit);
		counter = tmp_digit / 10;
    	result[i] += tmp_digit % 10 + '0';

		pos_fir--;
		pos_sec--;
		i++;
    }

	if (counter > 0)
	{
		result[i] = '1';
		result[i+1] = '\0';
	}
	else
    	result[i] = '\0';

	reverse_str(result);
    printf("%s + %s = %s\n", fir, sec, result);
}

void reverse_str(char buf[])
{
	int i;
    int len = strlen(buf);

    for (i = 0; i < len/2; i++)
        SWAP(buf[i], buf[len-i-1]);
}
int main(void)
{
    char fir_num[MAX_NUM];
    char sec_num[MAX_NUM];
    char symbol;

    printf("Please input a expression:");
    scanf("%s %c %s", fir_num, &symbol, sec_num);

    if (symbol == '+')
        add(fir_num, sec_num);
    else 
        printf("The symbol is error!\n");

    return 0;
}

/*******************************************************************
Please input a expression:5683 + 75 
5683 + 75 = 5758
********************************************************************/


/*****************************9.3***********************************/
/*编写一个去字符串多余空格的的程序，将连续的多个空格用一个空格代替。例如输入"abc___ab_a__c"，输出"abc ab a c"*/
#include <stdio.h>

#define MAX_LEN 50
#define YES     1
#define NO		0

int main(void)
{
	char input_str[MAX_LEN];
	char result[MAX_LEN];
	int existed_space, i, pos;

	printf("Pleas input a string:");
	gets(input_str);

	existed_space = NO;
	i = 0;
	pos = 0;

	while (input_str[i] != '\0')
	{
		if (existed_space && input_str[i] == ' ')
		{
			i++;
			continue ;
		}
		if (input_str[i] == ' ')
			existed_space = YES;
		else
			existed_space = NO;
		result[pos] = input_str[i];

		pos++;
		i++;
	}
	result[pos] = '\0';

	printf("result: %s\n", result);

	return 0;
}
/*******************************************************************
Pleas input a string:gsa   tgew sdf  erfs
result: gsa tgew sdf erfs

********************************************************************/
