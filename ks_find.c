#include "ks_base.h"

void query_stud(Student* slist, int count)//查询学生信息
{
	int an, t = 0;
	/*an：取1或2，确定查找方式
	t：判断记录是否存在*/
	int i;
	char xh[10], xm[20];//输入数据暂时存放处
	printf("|请确定你需要查找的是学生学号还是姓名：\n");
	printf("|（如果是学号，输入1，是姓名，输入2）\n");
	scanf("%d", &an);
	if (an == 1)
	{
		printf("|请输入你要查找的学号：\n");
		scanf("%s", xh);
		for (i = 0; i < count; i++)
		{
			if (strcmp(xh, slist[i].xh) == 0)
			{
				t = 1; break;
			}
		}
		if (t == 0) printf("|未找到该学号学生\n");
		else
			printf("|学号：%s\n|姓名：%s\n|性别：%s\n|年龄\
：%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
	}
	if (an == 2)
	{
		printf("|请输入你要查找的姓名：\n");
		scanf("%s", xm);
		for (i = 0; i < count; i++)
		{
			if (strcmp(xm, slist[i].xm) == 0)
			{
				t = 1; break;
			}
		}
		if (t == 0) printf("|未找到该姓名学生\n");
		else
			printf("|学号：%s\n|姓名：%s\n|性别：%s\n|年龄\
：%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
	}
}

void query_course(Course* clist, int count)//查询课程信息
{
	int an, t = 0;
	int i;
	char kh[10], km[25];
	printf("|请确定你需要查找的是课程课号还是课名：\n");
	printf("|（如果是课号，输入1，是课名，输入2）\n");
	scanf("%d", &an);
	if (an == 1)
	{
		printf("|请输入你要查找的课号：\n");
		scanf("%s", kh);
		for (i = 0; i < count; i++)
		{
			if (strcmp(kh, clist[i].kh) == 0)
			{
				t = 1; break;
			}
		}
		if (t == 0) printf("|未找到该课号课程\n");
		else
			printf("|课号：%s\n|课名：%s\n|学分：%.2f\n",clist[i].kh,clist[i].km,clist[i].xf);
	}
	if (an == 2)
	{
		printf("|请输入你要查找的课名：\n");
		scanf("%s", km);
		for (i = 0; i < count; i++)
		{
			if (strcmp(km, clist[i].km) == 0)
			{
				t = 1; break;
			}
		}
		if (t == 0) printf("|未找到该课名课程\n");
		else
			printf("|课号：%s\n|课名：%s\n|学分：%.2f\n", clist[i].kh, clist[i].km, clist[i].xf);
	}
}

void query_cjlist(Score* cjlist, Student* slist, int count)//查询成绩信息
{
	int an, t = 0;
	int i;
	char xh[10], xm[20];
	printf("|请输入你要查询的学生的学号或姓名：\n");
	printf("|（如果是学号，输入1，是姓名，输入2）\n");
	scanf("%d", &an);

	if (an == 1)
	{
		printf("|请输入你要查找的学号：\n");
		scanf("%s", xh);

		for (i = 0; i < count; i++)
		{
			if (strcmp(xh, slist[i].xh) == 0)
			{
				t = 1;
				break;
			}
		}

		if (t == 0) printf("|未找到该学号学生\n");

		else
		{
			printf("|学号：%s\n|姓名：%s\n", cjlist[i].xh, cjlist[i].xm);
			printf("|性别：%s\n|年龄：%d\n", slist[i].xb, slist[i].nl);
			for (int p = 0; p < cjlist[i].kcshu; p++)
			{
				printf("|课程名：%s\t成绩：%.2f\n", cjlist[i].kc[p].km, cjlist[i].cj[p]);
			}
			printf("|加权平均分：%.2f\t总学分：%.2f\n", cjlist[i].zpj, cjlist[i].zxf);
			printf("--------------------------------------\n");
		}
	}

	if (an == 2)
	{
		printf("|请输入你要查找的姓名：\n");
		scanf("%s", xm);

		for (i = 0; i < count; i++)
		{
			if (strcmp(xm, slist[i].xm) == 0)
			{
				t = 1;
				i--;
				break;
			}
		}

		if (t == 0) printf("|未找到该姓名学生\n");

		else
		{
			printf("|学号：%s\n|姓名：%s\n", cjlist[i].xh, cjlist[i].xm);
			printf("|性别：%s\n|年龄：%d\n", slist[i].xb, slist[i].nl);
			for (int p = 0; p < cjlist[i].kcshu; p++)
			{
				printf("|课程名：%s\t成绩：%.2f\n", cjlist[i].kc[p].km, cjlist[i].cj[p]);
			}
			printf("|加权平均分：%.2f\t总学分：%.2f\n", cjlist[i].zpj, cjlist[i].zxf);
			printf("--------------------------------------\n");
		}

	}
}