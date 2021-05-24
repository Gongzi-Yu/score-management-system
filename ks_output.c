#include "ks_base.h"


void write_to_file_1(Student* slist, Course* clist, Select* sclist, int s, int c, int sc)
/*输出学生信息、课程信息、选课信息*/
{
	FILE* st, * co, * se;
	/*
	st：指向学生信息文件
	co：指向课程信息文件
	se：指向选课信息文件
	*/
	char studname[20], courname[20], selname[20];

	printf("|请输入学生信息表的文件名：\n");
	scanf("%s", studname);
	st = fopen(studname, "w");
	if (st == NULL)
	{
		printf("|%s文件无法打开\n", studname);
		exit(1);
	}
	for (int i = 0; i < s; i++)
	{
		fprintf(st, "|学号：%s\t姓名：%s\t性别：%s\t年龄\
：%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
	}

	printf("|请输入课表信息表的文件名：\n");
	scanf("%s", courname);
	co = fopen(courname, "w");
	if (co == NULL)
	{
		printf("|%s文件无法打开\n", courname);
		exit(1);
	}
	for (int i = 0; i < c; i++)
	{
		fprintf(co, "|课号：%s\t课名：%s\t学分：%.2f\n", clist[i].kh, clist[i].km, clist[i].xf);
	}

	printf("|请输入选课信息表的文件名：\n");
	scanf("%s", selname);
	se = fopen(selname, "w");
	if (se == NULL)
	{
		printf("|%s文件无法打开\n", selname);
		exit(1);
	}
	for (int i = 0; i < sc; i++)
	{
		fprintf(se, "|学号：%s\t课号：%s\t成绩：%.2f\n", sclist[i].kh, sclist[i].xh, sclist[i].cj);
	}
	printf("|全部导出完成\n");
	fclose(st);
	fclose(co);
	fclose(se);
}

void write_to_file_2(Student* slist, Score* cjlist, int s)
{
	FILE* sco;
	char sconame[20];
	printf("|请输入成绩单的文件名：\n");
	scanf("%s", sconame);
	sco = fopen(sconame, "w");
	if (sco == NULL)
	{
		printf("|%s文件无法打开\n", sconame);
		exit(1);
	}
	for (int i = 0; i < s; i++)
	{
		fprintf(sco, "|学号：%s\t姓名：%s\n", cjlist[i].xh, cjlist[i].xm);
		fprintf(sco, "|性别：%s\t年龄：%d\n", slist[i].xb, slist[i].nl);
		for (int t = 0; t < cjlist[i].kcshu; t++)
		{
			fprintf(sco, "|课号：%s\t课名：%s\t成绩\
：%.2f\n", cjlist[i].kc[t].kh, cjlist[i].kc[t].km, cjlist[i].cj[t]);
			fprintf(sco, "-------------------------------------------------\n");
		}
		fprintf(sco, "|平均分：%.2f\t总学分：%.2f\n", cjlist[i].zpj, cjlist[i].zxf);
		fprintf(sco, "----------------------------------------------------\
---------------------------\n");
	}
	printf("|导出完成\n");
	fclose(sco);
}