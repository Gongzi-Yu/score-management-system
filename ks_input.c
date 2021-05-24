#include "ks_base.h"


int instud(Student* slist)//����ѧ����Ϣ
{
	int i = 0;
	FILE* fp;
	char filename[20] = { 0 };
	printf("|�����뱣��ѧ����Ϣ���ļ����ļ���: \n");
	if (scanf("%s", filename) != 0)
	{
		if ((fp = fopen(filename, "rb")) == NULL)
		{
			printf("|δ�ҵ����ļ�����ʹ��Ĭ���ļ�\n");
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

int incourse(Course* clist)//����γ���Ϣ
{
	FILE* fp;
	char filename[20];
	int i = 0;

	printf("|�����뱣��γ���Ϣ���ļ����ļ���: \n");
	if (scanf("%s", filename) != 0)
	{
		if ((fp = fopen(filename, "rb")) == NULL)
		{
			printf("|δ�ҵ����ļ�����ʹ��Ĭ���ļ�\n");
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

int insclist(Select* sclist)//����ѡ����Ϣ
{
	FILE* fp;
	char filename[20];
	int i = 0;

	printf("|�����뱣��ѡ����Ϣ���ļ����ļ���: \n");
	if (scanf("%s", filename) != 0)
	{
		if ((fp = fopen(filename, "rb")) == NULL)
		{
			printf("|δ�ҵ����ļ�����ʹ��Ĭ���ļ�\n");
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
/*�����ɼ���*/
{//countΪѧ����Ϣ����sccountΪѡ����Ϣ��
	int s = 0, sc, c, cj, t;
	/*
	sΪѭ��ѧ����Ϣ����
	cΪѭ���γ���Ϣ����
	scΪѭ��ѡ����Ϣ����
	cjΪѭ���ɼ���Ϣ����
	tΪ��ѧ����ѡ����Ŀ��
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
		printf("|�Ѵ�ӡ %d �ݳɼ���\r", ++s);
	}
}
