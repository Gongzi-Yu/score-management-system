#include "ks_base.h"


int delete_stud(Student* slist, int count)//ɾ��ѧ����Ϣ
{
	int an;//�ж�ɾ����Ϣ�ķ�ʽ
	int i, j = 0;
	char xh[10], xm[20];//������Ϣ��ʱ��Ŵ�
	printf("|�������Ǹ���ѧ�Ż���������ɾ����Ϣ�ģ�\n");
	printf("|(�����ѧ�ţ�������1�������������������2)\n");
	scanf("%d", &an);
	if (an == 1)
	{
		printf("|��������Ҫɾ����ѧ�ţ�\n");
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
		printf("|��ɾ���ɹ�\n");
	}
	if (an == 2)
	{
		printf("|��������Ҫɾ����������\n");
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
		printf("|��ɾ���ɹ�\n");
	}
	return j;
}

int delete_course(Course* clist, int count)//ɾ���γ���Ϣ
{
	int an;
	int i, j = 0;
	char kh[10], km[25];
	printf("|�������Ǹ��ݿκŻ��ǿ�����ɾ����Ϣ�ģ�\n");
	printf("|(����ǿκţ�������1������ǿ�����������2)\n");
	scanf("%d", &an);
	if (an == 1)
	{
		printf("|��������Ҫɾ���Ŀκţ�\n");
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
		printf("|��ɾ���ɹ�\n");
	}
	if (an == 2)
	{
		printf("|��������Ҫɾ���Ŀ�����\n");
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
		printf("|��ɾ���ɹ�\n");
	}
	return j;
}

int delete_select(Select* sclist, int count)//ɾ��ѡ����Ϣ
{
	int i, j = 0;
	int t = 0;
	char xh[10], kh[10];
	printf("|��������Ҫɾ����ѡ�μ�¼��ѧ����ѧ�ţ�\n");
	scanf("%s", xh);
	printf("|������ѧ��%s��ѡ����Ϣ��\n", xh);
	for (; t < count; t++)
	{
		if (strcmp(xh, sclist[t].xh) == 0)
			printf("|�κţ�%s\t�ɼ���%.2f\n", sclist[t].kh, sclist[t].cj);
	}
	printf("|��������Ҫɾ����ѡ�μ�¼�Ŀκţ�\n");
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
	printf("|��ɾ�����\n");
	return j;
}