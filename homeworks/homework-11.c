/*****************************11.1***********************************/
/*给定一个结构体 point_t 的数组，求出这一组点中，离原点距离最远的那个点。*/
#include <stdio.h>
#include <math.h>

#define POINT_NUM  10

struct point
{
	int x;
	int y;
};

typedef struct point point_t;

double calc_distance(point_t p1, point_t p2)
{
	int dx = p1.x - p2.x;
	int dy = p1.y - p2.y;

	return sqrt(dx * dx + dy * dy);
}

int main(void)
{
	double max_distance = 0;
	int i;
	point_t max_dp;
	point_t org_p = {0, 0};
	point_t point[POINT_NUM] = 
	{
		{3, 5},
		{6 ,3},
		{2, 8},
		{4, 2},
		{8, 1},
		{6, 2},
		{7, 3},
		{7, 5},
		{6, 4},
		{5, 5}
	};

	puts("All point:");
	for (i = 0; i < POINT_NUM; i++)
		printf("(%d, %d), ", point[i].x, point[i].y);
	puts("");

	for (i = 0; i < POINT_NUM; i++)
	{
		int tmp_d = calc_distance(point[i], org_p);
		if (max_distance < tmp_d)
		{
			max_distance = tmp_d;
			max_dp = point[i];
		}
	}

	printf("The point is (%d, %d) the farthest from the origin\n", max_dp.x, max_dp.y);

	return 0;
}
/*******************************************************************
All point:
(3, 5), (6, 3), (2, 8), (4, 2), (8, 1), (6, 2), (7, 3), (7, 5), (6, 4), (5, 5), 
The point is (2, 8) the farthest from the origin
********************************************************************/


/*****************************11.2***********************************/
/*求出上面这一组点中，距离最远的2个点以及它们之间的距离。*/
#include <stdio.h>
#include <math.h>

#define POINT_NUM  10

struct point
{
	int x;
	int y;
};

typedef struct point point_t;

double calc_distance(point_t p1, point_t p2)
{
	int dx = p1.x - p2.x;
	int dy = p1.y - p2.y;

	return sqrt(dx * dx + dy * dy);
}

int main(void)
{
	double max_distance = 0;
	int i, j;
	point_t max_dp1, max_dp2;
	point_t point[POINT_NUM] = 
	{
		{3, 5},
		{6 ,3},
		{2, 8},
		{4, 2},
		{8, 1},
		{6, 2},
		{7, 3},
		{7, 5},
		{6, 4},
		{5, 5}
	};

	puts("All point:");
	for (i = 0; i < POINT_NUM; i++)
		printf("(%d, %d), ", point[i].x, point[i].y);
	puts("");

	for (i = 0; i < POINT_NUM-1; i++)
	{
		for (j = i+1; j < POINT_NUM; j++)
		{
			int tmp_d = calc_distance(point[i], point[j]);
			if (max_distance < tmp_d)
			{
				max_distance = tmp_d;
				max_dp1 = point[i];
				max_dp2 = point[j];
			}
		}
	}

	printf("The farthest distance is between (%d, %d) and (%d, %d)\n", max_dp1.x, max_dp1.y, max_dp2.x, max_dp2.y);
	
		return 0;
}

/*******************************************************************
All point:
(3, 5), (6, 3), (2, 8), (4, 2), (8, 1), (6, 2), (7, 3), (7, 5), (6, 4), (5, 5), 
The farthest distance is between (2, 8) and (8, 1)
********************************************************************/


/*****************************11.3***********************************/
/*有5个学生，每个学生有3门课的成绩，用户输入以上数据，包括学号，姓名，三门课成绩(浮点数)，请计算出每位学生的总分和平均成绩，并支持用户通过学号和姓名进行查询。*/
#include <stdio.h>
#include <string.h>

#define STUDENT_NUM  5

typedef struct student
{
	char no[11];
	char name[10];
	float eng_score;
	float china_score;
	float math_score;
	float sum_score;
	float avg_score;
}student_t;


student_t stu[STUDENT_NUM] = 
{
	{"2009011142", "jack", 67.8, 98.5, 34, 364, 78},
	{"2009011143", "cheng", 67.8, 98.5, 34, 364, 78},
	{"2009011144", "lucy", 67.8, 98.5, 34, 364, 78},
	{"2009011145", "lily", 67.8, 98.5, 34, 364, 78},
	{"2009011146", "mali", 67.8, 98.5, 34, 364, 78}
};

void print_stu(student_t stu)
{
	printf("%11s|%10s|%7.1f|%7.1f|%7.1f|%7.1f|%7.1f|\n", stu.no, stu.name, stu.eng_score, stu.china_score, stu.math_score, stu.sum_score, stu.avg_score);
}

void print_head()
{
	printf("-----NO----|---NAME---|ENGLISH|-CHINA-|-MATH--|--SUM--|---AVG-|\n");
}

void print_all_stu()
{
	int i;
	print_head();
	for (i=0; i < STUDENT_NUM; i++)
		print_stu(stu[i]);
}

void select_stu()
{
	char tmp_str[11];
	int i;

	printf ("Please input student no or student name to find the student:\n");
	gets(tmp_str);

	for (i = 0; i < STUDENT_NUM; i++)
	{
		if (strcmp(tmp_str, stu[i].no) == 0
				|| strcmp(tmp_str, stu[i].name) == 0)
		{
			print_head();
			print_stu(stu[i]);
			break;
		}
	}
	
	if (i == STUDENT_NUM)
		printf ("Can not find the student\n");
}

void input_all_stu()
{
	int i;

	for (i = 0; i < STUDENT_NUM; i++)
	{
		printf("Please input %dth student no:", i);
		gets(stu[i].no);
		printf("please input %dth student name:", i);
		gets(stu[i].name);
		printf("Please input %dth english china and math score:", i);
		scanf("%f %f %f", &stu[i].eng_score, &stu[i].china_score, &stu[i].math_score);
		stu[i].sum_score = stu[i].eng_score + stu[i].china_score + stu[i].math_score;
		stu[i].avg_score = stu[i].sum_score / 3;
		
		//clear buf
		setbuf(stdin, NULL);
	}
}

void print_menu()
{
	printf ("*******MENU*******\n");
	printf ("* 1: Input student\n");
	printf ("* 2: print student\n");
	printf ("* 3: find  student\n");
}

int main(void)
{
	int select_num;
	
	while (1)
	{
		print_menu();
		printf("Please select:");
		scanf("%d", &select_num);
		setbuf(stdin, NULL);

		switch (select_num)
		{
			case 1:			//input student
				input_all_stu();
				break;
			case 2:			//print student
				print_all_stu();
				break;
			case 3:			//find student
				select_stu();
				break;
			default:
				printf("you input digit is wrong!\n");
				break;
		}
	}

	return 0;
}

/*******************************************************************

********************************************************************/
