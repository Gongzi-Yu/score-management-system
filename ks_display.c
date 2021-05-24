#include "ks_base.h"

void disp_stud(Student* slist, int count)//��ʾѧ����Ϣ
{
	int i = 0;
	while ((getchar() != EOF) && (i < count))
	{
		do
		{
			printf("|ѧ�ţ�%s\t������%s\t�Ա�%s\t����\
��%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
		} while ((++i % 10 != 0) && (i < count));
		printf("|���س����Լ���");

	}
}

void disp_course(Course* clist, int count)//��ʾ�γ���Ϣ
{
	int i = 0;
	while ((getchar() != EOF) && (i < count))
	{
		do
		{
			printf("|�κţ�%s\t�γ�����%s\tѧ��\
��%.2f\n", clist[i].kh, clist[i].km, clist[i].xf);
		} while ((++i % 10 != 0) && (i < count));
		printf("|���س����Լ���");

	}
}

void disp_cjlist(Score* cjlist, int count)//��ʾ�ɼ���
{
	int i = 0;
	while ((getchar() != EOF) && (i < count))
	{
		do
		{
			printf("|ѧ�ţ�%s\n|������%s\n", cjlist[i].xh, cjlist[i].xm);
			for (int t = 0; t < cjlist[i].kcshu; t++)
			{
				printf("|�γ�����%s\t�ɼ���%.2f\n", cjlist[i].kc[t].km, cjlist[i].cj[t]);
			}
			printf("|��Ȩƽ���֣�%.2f\t��ѧ�֣�%.2f\n", cjlist[i].zpj, cjlist[i].zxf);
			printf("--------------------------------------\n");
		} while ((++i % 10 != 0) && (i < count));
		printf("|���س����Լ���");
	}
}

void sort_slist(Student* slist, int count)//��ѧ����Ϣ��������
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

void sort_clist(Course* clist, int count)//�Կγ���Ϣ��������
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
