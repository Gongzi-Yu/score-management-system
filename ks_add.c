#include "ks_base.h"

int add_stud(Student* slist, int count)//���ѧ����Ϣ
{
	int s;
	/*s��Ҫ��ӵ�ѧ����Ϣ��
	*/
	printf("|��������Ҫ��ӵ�ѧ����Ϣ����\n");
	scanf("%d", &s);
	for (int i = count; i < count + s; i++)
	{
		int p = i, x = 0;//��i��ֵ���浽p��x���ж��Ƿ��滻
		printf("|���������%d��ѧ������Ϣ��\n", i - count + 1);
		printf("|�������ѧ����ѧ�ţ�\n");
		scanf("%s", slist[i].xh);

		for (int j = 0; j < i; j++)
		{
			if (strcmp(slist[i].xh, slist[j].xh) == 0)
			{
				int an;
				printf("|��ѧ����Ϣ�Ѵ��ڣ������Ƿ��滻��\n");
				printf("|(����滻������1����������2)\n");
				scanf("%d", &an);
				p--;
				if (an == 1)
				{
					
					i = j;
					printf("|���������ѧ��������Ϣ��\n");
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
		printf("|�������ѧ����������\n");
		scanf("%s", slist[i].xm);

		printf("|�������ѧ�����Ա���|Ů����\n");
		scanf("%s", slist[i].xb);

		printf("|�������ѧ�������䣺\n");
		scanf("%d", &slist[i].nl);
		i = p;
	}
	return (count + s);
}

int add_course(Course* clist, int count)
{
	int s;
	printf("|��������Ҫ��ӵĿγ���Ϣ����\n");
	scanf("%d", &s);
	for (int i = count; i < count + s; i++)
	{
		int p = i, x = 0;
		printf("|���������%d���γ̵���Ϣ��\n", i - count + 1);
		printf("|������ÿγ̵Ŀκţ�\n");
		scanf("%s", clist[i].kh);

		for (int j = 0; j < i; j++)
		{
			if (strcmp(clist[i].kh, clist[j].kh) == 0)
			{
				int an;
				printf("|�ÿγ���Ϣ�Ѵ��ڣ������Ƿ��滻��\n");
				printf("|(����滻������1����������2)\n");
				scanf("%d", &an);
				p--;
				if (an == 1)
				{
					
					i = j;
					printf("|��������ÿγ̵�����Ϣ��\n");
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
		printf("|������ÿγ̵Ŀ�����\n");
		scanf("%s", clist[i].km);

		printf("|������ÿγ̵�ѧ�֣�\n");
		scanf("%f", &clist[i].xf);
		i = p;
	}
	return (count + s);

}

int add_select(Select* sclist, int count)
{
	int s, w = 0;//w���ظ���ѡ����Ϣ��
	printf("|��������Ҫ��ӵ�ѡ����Ϣ����\n");
	scanf("%d", &s);
	for (int i = count; i < count + s; i++)
	{
		int x = 0;//�ж������ѧ���Ƿ����
		char xh[10];
		printf("|���������%d��ѡ�ε���Ϣ��\n", i - count + 1);
		printf("|�������ѡ����Ϣ��ѧ�ţ�\n");
		scanf("%s", xh);
		printf("|������ѧ��%s��ѡ����Ϣ��\n", xh);
		for (int t = 0; t < i; t++)
		{
			if (strcmp(xh, sclist[t].xh) == 0)
			{
				x = 1;
				printf("|�κţ�%s\t�ɼ���%.2f\n", sclist[t].kh, sclist[t].cj);
			}
		}
		if (x == 0)
		{
			printf("|ϵͳ��δ�ҵ���ѧ��ѧ����ѡ�μ�¼��\n\
��ȷ���Ƿ��������\n");
			printf("--------------------------------\n");
			i--;
		}
		else
		{
			int t = 0;//�ж��Ƿ��滻
			int p = i;
			strcpy(sclist[i].xh, xh);
			printf("|������������Ҫ��ӵ�ѡ����Ϣ�Ŀκţ�\n");
			scanf("%s", sclist[i].kh);

			for (int j = 0; j < i; j++)
			{
				if ((strcmp(sclist[i].kh, sclist[j].kh) == 0) && \
					(strcmp(sclist[i].xh, sclist[j].xh) == 0))
				{
					int an;
					printf("|�ÿκŵ�ѡ����Ϣ�Ѵ��ڣ������Ƿ��滻�ɼ���\n");
					printf("|(����滻������1����������2)\n");
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
			printf("|���������ѡ����Ϣ�ĳɼ���\n");
			scanf("%f", &sclist[i].cj);
			i = p;
		}
	}
	return (count + s - w);
}