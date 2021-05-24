#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//定义结构体变量
typedef struct
{
	char xh[10];
	char xm[10];
	char xb[3];
	int nl;
}Student;

typedef struct
{
	char kh[10];
	char km[25];
	float xf;
}Course;

typedef struct
{
	char xh[10];
	char kh[10];
	float cj;
}Select;

typedef struct
{
	char xh[10];
	char xm[20];
	Course kc[10];//该学生的选的科目
	float cj[20];
	float zpj;
	float zxf;
	int kcshu;//为该学生的选课数量
}Score;
