#include "ks_base.h"

void query_stud(Student* slist, int count)//��ѯѧ����Ϣ
{
	int an, t = 0;
	/*an��ȡ1��2��ȷ�����ҷ�ʽ
	t���жϼ�¼�Ƿ����*/
	int i;
	char xh[10], xm[20];//����������ʱ��Ŵ�
	printf("|��ȷ������Ҫ���ҵ���ѧ��ѧ�Ż���������\n");
	printf("|�������ѧ�ţ�����1��������������2��\n");
	scanf("%d", &an);
	if (an == 1)
	{
		printf("|��������Ҫ���ҵ�ѧ�ţ�\n");
		scanf("%s", xh);
		for (i = 0; i < count; i++)
		{
			if (strcmp(xh, slist[i].xh) == 0)
			{
				t = 1; break;
			}
		}
		if (t == 0) printf("|δ�ҵ���ѧ��ѧ��\n");
		else
			printf("|ѧ�ţ�%s\n|������%s\n|�Ա�%s\n|����\
��%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
	}
	if (an == 2)
	{
		printf("|��������Ҫ���ҵ�������\n");
		scanf("%s", xm);
		for (i = 0; i < count; i++)
		{
			if (strcmp(xm, slist[i].xm) == 0)
			{
				t = 1; break;
			}
		}
		if (t == 0) printf("|δ�ҵ�������ѧ��\n");
		else
			printf("|ѧ�ţ�%s\n|������%s\n|�Ա�%s\n|����\
��%d\n", slist[i].xh, slist[i].xm, slist[i].xb, slist[i].nl);
	}
}

void query_course(Course* clist, int count)//��ѯ�γ���Ϣ
{
	int an, t = 0;
	int i;
	char kh[10], km[25];
	printf("|��ȷ������Ҫ���ҵ��ǿγ̿κŻ��ǿ�����\n");
	printf("|������ǿκţ�����1���ǿ���������2��\n");
	scanf("%d", &an);
	if (an == 1)
	{
		printf("|��������Ҫ���ҵĿκţ�\n");
		scanf("%s", kh);
		for (i = 0; i < count; i++)
		{
			if (strcmp(kh, clist[i].kh) == 0)
			{
				t = 1; break;
			}
		}
		if (t == 0) printf("|δ�ҵ��ÿκſγ�\n");
		else
			printf("|�κţ�%s\n|������%s\n|ѧ�֣�%.2f\n",clist[i].kh,clist[i].km,clist[i].xf);
	}
	if (an == 2)
	{
		printf("|��������Ҫ���ҵĿ�����\n");
		scanf("%s", km);
		for (i = 0; i < count; i++)
		{
			if (strcmp(km, clist[i].km) == 0)
			{
				t = 1; break;
			}
		}
		if (t == 0) printf("|δ�ҵ��ÿ����γ�\n");
		else
			printf("|�κţ�%s\n|������%s\n|ѧ�֣�%.2f\n", clist[i].kh, clist[i].km, clist[i].xf);
	}
}

void query_cjlist(Score* cjlist, Student* slist, int count)//��ѯ�ɼ���Ϣ
{
	int an, t = 0;
	int i;
	char xh[10], xm[20];
	printf("|��������Ҫ��ѯ��ѧ����ѧ�Ż�������\n");
	printf("|�������ѧ�ţ�����1��������������2��\n");
	scanf("%d", &an);

	if (an == 1)
	{
		printf("|��������Ҫ���ҵ�ѧ�ţ�\n");
		scanf("%s", xh);

		for (i = 0; i < count; i++)
		{
			if (strcmp(xh, slist[i].xh) == 0)
			{
				t = 1;
				break;
			}
		}

		if (t == 0) printf("|δ�ҵ���ѧ��ѧ��\n");

		else
		{
			printf("|ѧ�ţ�%s\n|������%s\n", cjlist[i].xh, cjlist[i].xm);
			printf("|�Ա�%s\n|���䣺%d\n", slist[i].xb, slist[i].nl);
			for (int p = 0; p < cjlist[i].kcshu; p++)
			{
				printf("|�γ�����%s\t�ɼ���%.2f\n", cjlist[i].kc[p].km, cjlist[i].cj[p]);
			}
			printf("|��Ȩƽ���֣�%.2f\t��ѧ�֣�%.2f\n", cjlist[i].zpj, cjlist[i].zxf);
			printf("--------------------------------------\n");
		}
	}

	if (an == 2)
	{
		printf("|��������Ҫ���ҵ�������\n");
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

		if (t == 0) printf("|δ�ҵ�������ѧ��\n");

		else
		{
			printf("|ѧ�ţ�%s\n|������%s\n", cjlist[i].xh, cjlist[i].xm);
			printf("|�Ա�%s\n|���䣺%d\n", slist[i].xb, slist[i].nl);
			for (int p = 0; p < cjlist[i].kcshu; p++)
			{
				printf("|�γ�����%s\t�ɼ���%.2f\n", cjlist[i].kc[p].km, cjlist[i].cj[p]);
			}
			printf("|��Ȩƽ���֣�%.2f\t��ѧ�֣�%.2f\n", cjlist[i].zpj, cjlist[i].zxf);
			printf("--------------------------------------\n");
		}

	}
}