#include "ks_base.h"


void write_to_file_1(Student* slist, Course* clist, Select* sclist, int s, int c, int sc)
/*���ѧ����Ϣ���γ���Ϣ��ѡ����Ϣ*/
{
	FILE* st, * co, * se;
	/*
	st��ָ��ѧ����Ϣ�ļ�
	co��ָ��γ���Ϣ�ļ�
	se��ָ��ѡ����Ϣ�ļ�
	*/
	char studname[20], courname[20], selname[20];

	printf("|������ѧ����Ϣ����ļ�����\n");
	scanf("%s", studname);
	st = fopen(studname, "w");
	if (st == NULL)
	{
		printf("|%s�ļ��޷���\n", studname);
		exit(1);
	}
	for (int i = 0; i < s; i++)
	{
		fprintf(st, "|ѧ�ţ�%s\t������%s\t�Ա�%s\t����\
��%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
	}

	printf("|������α���Ϣ����ļ�����\n");
	scanf("%s", courname);
	co = fopen(courname, "w");
	if (co == NULL)
	{
		printf("|%s�ļ��޷���\n", courname);
		exit(1);
	}
	for (int i = 0; i < c; i++)
	{
		fprintf(co, "|�κţ�%s\t������%s\tѧ�֣�%.2f\n", clist[i].kh, clist[i].km, clist[i].xf);
	}

	printf("|������ѡ����Ϣ����ļ�����\n");
	scanf("%s", selname);
	se = fopen(selname, "w");
	if (se == NULL)
	{
		printf("|%s�ļ��޷���\n", selname);
		exit(1);
	}
	for (int i = 0; i < sc; i++)
	{
		fprintf(se, "|ѧ�ţ�%s\t�κţ�%s\t�ɼ���%.2f\n", sclist[i].kh, sclist[i].xh, sclist[i].cj);
	}
	printf("|ȫ���������\n");
	fclose(st);
	fclose(co);
	fclose(se);
}

void write_to_file_2(Student* slist, Score* cjlist, int s)
{
	FILE* sco;
	char sconame[20];
	printf("|������ɼ������ļ�����\n");
	scanf("%s", sconame);
	sco = fopen(sconame, "w");
	if (sco == NULL)
	{
		printf("|%s�ļ��޷���\n", sconame);
		exit(1);
	}
	for (int i = 0; i < s; i++)
	{
		fprintf(sco, "|ѧ�ţ�%s\t������%s\n", cjlist[i].xh, cjlist[i].xm);
		fprintf(sco, "|�Ա�%s\t���䣺%d\n", slist[i].xb, slist[i].nl);
		for (int t = 0; t < cjlist[i].kcshu; t++)
		{
			fprintf(sco, "|�κţ�%s\t������%s\t�ɼ�\
��%.2f\n", cjlist[i].kc[t].kh, cjlist[i].kc[t].km, cjlist[i].cj[t]);
			fprintf(sco, "-------------------------------------------------\n");
		}
		fprintf(sco, "|ƽ���֣�%.2f\t��ѧ�֣�%.2f\n", cjlist[i].zpj, cjlist[i].zxf);
		fprintf(sco, "----------------------------------------------------\
---------------------------\n");
	}
	printf("|�������\n");
	fclose(sco);
}