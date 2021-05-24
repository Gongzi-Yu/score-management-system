#include "ks_base.h"

void disp_stud(Student* slist, int count)//显示学生信息
{
	int i = 0;
	while ((getchar() != EOF) && (i < count))
	{
		do
		{
			printf("|学号：%s\t姓名：%s\t性别：%s\t年龄\
：%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
		} while ((++i % 10 != 0) && (i < count));
		printf("|按回车键以继续");

	}
}

void disp_course(Course* clist, int count)//显示课程信息
{
	int i = 0;
	while ((getchar() != EOF) && (i < count))
	{
		do
		{
			printf("|课号：%s\t课程名：%s\t学分\
：%.2f\n", clist[i].kh, clist[i].km, clist[i].xf);
		} while ((++i % 10 != 0) && (i < count));
		printf("|按回车键以继续");

	}
}

void disp_cjlist(Score* cjlist, int count)//显示成绩单
{
	int i = 0;
	while ((getchar() != EOF) && (i < count))
	{
		do
		{
			printf("|学号：%s\n|姓名：%s\n", cjlist[i].xh, cjlist[i].xm);
			for (int t = 0; t < cjlist[i].kcshu; t++)
			{
				printf("|课程名：%s\t成绩：%.2f\n", cjlist[i].kc[t].km, cjlist[i].cj[t]);
			}
			printf("|加权平均分：%.2f\t总学分：%.2f\n", cjlist[i].zpj, cjlist[i].zxf);
			printf("--------------------------------------\n");
		} while ((++i % 10 != 0) && (i < count));
		printf("|按回车键以继续");
	}
}

void sort_slist(Student* slist, int count)//对学生信息进行排序
{
	int i, j, t;
	char s[20];
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (strcmp(slist[j].xh, slist[j + 1].xh) > 0)
			{
				strcpy(s, slist[j].xh);
				strcpy(slist[j].xh, slist[j + 1].xh);
				strcpy(slist[j + 1].xh, s);

				strcpy(s, slist[j].xm);
				strcpy(slist[j].xm, slist[j + 1].xm);
				strcpy(slist[j + 1].xm, s);

				strcpy(s, slist[j].xb);
				strcpy(slist[j].xb, slist[j + 1].xb);
				strcpy(slist[j + 1].xb, s);

				t = slist[j].nl;
				slist[j].nl = slist[j + 1].nl;
				slist[j + 1].nl = t;
			}

		}
	}
}

void sort_clist(Course* clist, int count)//对课程信息进行排序
{
	int i, j;
	float t;
	char s[25];
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (strcmp(clist[j].kh, clist[j + 1].kh) > 0)
			{
				strcpy(s, clist[j].kh);
				strcpy(clist[j].kh, clist[j + 1].kh);
				strcpy(clist[j + 1].kh, s);

				strcpy(s, clist[j].km);
				strcpy(clist[j].km, clist[j + 1].km);
				strcpy(clist[j + 1].km, s);

				t = clist[j].xf;
				clist[j].xf = clist[j + 1].xf;
				clist[j + 1].xf = t;
			}

		}
	}
}
