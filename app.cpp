#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student
{
	int num;
	char name[20];
	char sex;
	double score[5];
	double sum;
	double aver;
} stu[1000];
int N = 0;		 // N表示学生个数
void in_comput() // 输入基本信息，计算每个学生各门功课总分sum、平均分aver。
{
	int i;
	printf("请输入学生的学号、姓名、性别、5门课程成绩:\n");
	while (1)
	{
		scanf("%d %s %c", &stu[N].num, stu[N].name, &stu[N].sex);
		for (i = 0; i < 5; i++)
		{
			scanf(" %lf", &stu[N].score[i]);
			stu[N].sum = stu[N].sum + stu[N].score[i];
		}
		stu[N].aver = (stu[N].sum) / 5.0;
		N++;
		printf("1.继续输入\n2.停止输入\n请输入序号：");
		scanf("\n%d", &i);
		while (i != 1 && i != 2)
		{
			printf("\a输入错误，请重新输入：");
			scanf("\n%d", &i);
		}
		if (i == 2)
			break;
	}
}
void aver_out() // 得到科目平均成绩并输出低于平均分的学生的基本信息
{
	int i, j, t = 0;
	double scoreaver[5] = {0};
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < N; j++)
			scoreaver[i] += stu[j].score[i];
		scoreaver[i] /= N;
	}
	for (i = 0; i < 5; i++)
		for (j = 0; j < N; j++)
			if (stu[j].score[i] < scoreaver[i])
			{
				t++;
				if (t == 1)
					printf("低于科目平均成绩的学生的基本信息如下：\n%-8s%-8s%-8s%-8s%-8s%-8s\n", "学号", "姓名", "性别", "科目", "平均", "成绩"); // 显示每门课程中低于平均分的每一个学生的学号，姓名，性别，科目，科目平均成绩，成绩。
				printf("%-8d%-8s%-8c%-8d%-8.2f%-8.2f\n", stu[j].num, stu[j].name, stu[j].sex, i + 1, scoreaver[i], stu[j].score[i]);
			}
	if (t == 0)
		printf("没有低于科目平均成绩的学生\n");
}
void output() // 按总分排序输出每个学生的基本信息、总分、平均分和名次。
{
	int i, j, a = 0;
	struct Student t;
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - 1 - i; j++)
			if (stu[j].sum < stu[j + 1].sum)
			{
				t = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = t;
			}
	for (i = 0; i < N; i++)
	{
		if (i == 0)
			printf("按总分排序后学生的基本信息、总分、平均分、名次如下：\n%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n", "学号", "姓名", "性别", "科目1", "科目2", "科目3", "科目4", "科目5", "总分", "平均分", "名次");
		printf("%-8d%-8s%-8c", stu[i].num, stu[i].name, stu[i].sex);
		for (j = 0; j < 5; j++)
			printf("%-8.2f", stu[i].score[j]);
		printf("%-8.2f%-8.2f%-8d\n", stu[i].sum, stu[i].aver, i + 1);
	}
}
void output90_60()
{ // 显示每门科目中，成绩在90分以上以及每门科目中不及格（60分以下）的学生基本信息。
	int i, j, a = 0, b = 0;
	for (i = 0; i < 5; i++)
		for (j = 0; j < N; j++)
			if (stu[j].score[i] > 90)
			{
				a++;
				if (a == 1)
					printf("科目成绩高于90分的学生的基本信息如下：\n%-8s%-8s%-8s%-8s%-8s\n", "学号", "姓名", "性别", "科目", "成绩");
				printf("%-8d%-8s%-8c%-8d%-8.2f\n", stu[j].num, stu[j].name, stu[j].sex, i + 1, stu[j].score[i]);
			}
	if (a == 0)
		printf("没有科目成绩高于90分的学生\n");
	for (i = 0; i < 5; i++)
		for (j = 0; j < N; j++)
			if (stu[j].score[i] < 60)
			{
				b++;
				if (b == 1)
					printf("科目成绩低于60分的学生的基本信息如下：\n%-8s%-8s%-8s%-8s%-8s\n", "学号", "姓名", "性别", "科目", "成绩");
				printf("%-8d%-8s%-8c%-8d%-8.2f\n", stu[j].num, stu[j].name, stu[j].sex, i + 1, stu[j].score[i]);
			}
	if (b == 0)
		printf("没有科目成绩低于60分的学生\n");
}
void tool()
{
	int n, s, v, i, t, j;
	char name[20];
	printf("||工具||\n|1.查询|\n|2.修改|\n|3.删除|\n|4.清空|\n请输入序号：");
	scanf("%d", &n);
	while (n != 1 && n != 2 && n != 3 && n != 4)
	{
		printf("\a输入错误，请重新输入：");
		scanf("%d", &n);
	}
	system("cls");
	if (n == 1) // 查询
	{
		printf("||查询|| \n");
		while (1)
		{
			t = 0;
			printf("|1.姓名|\n|2.学号|\n请输入序号：");
			scanf("%d", &s);
			while (s != 1 && s != 2)
			{
				printf("\a输入错误，请重新输入：");
				scanf("%d", &s);
			}
			if (s == 1)
			{
				printf("请输入学生姓名：");
				getchar();
				gets(name);
				for (i = 0; i < N; i++)
					if (strcmp(name, stu[i].name) == 0)
					{
						if (t == 0)
							printf("姓名为%s的学生的基本信息如下：\n%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n", name, "学号", "姓名", "性别", "科目1", "科目2", "科目3", "科目4", "科目5");
						t++;
						printf("%-8d%-8s%-8c%-8.2f%-8.2f%-8.2f%-8.2f%-8.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4]);
					}
				if (t == 0)
					printf("\a该生不存在\n");
			}
			if (s == 2)
			{
				printf("请输入学生学号：");
				scanf("%d", &v);
				for (i = 0; i < N; i++)
					if (stu[i].num == v)
					{
						if (t == 0)
							printf("学号为%d的学生的基本信息如下：\n%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n", v, "学号", "姓名", "性别", "科目1", "科目2", "科目3", "科目4", "科目5");
						t++;
						printf("%-8d%-8s%-8c%-8.2f%-8.2f%-8.2f%-8.2f%-8.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4]);
					}
				if (t == 0)
					printf("\a该生不存在\n");
			}
			printf("1.继续查询\n2.停止查询\n请输入序号：");
			scanf("\n%d", &i);
			while (i != 1 && i != 2)
			{
				printf("\a输入错误，请重新输入：");
				scanf("%d", &i);
			}
			if (i == 2)
				break;
		}
	}
	if (n == 2) // 修改
	{
		printf("||修改||\n");
		while (1)
		{
			t = 0;
			printf("|1.姓名|\n|2.学号|\n请输入序号：");
			scanf("%d", &s);
			while (s != 1 && s != 2)
			{
				printf("\a输入错误，请重新输入：");
				scanf("%d", &s);
			}
			if (s == 1)
			{
				printf("请输入学生姓名：");
				getchar();
				gets(name);
				for (i = 0; i < N; i++)
					if (strcmp(name, stu[i].name) == 0)
					{
						t++;
						printf("请按学号，姓名，性别，5门课程成绩依此输入该生修改后的信息：\n");
						scanf("%d %s %c %lf %lf %lf %lf %lf", &stu[i].num, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2], &stu[i].score[3], &stu[i].score[4]);
					}
				if (t == 0)
					printf("\a该生不存在\n");
			}
			if (s == 2)
			{
				printf("请输入学生学号：");
				scanf("%d", &v);
				for (i = 0; i < N; i++)
					if (stu[i].num == v)
					{
						t++;
						printf("请按学号，姓名，性别，5门课程成绩依此输入该生修改后的信息：\n");
						scanf("%d %s %c %lf %lf %lf %lf %lf", &stu[i].num, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2], &stu[i].score[3], &stu[i].score[4]);
					}
				if (t == 0)
					printf("\a该生不存在\n");
			}
			printf("1.继续修改\n2.停止修改\n请输入序号：");
			scanf("\n%d", &i);
			while (i != 1 && i != 2)
			{
				printf("\a输入错误，请重新输入：");
				scanf("%d", &i);
			}
			if (i == 2)
				break;
		}
	}
	if (n == 3) // 删除
	{
		printf("||删除||\n");
		while (1)
		{
			if (N == 0)
			{
				printf("\a无学生，无法进行删除\n");
				break;
			}
			t = 0;
			printf("|1.姓名|\n|2.学号|\n请输入序号：");
			scanf("%d", &s);
			while (s != 1 && s != 2)
			{
				printf("\a输入错误，请重新输入：");
				scanf("%d", &s);
			}
			if (s == 1)
			{
				printf("请输入学生姓名：");
				getchar();
				gets(name);
				for (i = 0; i < N; i++)
					if (strcmp(name, stu[i].name) == 0)
					{
						t++;
						for (j = i; j < N - 1; j++)
							stu[j] = stu[j + 1];
						N--;
					}
				if (t == 0)
					printf("\a该生不存在\n");
				else
					printf("已删除姓名为%s的学生的信息\n", name);
			}
			if (s == 2)
			{
				printf("请输入学生学号：");
				scanf("%d", &v);
				for (i = 0; i < N; i++)
					if (stu[i].num == v)
					{
						t++;
						for (j = i; j < N - 1; j++)
							stu[j] = stu[j + 1];
						N--;
					}
				if (t == 0)
					printf("\a该生不存在\n");
				else
					printf("已删除学号为%d的学生的信息\n", v);
			}
			printf("1.继续删除\n2.停止删除\n请输入序号：");
			scanf("\n%d", &i);
			while (i != 1 && i != 2)
			{
				printf("\a输入错误，请重新输入：");
				scanf("\n%d", &i);
			}
			if (i == 2)
				break;
		}
	}
	if (n == 4) // 清空
	{
		memset(stu, 0x0, 1000); // memset(变量地址，0x00,大小)。
		N = 0;
		printf("已清空\n");
	}
}
void start() // 主菜单
{
	void Write();
	int m;
	printf("||主 菜 单||\n|  1.输入  |\n|  2.显示  |\n|  3.工具  |\n|  4.退出  |\n请输入序号：");
	scanf("%d", &m);
	while (m != 1 && m != 2 && m != 3 && m != 4)
	{
		printf("\a输入错误，请重新输入：");
		scanf("%d", &m);
	}
	system("cls");
	if (m == 1)		 // 输入成绩
		in_comput(); // 输入成绩，计算每个学生各门功课总分sum、平均分aver。
	if (m == 2)		 // 显示所有信息
		if (N == 0)
			printf("\a无学生,无法显示信息\n");
		else
		{
			output();	   // 按总分排序输出每个学生的基本信息及总分、平均分和名次。
			aver_out();	   // 得到科目平均成绩scoreaver并输出低于平均分的学生的信息。
			output90_60(); // 显示每门科目中，成绩在90分以上的学生信息，以及每门科目中不及格（60分以下）的学生信息。
		}
	if (m == 3) // 工具
		if (N == 0)
			printf("\a无学生,无法使用工具\n");
		else
			tool();
	if (m == 4) // 退出
	{
		Write();
		printf("**********\n已退出系统\n**********\n");
		exit(0);
	}
}
void Read() // 将学生信息从文件读出
{
	FILE *fp;
	int i;
	if ((fp = fopen("Student Database.txt", "rb")) == NULL)
		return;
	if (fread(&N, sizeof(int), 1, fp) != 1) // if (fscanf(fp,"%d",&N) < 0)
		N = -1;
	else
		for (i = 0; i < N; i++)
			fread(&stu[i], sizeof(struct Student), 1, fp); // fscanf(fp, "%d %s %c %.2f %.2f %.2f %.2f %.2f %.2f %.2f", &stu[i].num, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2], &stu[i].score[3], &stu[i].score[4], &stu[i].sum, &stu[i].aver);
	fclose(fp);
}
void Write() // 将学生信息写入文件
{
	FILE *fp;
	int i;
	if ((fp = fopen("Student Database.txt", "wb")) == NULL)
	{
		printf("\a不能打开文件\n");
		return;
	}
	if (fwrite(&N, sizeof(int), 1, fp) != 1) // if(fprintf(fp,"%d",N)<0)
		printf("\a写入文件错误\n");
	for (i = 0; i < N; i++)
		if (fwrite(&stu[i], sizeof(struct Student), 1, fp) != 1) // if (fprintf(fp, "%d %s %c %.2f %.2f %.2f %.2f %.2f %.2f %.2f", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].sum, stu[i].aver)<0)
			printf("\a写入文件错误\n");
	fclose(fp);
}
int main() // 主函数
{
	int t = 0, w;
	Read();
	char userid[] = "lcy", password[] = "123", a[100], b[100];
	system("color 80"); // 画面颜色
	printf("****************************\n欢迎使用学生成绩统计管理系统\n****************************\n");
	do
	{ // 登陆界面
		if (t != 0)
			printf("\a用户名或密码错误，请重新输入\n");
		t++;
		if (t > 3)
		{
			printf("\a连续输错3次，自动退出系统，请稍候再试（用户名、密码在《说明报告》中）\n");
			exit(0);
		}
		printf("用户名：");
		gets(a);
		printf("密码：");
		gets(b);
	} while (strcmp(a, userid) != 0 || strcmp(b, password) != 0); // 满足条件时循环操作
	system("cls"); // 清屏进入内部页面
	printf("********\n登陆成功\n********\n");
	do
	{
		start(); // 主菜单
		printf("|1.返回|\n|2.退出|\n请输入序号：");
		scanf("%d", &w);
		while (w != 1 && w != 2)
		{
			printf("\a输入错误，请重新输入：");
			scanf("%d", &w);
		}
		system("cls");
	} while (w == 1);
	Write();
	printf("**********\n已退出系统\n**********\n");
	exit(0);
	return 0;
}