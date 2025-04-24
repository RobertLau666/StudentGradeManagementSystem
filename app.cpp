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
int N = 0;		 // N��ʾѧ������
void in_comput() // ���������Ϣ������ÿ��ѧ�����Ź����ܷ�sum��ƽ����aver��
{
	int i;
	printf("������ѧ����ѧ�š��������Ա�5�ſγ̳ɼ�:\n");
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
		printf("1.��������\n2.ֹͣ����\n��������ţ�");
		scanf("\n%d", &i);
		while (i != 1 && i != 2)
		{
			printf("\a����������������룺");
			scanf("\n%d", &i);
		}
		if (i == 2)
			break;
	}
}
void aver_out() // �õ���Ŀƽ���ɼ����������ƽ���ֵ�ѧ���Ļ�����Ϣ
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
					printf("���ڿ�Ŀƽ���ɼ���ѧ���Ļ�����Ϣ���£�\n%-8s%-8s%-8s%-8s%-8s%-8s\n", "ѧ��", "����", "�Ա�", "��Ŀ", "ƽ��", "�ɼ�"); // ��ʾÿ�ſγ��е���ƽ���ֵ�ÿһ��ѧ����ѧ�ţ��������Ա𣬿�Ŀ����Ŀƽ���ɼ����ɼ���
				printf("%-8d%-8s%-8c%-8d%-8.2f%-8.2f\n", stu[j].num, stu[j].name, stu[j].sex, i + 1, scoreaver[i], stu[j].score[i]);
			}
	if (t == 0)
		printf("û�е��ڿ�Ŀƽ���ɼ���ѧ��\n");
}
void output() // ���ܷ��������ÿ��ѧ���Ļ�����Ϣ���ܷ֡�ƽ���ֺ����Ρ�
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
			printf("���ܷ������ѧ���Ļ�����Ϣ���ܷ֡�ƽ���֡��������£�\n%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n", "ѧ��", "����", "�Ա�", "��Ŀ1", "��Ŀ2", "��Ŀ3", "��Ŀ4", "��Ŀ5", "�ܷ�", "ƽ����", "����");
		printf("%-8d%-8s%-8c", stu[i].num, stu[i].name, stu[i].sex);
		for (j = 0; j < 5; j++)
			printf("%-8.2f", stu[i].score[j]);
		printf("%-8.2f%-8.2f%-8d\n", stu[i].sum, stu[i].aver, i + 1);
	}
}
void output90_60()
{ // ��ʾÿ�ſ�Ŀ�У��ɼ���90�������Լ�ÿ�ſ�Ŀ�в�����60�����£���ѧ��������Ϣ��
	int i, j, a = 0, b = 0;
	for (i = 0; i < 5; i++)
		for (j = 0; j < N; j++)
			if (stu[j].score[i] > 90)
			{
				a++;
				if (a == 1)
					printf("��Ŀ�ɼ�����90�ֵ�ѧ���Ļ�����Ϣ���£�\n%-8s%-8s%-8s%-8s%-8s\n", "ѧ��", "����", "�Ա�", "��Ŀ", "�ɼ�");
				printf("%-8d%-8s%-8c%-8d%-8.2f\n", stu[j].num, stu[j].name, stu[j].sex, i + 1, stu[j].score[i]);
			}
	if (a == 0)
		printf("û�п�Ŀ�ɼ�����90�ֵ�ѧ��\n");
	for (i = 0; i < 5; i++)
		for (j = 0; j < N; j++)
			if (stu[j].score[i] < 60)
			{
				b++;
				if (b == 1)
					printf("��Ŀ�ɼ�����60�ֵ�ѧ���Ļ�����Ϣ���£�\n%-8s%-8s%-8s%-8s%-8s\n", "ѧ��", "����", "�Ա�", "��Ŀ", "�ɼ�");
				printf("%-8d%-8s%-8c%-8d%-8.2f\n", stu[j].num, stu[j].name, stu[j].sex, i + 1, stu[j].score[i]);
			}
	if (b == 0)
		printf("û�п�Ŀ�ɼ�����60�ֵ�ѧ��\n");
}
void tool()
{
	int n, s, v, i, t, j;
	char name[20];
	printf("||����||\n|1.��ѯ|\n|2.�޸�|\n|3.ɾ��|\n|4.���|\n��������ţ�");
	scanf("%d", &n);
	while (n != 1 && n != 2 && n != 3 && n != 4)
	{
		printf("\a����������������룺");
		scanf("%d", &n);
	}
	system("cls");
	if (n == 1) // ��ѯ
	{
		printf("||��ѯ|| \n");
		while (1)
		{
			t = 0;
			printf("|1.����|\n|2.ѧ��|\n��������ţ�");
			scanf("%d", &s);
			while (s != 1 && s != 2)
			{
				printf("\a����������������룺");
				scanf("%d", &s);
			}
			if (s == 1)
			{
				printf("������ѧ��������");
				getchar();
				gets(name);
				for (i = 0; i < N; i++)
					if (strcmp(name, stu[i].name) == 0)
					{
						if (t == 0)
							printf("����Ϊ%s��ѧ���Ļ�����Ϣ���£�\n%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n", name, "ѧ��", "����", "�Ա�", "��Ŀ1", "��Ŀ2", "��Ŀ3", "��Ŀ4", "��Ŀ5");
						t++;
						printf("%-8d%-8s%-8c%-8.2f%-8.2f%-8.2f%-8.2f%-8.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4]);
					}
				if (t == 0)
					printf("\a����������\n");
			}
			if (s == 2)
			{
				printf("������ѧ��ѧ�ţ�");
				scanf("%d", &v);
				for (i = 0; i < N; i++)
					if (stu[i].num == v)
					{
						if (t == 0)
							printf("ѧ��Ϊ%d��ѧ���Ļ�����Ϣ���£�\n%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n", v, "ѧ��", "����", "�Ա�", "��Ŀ1", "��Ŀ2", "��Ŀ3", "��Ŀ4", "��Ŀ5");
						t++;
						printf("%-8d%-8s%-8c%-8.2f%-8.2f%-8.2f%-8.2f%-8.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4]);
					}
				if (t == 0)
					printf("\a����������\n");
			}
			printf("1.������ѯ\n2.ֹͣ��ѯ\n��������ţ�");
			scanf("\n%d", &i);
			while (i != 1 && i != 2)
			{
				printf("\a����������������룺");
				scanf("%d", &i);
			}
			if (i == 2)
				break;
		}
	}
	if (n == 2) // �޸�
	{
		printf("||�޸�||\n");
		while (1)
		{
			t = 0;
			printf("|1.����|\n|2.ѧ��|\n��������ţ�");
			scanf("%d", &s);
			while (s != 1 && s != 2)
			{
				printf("\a����������������룺");
				scanf("%d", &s);
			}
			if (s == 1)
			{
				printf("������ѧ��������");
				getchar();
				gets(name);
				for (i = 0; i < N; i++)
					if (strcmp(name, stu[i].name) == 0)
					{
						t++;
						printf("�밴ѧ�ţ��������Ա�5�ſγ̳ɼ�������������޸ĺ����Ϣ��\n");
						scanf("%d %s %c %lf %lf %lf %lf %lf", &stu[i].num, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2], &stu[i].score[3], &stu[i].score[4]);
					}
				if (t == 0)
					printf("\a����������\n");
			}
			if (s == 2)
			{
				printf("������ѧ��ѧ�ţ�");
				scanf("%d", &v);
				for (i = 0; i < N; i++)
					if (stu[i].num == v)
					{
						t++;
						printf("�밴ѧ�ţ��������Ա�5�ſγ̳ɼ�������������޸ĺ����Ϣ��\n");
						scanf("%d %s %c %lf %lf %lf %lf %lf", &stu[i].num, stu[i].name, &stu[i].sex, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2], &stu[i].score[3], &stu[i].score[4]);
					}
				if (t == 0)
					printf("\a����������\n");
			}
			printf("1.�����޸�\n2.ֹͣ�޸�\n��������ţ�");
			scanf("\n%d", &i);
			while (i != 1 && i != 2)
			{
				printf("\a����������������룺");
				scanf("%d", &i);
			}
			if (i == 2)
				break;
		}
	}
	if (n == 3) // ɾ��
	{
		printf("||ɾ��||\n");
		while (1)
		{
			if (N == 0)
			{
				printf("\a��ѧ�����޷�����ɾ��\n");
				break;
			}
			t = 0;
			printf("|1.����|\n|2.ѧ��|\n��������ţ�");
			scanf("%d", &s);
			while (s != 1 && s != 2)
			{
				printf("\a����������������룺");
				scanf("%d", &s);
			}
			if (s == 1)
			{
				printf("������ѧ��������");
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
					printf("\a����������\n");
				else
					printf("��ɾ������Ϊ%s��ѧ������Ϣ\n", name);
			}
			if (s == 2)
			{
				printf("������ѧ��ѧ�ţ�");
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
					printf("\a����������\n");
				else
					printf("��ɾ��ѧ��Ϊ%d��ѧ������Ϣ\n", v);
			}
			printf("1.����ɾ��\n2.ֹͣɾ��\n��������ţ�");
			scanf("\n%d", &i);
			while (i != 1 && i != 2)
			{
				printf("\a����������������룺");
				scanf("\n%d", &i);
			}
			if (i == 2)
				break;
		}
	}
	if (n == 4) // ���
	{
		memset(stu, 0x0, 1000); // memset(������ַ��0x00,��С)��
		N = 0;
		printf("�����\n");
	}
}
void start() // ���˵�
{
	void Write();
	int m;
	printf("||�� �� ��||\n|  1.����  |\n|  2.��ʾ  |\n|  3.����  |\n|  4.�˳�  |\n��������ţ�");
	scanf("%d", &m);
	while (m != 1 && m != 2 && m != 3 && m != 4)
	{
		printf("\a����������������룺");
		scanf("%d", &m);
	}
	system("cls");
	if (m == 1)		 // ����ɼ�
		in_comput(); // ����ɼ�������ÿ��ѧ�����Ź����ܷ�sum��ƽ����aver��
	if (m == 2)		 // ��ʾ������Ϣ
		if (N == 0)
			printf("\a��ѧ��,�޷���ʾ��Ϣ\n");
		else
		{
			output();	   // ���ܷ��������ÿ��ѧ���Ļ�����Ϣ���ܷ֡�ƽ���ֺ����Ρ�
			aver_out();	   // �õ���Ŀƽ���ɼ�scoreaver���������ƽ���ֵ�ѧ������Ϣ��
			output90_60(); // ��ʾÿ�ſ�Ŀ�У��ɼ���90�����ϵ�ѧ����Ϣ���Լ�ÿ�ſ�Ŀ�в�����60�����£���ѧ����Ϣ��
		}
	if (m == 3) // ����
		if (N == 0)
			printf("\a��ѧ��,�޷�ʹ�ù���\n");
		else
			tool();
	if (m == 4) // �˳�
	{
		Write();
		printf("**********\n���˳�ϵͳ\n**********\n");
		exit(0);
	}
}
void Read() // ��ѧ����Ϣ���ļ�����
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
void Write() // ��ѧ����Ϣд���ļ�
{
	FILE *fp;
	int i;
	if ((fp = fopen("Student Database.txt", "wb")) == NULL)
	{
		printf("\a���ܴ��ļ�\n");
		return;
	}
	if (fwrite(&N, sizeof(int), 1, fp) != 1) // if(fprintf(fp,"%d",N)<0)
		printf("\aд���ļ�����\n");
	for (i = 0; i < N; i++)
		if (fwrite(&stu[i], sizeof(struct Student), 1, fp) != 1) // if (fprintf(fp, "%d %s %c %.2f %.2f %.2f %.2f %.2f %.2f %.2f", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].sum, stu[i].aver)<0)
			printf("\aд���ļ�����\n");
	fclose(fp);
}
int main() // ������
{
	int t = 0, w;
	Read();
	char userid[] = "lcy", password[] = "123", a[100], b[100];
	system("color 80"); // ������ɫ
	printf("****************************\n��ӭʹ��ѧ���ɼ�ͳ�ƹ���ϵͳ\n****************************\n");
	do
	{ // ��½����
		if (t != 0)
			printf("\a�û����������������������\n");
		t++;
		if (t > 3)
		{
			printf("\a�������3�Σ��Զ��˳�ϵͳ�����Ժ����ԣ��û����������ڡ�˵�����桷�У�\n");
			exit(0);
		}
		printf("�û�����");
		gets(a);
		printf("���룺");
		gets(b);
	} while (strcmp(a, userid) != 0 || strcmp(b, password) != 0); // ��������ʱѭ������
	system("cls"); // ���������ڲ�ҳ��
	printf("********\n��½�ɹ�\n********\n");
	do
	{
		start(); // ���˵�
		printf("|1.����|\n|2.�˳�|\n��������ţ�");
		scanf("%d", &w);
		while (w != 1 && w != 2)
		{
			printf("\a����������������룺");
			scanf("%d", &w);
		}
		system("cls");
	} while (w == 1);
	Write();
	printf("**********\n���˳�ϵͳ\n**********\n");
	exit(0);
	return 0;
}