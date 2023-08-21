/***********************************************************
�ҵ���Ϣ:                                                 *
  ����: ������		����:1985��2��26��                    *
  ��ҵѧУ: 2007���ڳɶ�����ѧ                          *
  �����ַ: �Ĵ�������Ϫ���ɽ��5��                       *
  ��ϵQQ: 287307421  ��ϵ�绰: 13558690869                *
  ��ϵEmail: wangjianlin1985@126.com 287307421            *
  ˫���ֳ����Ա���: http://shop34864101.taobao.com        *
  ˫���ֳ������ĵ�: http://287307421.paipai.com           *
  ��վ: http://www.shuangyulin.com                        *
														  *
  ��Ҫ������������ϵ�ң���֤���У�                      *
***********************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#define N 20
#define FILENAME "songs.txt"
struct song
{
	int num;		  /*�������*/
	char name[30];	  /*��������*/
	char singer[30];  /*��������*/
	char editor[30];  /*ר������*/
	char type[30];	  /*��������*/
	int date;		  /*�������*/
	char address[30]; /*���е���*/
	int time;		  /*����ʱ��*/
	int times;		  /*�㳪����*/
	float score;	  /*���۷���*/
};
/*******************************************************
����:��ʾ�˵�
��������
����ֵ����
 *******************************************************/
void scan()
{

	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++*++++++\n");
	printf("+               KTV��������ϵͳ                          +\n");
	printf("+                                                        +\n");
	printf("+                 1.  ������Ϣ                           +\n");
	printf("+                 2.  �����Ϣ                           +\n");
	printf("+                 3.  ��������Ų�                       +\n");
	printf("+                 4.  ����������                         +\n");
	printf("+                 5.  ��ר�����Ʋ�                       +\n");
	printf("+                 6.  ������������                       +\n");
	printf("+                 7.  ��Ӹ�����Ϣ                       +\n");
	printf("+                 8.  ɾ��������Ϣ                       +\n");
	printf("+                 9.  �޸ĸ�����Ϣ                       +\n");
	printf("+                 10. ��蹦��                           +\n");
	printf("+                 11. ���۹���                           +\n");
	printf("+                 12. ���㳪��������                     +\n");
	printf("+                 13. �����۷���������                   +\n");
	printf("+                 14. ���ļ���                           +\n");
	printf("+                 15. �������                           +\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
/*******************************************************
����:��½��������֤����
������
����1��n
  ���ͣ�char []
  ˵�����û��������
����ֵ��1��0
  ���ͣ�int
  ˵����1��ʾͨ����֤��0��ʾû��ͨ��
 *******************************************************/
int login(char password[])
{
	static char key[20] = "123";
	if (strcmp(password, key) == 0)
		return 1;
	else
		return 0;
}
/*******************************************************
����:���ļ�����Ϣ���ṹ��������
������
����1��songs[]
  ���ͣ�song []
  ˵���������洢���ļ������ĸ�����Ϣ
����ֵ��i
  ���ͣ�int
  ˵������ʾʵ�ʶ�ȡ���ĸ���
 *******************************************************/
int readFromFile(struct song songs[])
{
	FILE *fp = NULL;
	int i = 0;
	fp = fopen(FILENAME, "rb"); /*���ļ�*/

	if (fp != NULL)
	{

		while (!feof(fp)) /*���ļ��ж������*/
		{

			if (i >= N)
				break;
			if (fread(songs + i, sizeof(struct song), 1, fp) == 1)
				i++;
		}

		fclose(fp);
	}
	return i;
}

/*******************************************************
����:�жϸ����Ƿ�Ψһ
������
����1��songs[]
  ���ͣ�song []
  ˵�����洢������Ϣ������
����2��N
  ���ͣ�int
  ˵������ʾʵ������ĳ���
����2��songsnum
  ���ͣ�int
  ˵����Ҫ�жϵĸ������
����ֵ��1��0(flag)
  ���ͣ�int
  ˵����1��ʾ����Ψһ��0��ʾ������Ψһ��
 *******************************************************/
int unique(struct song songs[], int n, int songsnum, int cur)
{

	int flag = 1, i;
	for (i = 0; i < n; i++)
	{
		if (songs[i].num == songsnum && i != cur)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
/*******************************************************
����:������Ϣ���ṹ��������
������
����1��songs[]
 ���ͣ�song []
 ˵���������洢������Ϣ������
����2��N
 ���ͣ�int
 ˵������ʾʵ������ĳ���
����ֵ��i
 ���ͣ�int
 ˵������ʾ������Ϣ��ʵ������ĳ���
*******************************************************/

int input(struct song songs[], int n)
{
	int i = n;
	int endFlag = 0;
	printf("�����������Ϣ,�Ը������Ϊ�������\n");
	while (i < N)
	{
		while (1)
		{
			int flag;
			printf("��ţ�");
			scanf("%d", &songs[i].num);
			if (songs[i].num == 0)
			{
				endFlag = 1;
				break;
			}
			flag = unique(songs, i, songs[i].num, i);
			if (flag)
				break;
			printf("�ñ���Ѿ����ڣ�����������!\n");
		}
		if (endFlag == 1)
			break;
		printf("��������");
		scanf("%s", songs[i].name);
		printf("���֣�");
		scanf("%s", songs[i].singer);
		printf("ר����");
		scanf("%s", songs[i].editor);
		printf("���ɣ�");
		scanf("%s", songs[i].type);
		printf("�������ڣ�");
		scanf("%d", &songs[i].date);
		printf("���е�����");
		scanf("%s", songs[i].address);
		printf("ʱ��: ");
		scanf("%d min", &songs[i].time);
		i++;
	}
	return i;
}
/*******************************************************
���ܣ�ɾ��������Ϣ
������
����1��songs[]
  ���ͣ�song []
  ˵���������洢������Ϣ������
����2��N
  ���ͣ�int
  ˵������ʾʵ������ĳ���
����ֵ��i
  ���ͣ�int
  ˵������ʾɾ����Ϣ��ʵ������ĳ���
*******************************************************/
// int N=i;
int del(struct song songs[], int n)
{
	int i, j, found = 0;
	char delname[20];
	char choice;
	printf("��������Ҫɾ���ĸ�������:\n"); /*ɾ���ĸ�������Ϣ*/
	scanf("%s", delname);
	for (i = 0; i < n; i++)
	{
		if (strcmp(songs[i].name, delname) == 0)
		{
			found++;
			printf("�ҵ���!\n");
			printf("���:%d\n", songs[i].num);
			printf("����:%s\n", songs[i].name);
			printf("����:%s\n", songs[i].singer);
			printf("ר��:%s\n", songs[i].editor);
			printf("����:%s\n", songs[i].type);
			printf("��������:%d\n", songs[i].date);
			printf("���е���:%s\n", songs[i].address);
			printf("ʱ��:%d min\n", songs[i].time);
			printf("��ȷʵҪɾ�����׸���?(Y/N)");
			getchar();
			scanf("%c", &choice);
			if (choice == 'Y' || choice == 'y')
			{
				for (j = i; j < n; j++)
					songs[j] = songs[j + 1];
				n--;
				printf("ɾ���ɹ�!\n");
			}
			i--;
		}
	}
	if (found == 0)
		printf("\nָ���ĸ���������!\n");

	return n;
}
/*******************************************************
���ܣ��޸ĸ�����Ϣ
����1��songs[]
  ���ͣ�song []
  ˵���������洢������Ϣ������
����2��N
  ���ͣ�int
  ˵������ʾʵ������ĳ���

����ֵ����
*********************************************************/
void changecommunicate(struct song songs[], int n)
{

	int i, found = 0;
	char chcname[20];
	int choicecom;
	printf("����������Ҫ�޸ĵĸ�������:\n"); /*�޸ĵĸ�������Ϣ*/
	scanf("%s", chcname);
	for (i = 0; i < n; i++)
	{
		if (strcmp(songs[i].name, chcname) == 0)
		{
			found++;
			printf("����Ϊ����Ҫ�޸ĵĸ�������Ϣ:\n");
			printf("��������Ϊ%s\n", songs[i].name);
			printf("��������%s\n", songs[i].singer);
			printf("ר������Ϊ%s\n", songs[i].editor);
			printf("��������Ϊ%s\n", songs[i].type);
			printf("�������Ϊ%d\n", songs[i].date);
			printf("���е���Ϊ%s\n", songs[i].address);
			printf("����ʱ��Ϊ%d min\n", songs[i].time);
			printf("����ѡ��Ҫ�޸ĵĶ���:\n");
			printf("*****************************************\n");
			printf("1�޸�ר������\n");
			printf("2�޸ĸ�������\n");
			printf("0�˳�ϵͳ\n");
			printf("*****************************************\n");
			scanf("%d", &choicecom);
			switch (choicecom)
			{
			case 1:
			{
				printf("������ר����");
				scanf("%s", songs[i].editor);
			}
			break;
			case 2:
			{
				printf("�����¸���������");
				scanf("%s", songs[i].singer);
			}
			break;
			case 0:
				return;
			default:
				printf("�����д�\n");
			}
		}
	}
	if (found == 0)
		printf("��ѡ����������:\n");
}
/*******************************************************
����:���ṹ�������еĸ�����Ϣ��ʾ����Ļ���ļ���
������
����1��songs[]
 ���ͣ�song []
 ���������洢������Ϣ������
����2��N
 ���ͣ�int
 ˵������ʾʵ������ĳ���
����ֵ����
*******************************************************/
void output(struct song songs[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("��ţ�");
		printf("%d\n", songs[i].num);
		printf("��������");
		printf("%s\n", songs[i].name);
		printf("���֣�");
		printf("%s\n", songs[i].singer);
		printf("ר����");
		printf("%s\n", songs[i].editor);
		printf("���ɣ�");
		printf("%s\n", songs[i].type);
		printf("�������ڣ�");
		printf("%d\n", songs[i].date);
		printf("���е�����");
		printf("%s\n", songs[i].address);
		printf("ʱ��: ");
		printf("%d min\n", songs[i].time);
		printf("��������");
		printf("%d\n", songs[i].times);
		printf("���۷�����");
		printf("%f\n", songs[i].score);
	}
}
/*******************************************************
����:���ݱ�Ŵ������в��Ҹ���
������
����1��songs[]
  ���ͣ�song []
  ˵���������洢������Ϣ������
����2��N
  ���ͣ�int
  ˵������ʾʵ������ĳ���
����3��songsnum
  ���ͣ�int
  ˵������ʾҪ���ҵĸ����ı��
����ֵ����
 *******************************************************/
void queryInfonum(struct song songs[], int n, int num)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (num == songs[i].num)
		{
			printf("�ҵ����������±��� :%d\n", i);
			printf("���:%d\n", songs[i].num);
			printf("����:%s\n", songs[i].name);
			printf("����:%s\n", songs[i].singer);
			printf("ר��:%s\n", songs[i].editor);
			printf("����:%s\n", songs[i].type);
			printf("��������:%d\n", songs[i].date);
			printf("���е���:%s\n", songs[i].address);
			printf("ʱ��:%d min\n", songs[i].time);
			break;
		}
	}
	if (i >= n)
		printf("\n�����ڣ�\n");
}

/*******************************************************
����:���ݸ������������в��Ҹ���
������
����1��songs[]
  ���ͣ�song []
  ˵���������洢������Ϣ������
����2��N
  ���ͣ�int
  ˵������ʾʵ������ĳ���
����3��songsname
  ���ͣ�char
  ˵������ʾҪ���ҵĸ����ĸ���
����ֵ����
 *******************************************************/
void queryInfoname(struct song songs[], int n, char name[])
{
	int i, found = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(name, songs[i].name) == 0)
		{
			found++;
			printf("�ҵ����������±��� :%d\n", i);
			printf("���:%d\n", songs[i].num);
			printf("����:%s\n", songs[i].name);
			printf("����:%s\n", songs[i].singer);
			printf("ר��:%s\n", songs[i].editor);
			printf("����:%s\n", songs[i].type);
			printf("��������:%d\n", songs[i].date);
			printf("���е���:%s\n", songs[i].address);
			printf("ʱ��:%d min\n", songs[i].time);
		}
	}
	if (found == 0)
		printf("\n�����ڣ�\n");
}
/*******************************************************
����:���ݸ��ִ������в��Ҹ���
������
����1��songs[]
  ���ͣ�song[]
  ˵���������洢������Ϣ������
����2��N
  ���ͣ�int
  ˵������ʾʵ������ĳ���
����3��songsinger
  ���ͣ�char
  ˵������ʾҪ���ҵĸ����ĸ���
����ֵ����
 *******************************************************/
void queryInfosinger(struct song songs[], int n, char singer[])
{
	int i, found = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(singer, songs[i].singer) == 0)
		{
			found++;
			printf("�ҵ����������±��� :%d\n", i);
			printf("���:%d\n", songs[i].num);
			printf("����:%s\n", songs[i].name);
			printf("����:%s\n", songs[i].singer);
			printf("ר��:%s\n", songs[i].editor);
			printf("����:%s\n", songs[i].type);
			printf("��������:%d\n", songs[i].date);
			printf("���е���:%s\n", songs[i].address);
			printf("ʱ��:%d min\n", songs[i].time);
		}
	}
	if (found == 0)
		printf("\n�����ڣ�\n");
}
/*******************************************************
����:����ר���������в��Ҹ���
������
����1��songs[]
  ���ͣ�song []
  ˵���������洢������Ϣ������
����2��N
  ���ͣ�int
  ˵������ʾʵ������ĳ���
����3��songseditor
  ���ͣ�char
  ˵������ʾҪ���ҵĸ�����ר��
����ֵ����
 *******************************************************/
void queryInfoeditor(struct song songs[], int n, char editor[])
{
	int i, found = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(editor, songs[i].editor) == 0)
		{
			found++;
			printf("�ҵ����������±��� :%d\n", i);
			printf("���:%d\n", songs[i].num);
			printf("����:%s\n", songs[i].name);
			printf("����:%s\n", songs[i].singer);
			printf("ר��:%s\n", songs[i].editor);
			printf("����:%s\n", songs[i].type);
			printf("��������:%d\n", songs[i].date);
			printf("���е���:%s\n", songs[i].address);
			printf("ʱ��:%d min\n", songs[i].time);
		}
	}

	if (found == 0)
		printf("\n�����ڣ�\n");
}
/************************************************
��蹦��
   ���������ţ��㳪�����Զ���1����ʾ"���ɹ�"
**************************************************/
// for(i=0;i<N;i++)
// songs[i].times=0;
void choice(struct song songs[], int n)
{
	int i, num;
	printf("��������ѡ�������:");
	scanf("%d", &num);
	for (i = 0; i < n; i++)
	{
		if (songs[i].num == num)
		{
			songs[i].times += 1;
			printf("���ɹ�!");
			break;
		}
	}
	if (i >= n)
		printf("\n����ĸ費���ڣ�\n");
}
/********************************************
�������۹���
���������źͷ������˸������۷������ӣ���ʾ"���۳ɹ�"��
**************************************************/
// for(i=0;i<N;i++)
// songs[i].score=0;
void appraise(struct song songs[], int n)
{
	int i, num;
	float score;
	printf("��������ѡ�������:");
	scanf("%d", &num);
	for (i = 0; i < n; i++)
		if (songs[i].num == num)
		{
			printf("���������۷���:");
			scanf("%f", &score);
			songs[i].score += score;
			printf("���۳ɹ�!");
			break;
		}
	if (i >= n)
		printf("\n����ĸ費���ڣ�\n");
}
/*���㳪�����Ӵ�С����*/
void sort1(struct song songs[], int n)
{

	int i, j;
	struct song t;
	for (j = 0; j < n - 1; j++)
		for (i = 0; i < n - j - 1; i++)
			if (songs[i].times < songs[i + 1].times)
			{
				t = songs[i];
				songs[i] = songs[i + 1];
				songs[i + 1] = t;
			}
	printf("��� �������� ������\n");
	for (i = 0; i < n && i < 10; i++)
	{
		printf("%4d ", songs[i].num);
		printf("%10s ", songs[i].name);
		printf("%4d ", songs[i].times);
		printf("\n");
	}
}
/*�����������Ӵ�С����*/
void sort2(struct song songs[], int n)
{
	int i, j;
	struct song t;
	for (j = 0; j < n - 1; j++)
		for (i = 0; i < n - j - 1; i++)
			if (songs[i].score < songs[i + 1].score)
			{
				t = songs[i];
				songs[i] = songs[i + 1];
				songs[i + 1] = t;
			}
	printf("��� �������� ���۷���\n");
	for (i = 0; i < n && i < 10; i++)
	{
		printf("%4d ", songs[i].num);
		printf("%10s ", songs[i].name);
		printf("%6.0f ", songs[i].score);
		printf("\n");
	}
}
/*******************************************************
����:�ṹ�������еĸ�����Ϣ������ļ�
������
����1��songs
  ���ͣ�song []
  ˵���������洢���ļ������ĸ�����Ϣ
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ���
����ֵ����
 *******************************************************/
void writeToFile(struct song songs[], int length)
{
	FILE *fp = NULL;
	int i = 0;

	fp = fopen(FILENAME, "wb");

	if (fp == NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}

	for (i = 0; i < length; i++)
		fwrite(songs + i, sizeof(struct song), 1, fp);

	fclose(fp);
}

void main()
{
	struct song songs[N];
	char password[20];
	int choices = 0; /*select and store menu item  */
	int s = 0;
	int num, sum = 0, i;
	char name[20], singer[20], editor[20];
	/*====��֤�û��Ŀ��ֱ����ȷΪֹ====*/
	do
	{
		printf("��������");
		scanf("%s", password);

		s = login(password);
	} while (s == 0);
	/*====�����û���ѡ��ִ����Ӧ�Ĳ���.====*/
	for (i = 0; i < N; i++)
		songs[i].times = 0;
	for (i = 0; i < N; i++)
		songs[i].score = 0;
	sum = readFromFile(songs);
	while (1)
	{

		scan();
		printf("\n ��ѡ�����Ĳ���(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15)��\n");
		scanf("%d", &choices);

		switch (choices)
		{

		case 1:
			sum = input(songs, sum);
			printf("\n����%d��������Ϣ\n", sum);
			break;
		case 2:
			if (sum == 0)
				printf("ϵͳ��û�и�����Ϣ�����ȳ�ʼ����\n\n");
			else
				output(songs, sum);
			break;
		case 3:
			printf("�����������ҵĸ�����ţ�\n");
			scanf("%d", &num);
			queryInfonum(songs, sum, num);
			break;
		case 4:
			printf("�����������ҵĸ�������\n");
			scanf("%s", name);
			queryInfoname(songs, sum, name);
			break;
		case 5:
			printf("�����������ҵ�ר����\n");
			scanf("%s", editor);
			queryInfoeditor(songs, sum, editor);
			break;
		case 6:
			printf("�����������ҵĸ��֣�\n");
			scanf("%s", singer);
			queryInfosinger(songs, sum, singer);
			break;
		case 7:
			sum = input(songs, sum);
			printf("\n����%d��������Ϣ\n", sum);
			break;
		case 8:
			sum = del(songs, sum);
			break;
		case 9:
			changecommunicate(songs, sum);
			break;
		case 10:
			choice(songs, sum);
			break;
		case 11:
			appraise(songs, sum);
			break;
		case 12:
			sort1(songs, sum);
			break;
		case 13:
			sort2(songs, sum);
			break;

		case 14:
			sum = readFromFile(songs);
			break;
		case 15:
			writeToFile(songs, sum);
			exit(0);
			break;
		}
	}
}