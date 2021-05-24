#include "ks_base.h"


int instud(Student* slist)//导入学生信息
{
	int i = 0;
	FILE* fp;
	char filename[20] = { 0 };
	printf("|请输入保存学生信息的文件的文件名: \n");
	if (scanf("%s", filename) != 0)
	{
		if ((fp = fopen(filename, "rb")) == NULL)
		{
			printf("|未找到该文件，已使用默认文件\n");
			fp = fopen("_stud.txt", "rb");
		}
			
		//!feof(fp)
		while (fscanf(fp, "%s %s %s %d", slist[i].xh, \
			slist[i].xm, slist[i].xb, &slist[i].nl) != EOF)
		{
			i++;
		}
		fclose(fp);
	}
	return i;
}

int incourse(Course* clist)//导入课程信息
{
	FILE* fp;
	char filename[20];
	int i = 0;

	printf("|请输入保存课程信息的文件的文件名: \n");
	if (scanf("%s", filename) != 0)
	{
		if ((fp = fopen(filename, "rb")) == NULL)
		{
			printf("|未找到该文件，已使用默认文件\n");
			fp = fopen("_course.txt", "rb");
		}
		while (fscanf(fp, "%s %s %f\n", clist[i].kh, clist[i].km, &clist[i].xf) != EOF)
		{
			i++;
		}
		fclose(fp);
	}
	return i;
}

int insclist(Select* sclist)//导入选课信息
{
	FILE* fp;
	char filename[20];
	int i = 0;

	printf("|请输入保存选课信息的文件的文件名: \n");
	if (scanf("%s", filename) != 0)
	{
		if ((fp = fopen(filename, "rb")) == NULL)
		{
			printf("|未找到该文件，已使用默认文件\n");
			fp = fopen("_select.txt", "rb");
		}
		while (fscanf(fp, "%s %s %f\n", sclist[i].xh, sclist[i].kh, &sclist[i].cj) != EOF)
		{
			i++;
		}
		fclose(fp);

	}
	return i;
}

void create_cjlist(Student* slist, Select* sclist, Course* clist, \
	Score* cjlist, int count,int sccount)
/*创建成绩单*/
{//count为学生信息数、sccount为选课信息数
	int s = 0, sc, c, cj, t;
	/*
	s为循环学生信息数；
	c为循环课程信息数；
	sc为循环选课信息数；
	cj为循环成绩信息数；
	t为该学生的选课数目。
	*/

	for (cj = 0; s < count; cj++)
	{
		strcpy(cjlist[cj].xm, slist[s].xm);
		strcpy(cjlist[cj].xh, slist[s].xh);

		
		cjlist[cj].zpj = 0;
		cjlist[cj].zxf = 0;
		t = 0;
		for (sc = 0; sc < sccount; sc++)
		{

			if (strcmp(sclist[sc].xh, cjlist[cj].xh) == 0)
			{
				cjlist[cj].cj[t] = sclist[sc].cj;
				
				for (c = 0; strcmp(clist[c].kh, sclist[sc].kh) != 0; c++);

				strcpy(cjlist[cj].kc[t].kh, clist[c].kh);
				strcpy(cjlist[cj].kc[t].km, clist[c].km);
				cjlist[cj].kc[t++].xf = clist[c].xf;

				cjlist[cj].zxf += clist[c].xf;

				cjlist[cj].zpj += sclist[sc].cj * clist[c].xf;

			}
		}
		cjlist[cj].kcshu = t;

		cjlist[cj].zpj /= cjlist[cj].zxf;
		printf("|已打印 %d 份成绩单\r", ++s);
	}
}
