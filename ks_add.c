#include "ks_base.h"

int add_stud(Student* slist, int count)//添加学生信息
{
	int s;
	/*s：要添加的学生信息数
	*/
	printf("|请输入你要添加的学生信息数：\n");
	scanf("%d", &s);
	for (int i = count; i < count + s; i++)
	{
		int p = i, x = 0;//将i的值保存到p；x：判断是否替换
		printf("|现在输入第%d名学生的信息：\n", i - count + 1);
		printf("|请输入该学生的学号：\n");
		scanf("%s", slist[i].xh);

		for (int j = 0; j < i; j++)
		{
			if (strcmp(slist[i].xh, slist[j].xh) == 0)
			{
				int an;
				printf("|该学生信息已存在，请问是否替换？\n");
				printf("|(如果替换，输入1；否则，输入2)\n");
				scanf("%d", &an);
				p--;
				if (an == 1)
				{
					
					i = j;
					printf("|现在输入该学生的新信息：\n");
					break;
				}
				else {
					i--;
					x = 1;
					break;
				}
			}
		}
		if (x == 1) continue;
		printf("|请输入该学生的姓名：\n");
		scanf("%s", slist[i].xm);

		printf("|请输入该学生的性别（男|女）：\n");
		scanf("%s", slist[i].xb);

		printf("|请输入该学生的年龄：\n");
		scanf("%d", &slist[i].nl);
		i = p;
	}
	return (count + s);
}

int add_course(Course* clist, int count)
{
	int s;
	printf("|请输入你要添加的课程信息数：\n");
	scanf("%d", &s);
	for (int i = count; i < count + s; i++)
	{
		int p = i, x = 0;
		printf("|现在输入第%d个课程的信息：\n", i - count + 1);
		printf("|请输入该课程的课号：\n");
		scanf("%s", clist[i].kh);

		for (int j = 0; j < i; j++)
		{
			if (strcmp(clist[i].kh, clist[j].kh) == 0)
			{
				int an;
				printf("|该课程信息已存在，请问是否替换？\n");
				printf("|(如果替换，输入1；否则，输入2)\n");
				scanf("%d", &an);
				p--;
				if (an == 1)
				{
					
					i = j;
					printf("|现在输入该课程的新信息：\n");
					break;
				}
				else {
					i--;
					x = 1;
					break;
				}
			}
		}
		if (x == 1) continue;
		printf("|请输入该课程的课名：\n");
		scanf("%s", clist[i].km);

		printf("|请输入该课程的学分：\n");
		scanf("%f", &clist[i].xf);
		i = p;
	}
	return (count + s);

}

int add_select(Select* sclist, int count)
{
	int s, w = 0;//w：重复的选课信息数
	printf("|请输入你要添加的选课信息数：\n");
	scanf("%d", &s);
	for (int i = count; i < count + s; i++)
	{
		int x = 0;//判断输入的学号是否存在
		char xh[10];
		printf("|现在输入第%d个选课的信息：\n", i - count + 1);
		printf("|请输入该选课信息的学号：\n");
		scanf("%s", xh);
		printf("|以下是学号%s的选课信息：\n", xh);
		for (int t = 0; t < i; t++)
		{
			if (strcmp(xh, sclist[t].xh) == 0)
			{
				x = 1;
				printf("|课号：%s\t成绩：%.2f\n", sclist[t].kh, sclist[t].cj);
			}
		}
		if (x == 0)
		{
			printf("|系统内未找到该学号学生的选课记录，\n\
请确认是否输入错误\n");
			printf("--------------------------------\n");
			i--;
		}
		else
		{
			int t = 0;//判断是否替换
			int p = i;
			strcpy(sclist[i].xh, xh);
			printf("|下面请输入你要添加的选课信息的课号：\n");
			scanf("%s", sclist[i].kh);

			for (int j = 0; j < i; j++)
			{
				if ((strcmp(sclist[i].kh, sclist[j].kh) == 0) && \
					(strcmp(sclist[i].xh, sclist[j].xh) == 0))
				{
					int an;
					printf("|该课号的选课信息已存在，请问是否替换成绩？\n");
					printf("|(如果替换，输入1；否则，输入2)\n");
					scanf("%d", &an);
					if (an == 1)
					{
						w++;
						p--;
						i = j;	
						break;
					}
					else {
						t = 1; i--; break;
					}
				}
			}
			if (t == 1) continue;
			printf("|现在输入该选课信息的成绩：\n");
			scanf("%f", &sclist[i].cj);
			i = p;
		}
	}
	return (count + s - w);
}