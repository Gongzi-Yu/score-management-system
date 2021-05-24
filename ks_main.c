#include "ks_base.h"
//引用其他c文件的函数
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
	printf("|0. 退出当前系统；\n");
	printf("|1. 装入：从指定的文件中导入学生、课程以及选课信息，并创建成绩单；\n");
	printf("|2. 显示：显示系统中所有学生信息、课程信息、选课信息、成绩单；\n");
	printf("|3. 输入：通过键盘输入学生记录、课程记录、选课记录；\n");
	printf("|4. 删除：删除一条已经存在的学生记录或课程记录、选课记录；\n");
	printf("|5. 查找：根据用户输入的属性值查找符合条件的记录；\n");
	printf("|6. 输出：把当前所有的学生、课程、选课信息、成绩单输出的指定文件；\n");
	printf("-----------------------------------------------------------------\n");
}

#define S 12
#define C 12
#define SC 22

int main()
{
	int s = 0, c = 0, sc = 0;
	/*
	s、c、sc分别为学生信息、课程信息、选课信息的记录数
	文件导入后会更新s、c、sc
	*/
	Student slist[S];
	Course clist[C];
	Select sclist[SC];
	Score cjlist[S];

	int answer;
	do
	{
		disktop();//循环显示主菜单
		printf("|请给出你的选择：（输入0~6中的一个数字）\n");
		if (scanf("%d", &answer) == 1)
		{
			if (answer == 1)
			{
				s = instud(slist);
				c = incourse(clist);
				sc = insclist(sclist);
				create_cjlist(slist, sclist, clist, cjlist, s, sc);
				printf("\n已装入完毕\n");
				printf("\n\n\f");
			}

			else if (answer == 2)
			{
				int answer_02;
				printf("-----------------\n");
				printf("|0. 返回；\n");
				printf("|1. 显示学生信息；\n");
				printf("|2. 显示课程信息；\n");
				printf("|3. 显示成绩信息；\n");
				printf("-----------------\n");
				printf("|请给出你的选择：（输入0~3中的一个数字）\n");
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
				printf("|0. 返回；\n");
				printf("|1. 添加学生信息；\n");
				printf("|2. 添加课程信息；\n");
				printf("|3. 添加成绩信息；\n");
				printf("-----------------\n");
				printf("|请给出你的选择：（输入0~3中的一个数字）\n");
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
				printf("|0. 返回；\n");
				printf("|1. 删除学生信息；\n");
				printf("|2. 删除课程信息；\n");
				printf("|3. 删除成绩信息；\n");
				printf("-----------------\n");
				printf("|请给出你的选择：（输入0~3中的一个数字）\n");
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
				printf("|0. 返回；\n");
				printf("|1. 查询学生信息；\n");
				printf("|2. 查询课程信息；\n");
				printf("|3. 查询成绩信息；\n");
				printf("-----------------\n");
				printf("|请给出你的选择：（输入0~3中的一个数字）\n");
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
				printf("|0. 返回；\n");
				printf("|1. 导出学生、课程、选课信息；\n");
				printf("|2. 导出成绩单信息；\n");
				printf("-----------------\n");
				printf("|请给出你的选择：（输入0~2中的一个数字）\n");
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
	} while (answer != 0);//如果answer==0，自动退出
	return 0;
}