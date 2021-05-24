#include "ks_base.h"


int delete_stud(Student* slist, int count)//删除学生信息
{
	int an;//判断删除信息的方式
	int i, j = 0;
	char xh[10], xm[20];//输入信息临时存放处
	printf("|请问你是根据学号还是姓名来删除信息的？\n");
	printf("|(如果是学号，请输入1；如果是姓名，请输入2)\n");
	scanf("%d", &an);
	if (an == 1)
	{
		printf("|请输入你要删除的学号：\n");
		scanf("%s", xh);
		for (i = 0, j = 0; i < count; i++)
		{
			if (strcmp(xh, slist[i].xh) != 0)
			{
				strcpy(slist[j].xh, slist[i].xh);
				strcpy(slist[j].xm, slist[i].xm);
				strcpy(slist[j].xb, slist[i].xb);
				slist[j].nl = slist[i].nl;
				j++;
			}
		}
		printf("|已删除成功\n");
	}
	if (an == 2)
	{
		printf("|请输入你要删除的姓名：\n");
		scanf("%s", xm);
		for (i = 0, j = 0; i < count; i++)
		{
			if (strcmp(xm, slist[i].xm) != 0)
			{
				strcpy(slist[j].xh, slist[i].xh);
				strcpy(slist[j].xm, slist[i].xm);
				strcpy(slist[j].xb, slist[i].xb);
				slist[j].nl = slist[i].nl;
				j++;
			}
		}
		printf("|已删除成功\n");
	}
	return j;
}

int delete_course(Course* clist, int count)//删除课程信息
{
	int an;
	int i, j = 0;
	char kh[10], km[25];
	printf("|请问你是根据课号还是课名来删除信息的？\n");
	printf("|(如果是课号，请输入1；如果是课名，请输入2)\n");
	scanf("%d", &an);
	if (an == 1)
	{
		printf("|请输入你要删除的课号：\n");
		scanf("%s", kh);
		for (i = 0, j = 0; i < count; i++)
		{
			if (strcmp(kh, clist[i].kh) != 0)
			{
				strcpy(clist[j].kh, clist[i].kh);
				strcpy(clist[j].km, clist[i].km);
				clist[j].xf = clist[i].xf;
				j++;
			}
		}
		printf("|已删除成功\n");
	}
	if (an == 2)
	{
		printf("|请输入你要删除的课名：\n");
		scanf("%s", km);
		for (i = 0, j = 0; i < count; i++)
		{
			if (strcmp(km, clist[i].km) != 0)
			{
				strcpy(clist[j].kh, clist[i].kh);
				strcpy(clist[j].km, clist[i].km);
				clist[j].xf = clist[i].xf;
				j++;
			}
		}
		printf("|已删除成功\n");
	}
	return j;
}

int delete_select(Select* sclist, int count)//删除选课信息
{
	int i, j = 0;
	int t = 0;
	char xh[10], kh[10];
	printf("|请输入你要删除的选课记录的学生的学号：\n");
	scanf("%s", xh);
	printf("|以下是学号%s的选课信息：\n", xh);
	for (; t < count; t++)
	{
		if (strcmp(xh, sclist[t].xh) == 0)
			printf("|课号：%s\t成绩：%.2f\n", sclist[t].kh, sclist[t].cj);
	}
	printf("|请输入你要删除的选课记录的课号：\n");
	scanf("%s", kh);
	for (i = 0, j = 0; i < count; i++)
	{
		if ((strcmp(xh, sclist[i].xh) != 0) || (strcmp(kh, sclist[i].kh) != 0))
		{
			strcpy(sclist[j].xh, sclist[i].xh);
			strcpy(sclist[j].kh, sclist[i].kh);
			sclist[j].cj = sclist[i].cj;
			j++;
		}
	}
	printf("|已删除完成\n");
	return j;
}