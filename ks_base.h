#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//����ṹ�����
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
	Course kc[10];//��ѧ����ѡ�Ŀ�Ŀ
	float cj[20];
	float zpj;
	float zxf;
	int kcshu;//Ϊ��ѧ����ѡ������
}Score;
