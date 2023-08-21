/***********************************************************
我的信息:                                                 *
  姓名: 汪建林		生日:1985年2月26日                    *
  毕业学校: 2007年于成都理工大学                          *
  家乡地址: 四川渠县望溪乡包山村5组                       *
  联系QQ: 287307421  联系电话: 13558690869                *
  联系Email: wangjianlin1985@126.com 287307421            *
  双鱼林程序淘宝店: http://shop34864101.taobao.com        *
  双鱼林程序拍拍店: http://287307421.paipai.com           *
  网站: http://www.shuangyulin.com                        *
														  *
  需要更多程序可以联系我，保证运行！                      *
***********************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#define N 20
#define FILENAME "songs.txt"
struct song
{
	int num;		  /*歌曲编号*/
	char name[30];	  /*歌曲名称*/
	char singer[30];  /*歌手姓名*/
	char editor[30];  /*专辑名称*/
	char type[30];	  /*歌曲流派*/
	int date;		  /*出版年份*/
	char address[30]; /*发行地区*/
	int time;		  /*歌曲时长*/
	int times;		  /*点唱人数*/
	float score;	  /*评价分数*/
};
/*******************************************************
功能:显示菜单
参数：无
返回值：无
 *******************************************************/
void scan()
{

	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++*++++++\n");
	printf("+               KTV歌曲管理系统                          +\n");
	printf("+                                                        +\n");
	printf("+                 1.  输入信息                           +\n");
	printf("+                 2.  输出信息                           +\n");
	printf("+                 3.  按歌曲编号查                       +\n");
	printf("+                 4.  按歌曲名查                         +\n");
	printf("+                 5.  按专辑名称查                       +\n");
	printf("+                 6.  按歌手姓名查                       +\n");
	printf("+                 7.  添加歌曲信息                       +\n");
	printf("+                 8.  删除歌曲信息                       +\n");
	printf("+                 9.  修改歌曲信息                       +\n");
	printf("+                 10. 点歌功能                           +\n");
	printf("+                 11. 评价功能                           +\n");
	printf("+                 12. 按点唱人数排序                     +\n");
	printf("+                 13. 按评价分数数排序                   +\n");
	printf("+                 14. 从文件读                           +\n");
	printf("+                 15. 程序结束                           +\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
/*******************************************************
功能:登陆函数，验证口令
参数：
参数1：n
  类型：char []
  说明：用户输入口令
返回值：1或0
  类型：int
  说明：1表示通过验证；0表示没有通过
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
功能:从文件读信息到结构体数组中
参数：
参数1：songs[]
  类型：song []
  说明：用来存储从文件读到的歌曲信息
返回值：i
  类型：int
  说明：表示实际读取到的个数
 *******************************************************/
int readFromFile(struct song songs[])
{
	FILE *fp = NULL;
	int i = 0;
	fp = fopen(FILENAME, "rb"); /*打开文件*/

	if (fp != NULL)
	{

		while (!feof(fp)) /*从文件中读入歌曲*/
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
功能:判断歌曲是否唯一
参数：
参数1：songs[]
  类型：song []
  说明：存储歌曲信息的数组
参数2：N
  类型：int
  说明：表示实际数组的长度
参数2：songsnum
  类型：int
  说明：要判断的歌曲编号
返回值：1或0(flag)
  类型：int
  说明：1表示歌曲唯一；0表示歌曲不唯一。
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
功能:输入信息到结构体数组中
参数：
参数1：songs[]
 类型：song []
 说明：用来存储歌曲信息的数组
参数2：N
 类型：int
 说明：表示实际数组的长度
返回值：i
 类型：int
 说明：表示增加信息后，实际数组的长度
*******************************************************/

int input(struct song songs[], int n)
{
	int i = n;
	int endFlag = 0;
	printf("请输入歌曲信息,以歌曲编号为零结束：\n");
	while (i < N)
	{
		while (1)
		{
			int flag;
			printf("编号：");
			scanf("%d", &songs[i].num);
			if (songs[i].num == 0)
			{
				endFlag = 1;
				break;
			}
			flag = unique(songs, i, songs[i].num, i);
			if (flag)
				break;
			printf("该编号已经存在，请重新输入!\n");
		}
		if (endFlag == 1)
			break;
		printf("歌曲名：");
		scanf("%s", songs[i].name);
		printf("歌手：");
		scanf("%s", songs[i].singer);
		printf("专辑：");
		scanf("%s", songs[i].editor);
		printf("流派：");
		scanf("%s", songs[i].type);
		printf("发行日期：");
		scanf("%d", &songs[i].date);
		printf("发行地区：");
		scanf("%s", songs[i].address);
		printf("时长: ");
		scanf("%d min", &songs[i].time);
		i++;
	}
	return i;
}
/*******************************************************
功能：删除歌曲信息
参数：
参数1：songs[]
  类型：song []
  说明：用来存储歌曲信息的数组
参数2：N
  类型：int
  说明：表示实际数组的长度
返回值：i
  类型：int
  说明：表示删除信息后，实际数组的长度
*******************************************************/
// int N=i;
int del(struct song songs[], int n)
{
	int i, j, found = 0;
	char delname[20];
	char choice;
	printf("请你输入要删除的歌曲名称:\n"); /*删除的歌曲的信息*/
	scanf("%s", delname);
	for (i = 0; i < n; i++)
	{
		if (strcmp(songs[i].name, delname) == 0)
		{
			found++;
			printf("找到啦!\n");
			printf("编号:%d\n", songs[i].num);
			printf("歌名:%s\n", songs[i].name);
			printf("歌手:%s\n", songs[i].singer);
			printf("专辑:%s\n", songs[i].editor);
			printf("流派:%s\n", songs[i].type);
			printf("发行日期:%d\n", songs[i].date);
			printf("发行地区:%s\n", songs[i].address);
			printf("时长:%d min\n", songs[i].time);
			printf("你确实要删除这首歌吗?(Y/N)");
			getchar();
			scanf("%c", &choice);
			if (choice == 'Y' || choice == 'y')
			{
				for (j = i; j < n; j++)
					songs[j] = songs[j + 1];
				n--;
				printf("删除成功!\n");
			}
			i--;
		}
	}
	if (found == 0)
		printf("\n指定的歌曲不存在!\n");

	return n;
}
/*******************************************************
功能：修改歌曲信息
参数1：songs[]
  类型：song []
  说明：用来存储歌曲信息的数组
参数2：N
  类型：int
  说明：表示实际数组的长度

返回值：无
*********************************************************/
void changecommunicate(struct song songs[], int n)
{

	int i, found = 0;
	char chcname[20];
	int choicecom;
	printf("请你输入你要修改的歌曲名称:\n"); /*修改的歌曲的信息*/
	scanf("%s", chcname);
	for (i = 0; i < n; i++)
	{
		if (strcmp(songs[i].name, chcname) == 0)
		{
			found++;
			printf("以下为您所要修改的歌曲的信息:\n");
			printf("歌曲名称为%s\n", songs[i].name);
			printf("歌手姓名%s\n", songs[i].singer);
			printf("专辑名称为%s\n", songs[i].editor);
			printf("歌曲流派为%s\n", songs[i].type);
			printf("出版年份为%d\n", songs[i].date);
			printf("发行地区为%s\n", songs[i].address);
			printf("歌曲时长为%d min\n", songs[i].time);
			printf("请你选择要修改的东西:\n");
			printf("*****************************************\n");
			printf("1修改专辑名称\n");
			printf("2修改歌手姓名\n");
			printf("0退出系统\n");
			printf("*****************************************\n");
			scanf("%d", &choicecom);
			switch (choicecom)
			{
			case 1:
			{
				printf("输入新专辑：");
				scanf("%s", songs[i].editor);
			}
			break;
			case 2:
			{
				printf("输入新歌手姓名：");
				scanf("%s", songs[i].singer);
			}
			break;
			case 0:
				return;
			default:
				printf("输入有错\n");
			}
		}
	}
	if (found == 0)
		printf("所选歌曲不存在:\n");
}
/*******************************************************
功能:将结构体数组中的歌曲信息显示到屏幕和文件中
参数：
参数1：songs[]
 类型：song []
 明：用来存储歌曲信息的数组
参数2：N
 类型：int
 说明：表示实际数组的长度
返回值：无
*******************************************************/
void output(struct song songs[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("编号：");
		printf("%d\n", songs[i].num);
		printf("歌曲名：");
		printf("%s\n", songs[i].name);
		printf("歌手：");
		printf("%s\n", songs[i].singer);
		printf("专辑：");
		printf("%s\n", songs[i].editor);
		printf("流派：");
		printf("%s\n", songs[i].type);
		printf("发行日期：");
		printf("%d\n", songs[i].date);
		printf("发行地区：");
		printf("%s\n", songs[i].address);
		printf("时长: ");
		printf("%d min\n", songs[i].time);
		printf("点歌次数：");
		printf("%d\n", songs[i].times);
		printf("评价分数：");
		printf("%f\n", songs[i].score);
	}
}
/*******************************************************
功能:根据编号从数组中查找歌曲
参数：
参数1：songs[]
  类型：song []
  说明：用来存储歌曲信息的数组
参数2：N
  类型：int
  说明：表示实际数组的长度
参数3：songsnum
  类型：int
  说明：表示要查找的歌曲的编号
返回值：无
 *******************************************************/
void queryInfonum(struct song songs[], int n, int num)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (num == songs[i].num)
		{
			printf("找到啦！它的下标是 :%d\n", i);
			printf("编号:%d\n", songs[i].num);
			printf("歌名:%s\n", songs[i].name);
			printf("歌手:%s\n", songs[i].singer);
			printf("专辑:%s\n", songs[i].editor);
			printf("流派:%s\n", songs[i].type);
			printf("发行日期:%d\n", songs[i].date);
			printf("发行地区:%s\n", songs[i].address);
			printf("时长:%d min\n", songs[i].time);
			break;
		}
	}
	if (i >= n)
		printf("\n不存在！\n");
}

/*******************************************************
功能:根据歌曲名从数组中查找歌曲
参数：
参数1：songs[]
  类型：song []
  说明：用来存储歌曲信息的数组
参数2：N
  类型：int
  说明：表示实际数组的长度
参数3：songsname
  类型：char
  说明：表示要查找的歌曲的歌名
返回值：无
 *******************************************************/
void queryInfoname(struct song songs[], int n, char name[])
{
	int i, found = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(name, songs[i].name) == 0)
		{
			found++;
			printf("找到啦！它的下标是 :%d\n", i);
			printf("编号:%d\n", songs[i].num);
			printf("歌名:%s\n", songs[i].name);
			printf("歌手:%s\n", songs[i].singer);
			printf("专辑:%s\n", songs[i].editor);
			printf("流派:%s\n", songs[i].type);
			printf("发行日期:%d\n", songs[i].date);
			printf("发行地区:%s\n", songs[i].address);
			printf("时长:%d min\n", songs[i].time);
		}
	}
	if (found == 0)
		printf("\n不存在！\n");
}
/*******************************************************
功能:根据歌手从数组中查找歌曲
参数：
参数1：songs[]
  类型：song[]
  说明：用来存储歌曲信息的数组
参数2：N
  类型：int
  说明：表示实际数组的长度
参数3：songsinger
  类型：char
  说明：表示要查找的歌曲的歌手
返回值：无
 *******************************************************/
void queryInfosinger(struct song songs[], int n, char singer[])
{
	int i, found = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(singer, songs[i].singer) == 0)
		{
			found++;
			printf("找到啦！它的下标是 :%d\n", i);
			printf("编号:%d\n", songs[i].num);
			printf("歌名:%s\n", songs[i].name);
			printf("歌手:%s\n", songs[i].singer);
			printf("专辑:%s\n", songs[i].editor);
			printf("流派:%s\n", songs[i].type);
			printf("发行日期:%d\n", songs[i].date);
			printf("发行地区:%s\n", songs[i].address);
			printf("时长:%d min\n", songs[i].time);
		}
	}
	if (found == 0)
		printf("\n不存在！\n");
}
/*******************************************************
功能:根据专辑从数组中查找歌曲
参数：
参数1：songs[]
  类型：song []
  说明：用来存储歌曲信息的数组
参数2：N
  类型：int
  说明：表示实际数组的长度
参数3：songseditor
  类型：char
  说明：表示要查找的歌曲的专辑
返回值：无
 *******************************************************/
void queryInfoeditor(struct song songs[], int n, char editor[])
{
	int i, found = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(editor, songs[i].editor) == 0)
		{
			found++;
			printf("找到啦！它的下标是 :%d\n", i);
			printf("编号:%d\n", songs[i].num);
			printf("歌名:%s\n", songs[i].name);
			printf("歌手:%s\n", songs[i].singer);
			printf("专辑:%s\n", songs[i].editor);
			printf("流派:%s\n", songs[i].type);
			printf("发行日期:%d\n", songs[i].date);
			printf("发行地区:%s\n", songs[i].address);
			printf("时长:%d min\n", songs[i].time);
		}
	}

	if (found == 0)
		printf("\n不存在！\n");
}
/************************************************
点歌功能
   输入歌曲编号，点唱人数自动加1，显示"点歌成功"
**************************************************/
// for(i=0;i<N;i++)
// songs[i].times=0;
void choice(struct song songs[], int n)
{
	int i, num;
	printf("请输入所选歌曲编号:");
	scanf("%d", &num);
	for (i = 0; i < n; i++)
	{
		if (songs[i].num == num)
		{
			songs[i].times += 1;
			printf("点歌成功!");
			break;
		}
	}
	if (i >= n)
		printf("\n所点的歌不存在！\n");
}
/********************************************
歌曲评价功能
输入歌曲编号和分数，此歌曲评价分数增加，显示"评价成功"。
**************************************************/
// for(i=0;i<N;i++)
// songs[i].score=0;
void appraise(struct song songs[], int n)
{
	int i, num;
	float score;
	printf("请输入所选歌曲编号:");
	scanf("%d", &num);
	for (i = 0; i < n; i++)
		if (songs[i].num == num)
		{
			printf("请输入评价分数:");
			scanf("%f", &score);
			songs[i].score += score;
			printf("评价成功!");
			break;
		}
	if (i >= n)
		printf("\n所点的歌不存在！\n");
}
/*按点唱人数从大到小排序*/
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
	printf("编号 歌曲名称 点歌次数\n");
	for (i = 0; i < n && i < 10; i++)
	{
		printf("%4d ", songs[i].num);
		printf("%10s ", songs[i].name);
		printf("%4d ", songs[i].times);
		printf("\n");
	}
}
/*按歌曲分数从大到小排序*/
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
	printf("编号 歌曲名称 评价分数\n");
	for (i = 0; i < n && i < 10; i++)
	{
		printf("%4d ", songs[i].num);
		printf("%10s ", songs[i].name);
		printf("%6.0f ", songs[i].score);
		printf("\n");
	}
}
/*******************************************************
功能:结构体数组中的歌曲信息输出到文件
参数：
参数1：songs
  类型：song []
  说明：用来存储从文件读到的歌曲信息
参数2：length
  类型：int
  说明：表示实际数组的长度
返回值：无
 *******************************************************/
void writeToFile(struct song songs[], int length)
{
	FILE *fp = NULL;
	int i = 0;

	fp = fopen(FILENAME, "wb");

	if (fp == NULL)
	{
		printf("打开文件出错！\n");
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
	/*====验证用户的口令，直到正确为止====*/
	do
	{
		printf("请输入口令：");
		scanf("%s", password);

		s = login(password);
	} while (s == 0);
	/*====根据用户的选择，执行相应的操作.====*/
	for (i = 0; i < N; i++)
		songs[i].times = 0;
	for (i = 0; i < N; i++)
		songs[i].score = 0;
	sum = readFromFile(songs);
	while (1)
	{

		scan();
		printf("\n 请选择您的操作(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15)：\n");
		scanf("%d", &choices);

		switch (choices)
		{

		case 1:
			sum = input(songs, sum);
			printf("\n现有%d个歌曲信息\n", sum);
			break;
		case 2:
			if (sum == 0)
				printf("系统中没有歌曲信息，请先初始化！\n\n");
			else
				output(songs, sum);
			break;
		case 3:
			printf("请输入欲查找的歌曲编号：\n");
			scanf("%d", &num);
			queryInfonum(songs, sum, num);
			break;
		case 4:
			printf("请输入欲查找的歌曲名：\n");
			scanf("%s", name);
			queryInfoname(songs, sum, name);
			break;
		case 5:
			printf("请输入欲查找的专辑：\n");
			scanf("%s", editor);
			queryInfoeditor(songs, sum, editor);
			break;
		case 6:
			printf("请输入欲查找的歌手：\n");
			scanf("%s", singer);
			queryInfosinger(songs, sum, singer);
			break;
		case 7:
			sum = input(songs, sum);
			printf("\n现有%d个歌曲信息\n", sum);
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