#include "ks_base.h"
//��������c�ļ��ĺ���
extern int instud(Student*);
extern int incourse(Course*);
extern int insclist(Select*);
extern void create_cjlist(Student*, Select*, Course*, Score*, int, int);

extern void disp_stud(Student*, int);
extern void disp_course(Course*, int);
extern void disp_cjlist(Score*, int);
extern void sort_slist(Student*, int);
extern void sort_clist(Course*, int);

extern int add_stud(Student*, int);
extern int add_course(Course*, int);
extern int add_select(Select*, int);

extern int delete_stud(Student*, int);
extern int delete_course(Course*, int);
extern int delete_select(Select*, int);

extern void query_stud(Student*, int);
extern void query_course(Course*, int);
extern void query_cjlist(Score*, Student*, int);

extern void write_to_file_1(Student*, Course*, Select*, int, int, int);
extern void write_to_file_2(Student*, Score*, int);


void disktop(void)
{
	printf("-----------------------------------------------------------------\n");
	printf("|0. �˳���ǰϵͳ��\n");
	printf("|1. װ�룺��ָ�����ļ��е���ѧ�����γ��Լ�ѡ����Ϣ���������ɼ�����\n");
	printf("|2. ��ʾ����ʾϵͳ������ѧ����Ϣ���γ���Ϣ��ѡ����Ϣ���ɼ�����\n");
	printf("|3. ���룺ͨ����������ѧ����¼���γ̼�¼��ѡ�μ�¼��\n");
	printf("|4. ɾ����ɾ��һ���Ѿ����ڵ�ѧ����¼��γ̼�¼��ѡ�μ�¼��\n");
	printf("|5. ���ң������û����������ֵ���ҷ��������ļ�¼��\n");
	printf("|6. ������ѵ�ǰ���е�ѧ�����γ̡�ѡ����Ϣ���ɼ��������ָ���ļ���\n");
	printf("-----------------------------------------------------------------\n");
}

#define S 12
#define C 12
#define SC 22

int main()
{
	int s = 0, c = 0, sc = 0;
	/*
	s��c��sc�ֱ�Ϊѧ����Ϣ���γ���Ϣ��ѡ����Ϣ�ļ�¼��
	�ļ����������s��c��sc
	*/
	Student slist[S];
	Course clist[C];
	Select sclist[SC];
	Score cjlist[S];

	int answer;
	do
	{
		disktop();//ѭ����ʾ���˵�
		printf("|��������ѡ�񣺣�����0~6�е�һ�����֣�\n");
		if (scanf("%d", &answer) == 1)
		{
			if (answer == 1)
			{
				s = instud(slist);
				c = incourse(clist);
				sc = insclist(sclist);
				create_cjlist(slist, sclist, clist, cjlist, s, sc);
				printf("\n��װ�����\n");
				printf("\n\n\f");
			}

			else if (answer == 2)
			{
				int answer_02;
				printf("-----------------\n");
				printf("|0. ���أ�\n");
				printf("|1. ��ʾѧ����Ϣ��\n");
				printf("|2. ��ʾ�γ���Ϣ��\n");
				printf("|3. ��ʾ�ɼ���Ϣ��\n");
				printf("-----------------\n");
				printf("|��������ѡ�񣺣�����0~3�е�һ�����֣�\n");
				if (scanf("%d", &answer_02) == 1)
				{
					if (answer_02 == 1)
					{
						sort_slist(slist, s);
						disp_stud(slist, s);
					}
					if (answer_02 == 2)
					{
						sort_clist(clist, c);
						disp_course(clist, c);
					}
					if (answer_02 == 3)
					{
						create_cjlist(slist, sclist, clist, cjlist, s, sc);
						printf("\n");
						disp_cjlist(cjlist, s);
					}
				}
				printf("\n\n\f");

			}

			else if (answer == 3)
			{
				int answer_02;
				printf("-----------------\n");
				printf("|0. ���أ�\n");
				printf("|1. ���ѧ����Ϣ��\n");
				printf("|2. ��ӿγ���Ϣ��\n");
				printf("|3. ��ӳɼ���Ϣ��\n");
				printf("-----------------\n");
				printf("|��������ѡ�񣺣�����0~3�е�һ�����֣�\n");
				if (scanf("%d", &answer_02) == 1)
				{
					if (answer_02 == 1)
					{
						s = add_stud(slist, s);
					}
					if (answer_02 == 2)
					{
						c = add_course(clist, c);
					}
					if (answer_02 == 3)
					{
						sc = add_select(sclist, sc);
					}

				}
				printf("\n\n\f");

			}

			else if (answer == 4)
			{
				int answer_02;
				printf("-----------------\n");
				printf("|0. ���أ�\n");
				printf("|1. ɾ��ѧ����Ϣ��\n");
				printf("|2. ɾ���γ���Ϣ��\n");
				printf("|3. ɾ���ɼ���Ϣ��\n");
				printf("-----------------\n");
				printf("|��������ѡ�񣺣�����0~3�е�һ�����֣�\n");
				if (scanf("%d", &answer_02) == 1)
				{
					if (answer_02 == 1)
					{
						s = delete_stud(slist, s);
					}
					if (answer_02 == 2)
					{
						c = delete_course(clist, c);
					}
					if (answer_02 == 3)
					{
						sc = delete_select(sclist, sc);
					}
				}
				printf("\n\n\f");

			}

			else if (answer == 5)
			{
				int answer_02;
				printf("-----------------\n");
				printf("|0. ���أ�\n");
				printf("|1. ��ѯѧ����Ϣ��\n");
				printf("|2. ��ѯ�γ���Ϣ��\n");
				printf("|3. ��ѯ�ɼ���Ϣ��\n");
				printf("-----------------\n");
				printf("|��������ѡ�񣺣�����0~3�е�һ�����֣�\n");
				if (scanf("%d", &answer_02) == 1)
				{
					if (answer_02 == 1)
					{
						query_stud(slist, s);
					}
					if (answer_02 == 2)
					{
						query_course(clist, c);
					}
					if (answer_02 == 3)
					{
						query_cjlist(cjlist, slist, s);
					}

				}
				printf("\n\n\f");

			}

			else if (answer == 6)
			{
				int answer_02;
				printf("-----------------\n");
				printf("|0. ���أ�\n");
				printf("|1. ����ѧ�����γ̡�ѡ����Ϣ��\n");
				printf("|2. �����ɼ�����Ϣ��\n");
				printf("-----------------\n");
				printf("|��������ѡ�񣺣�����0~2�е�һ�����֣�\n");
				if (scanf("%d", &answer_02) == 1)
				{
					if (answer_02 == 1)
					{
						write_to_file_1(slist, clist, sclist, s, c, s);
					}
					if (answer_02 == 2)
					{
						write_to_file_2(slist, cjlist, s);
					}
				}
				printf("\n\n\f");

			}
		}
	} while (answer != 0);//���answer==0���Զ��˳�
	return 0;
}