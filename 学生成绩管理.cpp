/***********************************************************
我的信息:                                                  *
  姓名: 汪建林		生日:1985年2月26日                     *
  毕业学校: 2007年于成都理工大学                           *
  家乡地址: 四川渠县望溪乡包山村5组                        *
  联系QQ1: 287307421  QQ2: 254540457  QQ3:344245001        *
  联系Email: wangjianlin1985@126.com 13908064703           *
  淘宝新店地址： http://taochengxu.taobao.com              *
  双鱼林程序拍拍专卖店: http://287307421.paipai.com        *
  网站: http://www.shuangyulin.com 【长期有效】            *
***********************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#define N 10
#define FILENAME "student.txt"
typedef struct
{
    int num1;         
    char name1[10];      
    int fen;
}LESSON;

typedef struct
{
	int num2;      /*学号*/
	char name2[10];/*姓名*/
	char xing[10];
	int num3;
	int tele;
	float score[3];
	float zong;
	float fen2;
}STUDENT;



/*******************************************************       
功能:显示菜单
参数：无   
返回值：无
 *******************************************************/
 void displayMenu()
 {

        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               学生成绩管理系统2.0                     +\n");
		printf("+                                                       +\n");
        printf("+                 1. 输入课程信息                       +\n");
        printf("+                 2. 输入学生信息成绩                   +\n");
        printf("+                 3. 学生基本情况查询                   +\n");
        printf("+                 4. 成绩查询                           +\n");
        printf("+                 5. 删除信息                           +\n");
        printf("+   6. 按综合成绩或实得学分升序或降序排序并显示数据     +\n");
        printf("+                 7. 程序结束                           +\n");
		printf("+                                                       +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

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
     static char LESSONy[10]="123";
     if(strcmp(password,LESSONy)==0)
       return 1;
     else
       return 0;
 }

 
 int readFromFile2(LESSON lesson[])
 {
	FILE *fp=NULL;
	int i=0;

	fp=fopen("student2","rb"); 

	if(fp!=NULL)
	{

		while(!feof(fp)) 
		{
     
			if(i>=N)
				break;
			if(fread(lesson+i,sizeof(LESSON),1,fp))
				i++;
		}

		fclose(fp);
	}
    return i;
}

  /*******************************************************       
功能:从文件读信息到结构体数组中
参数：
参数1：student[]
  类型：STUDENT []
  说明：用来存储从文件读到的学生信息
返回值：i
  类型：int
  说明：表示实际读取到的个数
 *******************************************************/
 int readFromFile(STUDENT student[])
 {
	FILE *fp=NULL;
	int i=0;

	fp=fopen(FILENAME,"rb"); 

	if(fp!=NULL)
	{

		while(!feof(fp)) 
		{
     
			if(i>=N)
				break;
			if(fread(student+i,sizeof(STUDENT),1,fp))
				i++;
		}

		fclose(fp);
	}
    return i;
}

/*******************************************************       
功能:判断学号是否唯一
参数：
参数1：student[]
  类型：STUDENT []
  说明：存储学生信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
参数2：stuNumber
  类型：int
  说明：要判断的学号 
返回值：1或0(flag)
  类型：int
  说明：1表示学号唯一；0表示学号不唯一
 *******************************************************/

int unique(STUDENT student[],int length,int stuNumber)
{
	int flag=1,i;
	for(i=0;i<length;i++)
	{
		if(student[i].num2==stuNumber)
		{ 
			flag=0;
			break;
		}
	}
return flag;
}
void inputInfo1(LESSON *lesson)
{
	printf("请输入课程信息：\n");
	printf("课程编号：");
	scanf("%d",&lesson->num1);
	printf("课程名称：");
	scanf("%s",lesson->name1);
	printf("学分：");
	scanf("%d",&lesson->fen);
}
int inputInfo2(STUDENT student[],int length)
{
	int i=length;
	int endFlag=0;

	printf("请输入学生信息（以学号为0结束）：\n");
	while(i<N)
	{
		while(1)
		{
			int flag;
			printf("学号：");
			scanf("%d",&student[i].num2);
			if(student[i].num2==0)
			{
				endFlag=1;
				break;
			}
			flag=unique(student,i,student[i].num2);
			if(flag) break;
			printf("该学号已经存在，请重新输入！\n");
		}
		if(endFlag==1)
			break;
		printf("姓名：");
		scanf("%s",student[i].name2);
		printf(" 性别：");
		scanf("%s",student[i].xing);
		while(1)
		{
			printf("宿舍号码：");
			if(scanf("%d",&student[i].num3)==1)
				break;
			printf("输入格式不对，请重新输入！\n");
			while(getchar()!='\n')
				continue;
		}
		while(1)
		{
			printf("电话号码：");
			if(scanf("%d",&student[i].tele)==1)
				break;
			printf("输入格式不对，请重新输入！\n");
			while(getchar()!='\n')
				continue;
		}
		while(1)
		{
			printf("平时成绩：");
			if(scanf("%f",&student[i].score[1])==1)
				break;
			printf("输入格式不对，请重新输入！\n");
			while(getchar()!='\n')
				continue;
		}
		while(1)
		{
			printf("实验成绩：");
			if(scanf("%f",&student[i].score[2])==1)
				break;
			printf("输入格式不对，请重新输入！\n");
			while(getchar()!='\n')
				continue;
		}
        while(1)
		{
			printf("卷面成绩：");
			if(scanf("%f",&student[i].score[3])==1)
				break;
			printf("输入格式不对，请重新输入！\n");
			while(getchar()!='\n')
				continue;
		}

		while(getchar()!='\n')
			continue;
		i++;

	}

	return i;
}
/*输入一个学号，查出此生的基本信息并显示输出*/
void xuehao(STUDENT student[],int length,int stuNum2)
{
	int i=0;
	for(i=0;i<length;i++)
	{
	if(stuNum2==student[i].num2)
	{     
	      printf("找到啦！他的基本信息是 :%d\n", i);
          printf("%-4s %-4s %-4s %-8s %-8s %-10s %-8s %-8s","学号","姓名","性别","宿舍号码","电话号码","平时成绩","实验成绩","卷面成绩","综合成绩","实得学分");
	      printf("\n%-4d %-4s %-4s %-8d %-8d %-4f %-3f %-3f %-8f %-8f\n",student[i].num2,student[i].name2,student[i].xing,student[i].num3,student[i].tele,student[i].score[1],student[i].score[2],student[i].score[3],student[i].zong,student[i].fen2);
	break;
        }
    }
    if(i>=length)
        printf("\n不存在！\n");
}
/*输入一个姓名，查出此生的基本信息并显示输出。*/
void name(STUDENT student[],int length,char stuname2[])
{
	int i=0;
	for(i=0;i<length;i++)
	{

		if(strcmp(stuname2,student[i].name2)==0)

        {
		printf("找到啦！他的基本信息是 :%d\n", i);
	printf("%-4s %-4s %-4s %-8s %-8s %-10s %-8s %-8s","学号","姓名","性别","宿舍号码","电话号码","平时成绩","实验成绩","卷面成绩","综合成绩","实得学分");
	printf("\n%-4d %-4s %-4s %-8d %-8d %-4f %-3f %-3f %-8f %-8f\n",student[i].num2,student[i].name2,student[i].xing,student[i].num3,student[i].tele,student[i].score[1],student[i].score[2],student[i].score[3],student[i].zong,student[i].fen2);
	break;
        }
    }
    if(i>=length)
        printf("\n不存在！\n");
}
/*输入一个宿舍号码，可查询出本室所有的学生的基本信息并显示输出。*/
void suse(STUDENT student[],int length,int stuNum3)
{
	int i=0;
	for(i=0;i<length;i++)
	{
	if(stuNum3==student[i].num3)
        {
	printf("找到啦！他们的基本信息是 :%d\n", i);
    printf("%-4s %-4s %-4s %-8s %-8s %-10s %-8s %-8s","学号","姓名","性别","宿舍号码","电话号码","平时成绩","实验成绩","卷面成绩","综合成绩","实得学分");
	printf("\n%-4d %-4s %-4s %-8d %-8d %-4f %-3f %-3f %-8f %-8f\n",student[i].num2,student[i].name2,student[i].xing,student[i].num3,student[i].tele,student[i].score[1],student[i].score[2],student[i].score[3],student[i].zong,student[i].fen2);
	break;
        }
    }
    if(i>=length)
        printf("\n不存在！\n");
}
/*输入一个学号时，查询出此生的成绩和学分情况*/
void searchNum(STUDENT student[],int length)         //查询
{
 int num2,i;
 printf("\n\t请输入要查询的学号:\n\n\t");
 scanf("%d",&num2);
 printf("\n");
 for(i=0;i<length;i++)
 {
  if(num2==student[i].num2)
   break;
 }
 if(i<length)
 {
  printf("\t学分\t成绩\n\n");
  printf("\t%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n\n\t",student[i].num2,student[i].name2,student[i].score[1],student[i].score[2],student[i].score[3],student[i].zong,student[i].fen2);
 }
 else
  printf("\t该学号不存在\n\n\t");
} 
/**/
void turm(STUDENT student[],int length)
{	int choice,i,j;
    float term;
	printf("按综合成绩排序选择1，按实得学分排序选择2");
	for(i=0;i<length;i++)
	{
	if(student[i].zong>100&&student[i].zong<0);
	else if(student[i].zong>=90&&student[i].zong<=100) student[i].fen2=student[i].zong;
	else if(student[i].zong>=80) student[i].fen2=(float)(student[i].zong*0.8);
	else if(student[i].zong>=70) student[i].fen2=(float)(student[i].zong*0.75);
	else if(student[i].zong>=60) student[i].fen2=(float)(student[i].zong*0.6);
	else  student[i].fen2=0;


	}
	scanf("%d",&choice);
	switch(choice)
	{
		/*按综合成绩降序排序并显示数据。*/
	case 1:
	{
		for(j=0;j<length;j++)
		for(i=0;i<length-j;i++)
		{
			if(student[i].zong<student[i+1].zong)
			{
			term=student[i].zong;
			student[i].zong=student[i+1].zong;
			student[i+1].zong=term;
			}
		}
	




	}
	break;
	/*按得学分降序排序并显示数据。*/
	case 2:
	{
		for(j=0;j<length;j++)
		for(i=0;i<length-j;i++)
		{
			if(student[i].fen2<student[i+1].fen2)
			{
			term=student[i].zong;
			student[i].fen2=student[i+1].fen2;
			student[i+1].fen2=term;
			}
		}	
	}break;
	}
}
/*打印*/
void outputInfo(STUDENT student[],int length)
{
	int i=0;
    printf("%-4s %-4s %-4s %-8s %-8s %-10s %-8s %-8s","学号","姓名","性别","宿舍号码","电话号码","平时成绩","实验成绩","卷面成绩","综合成绩","实得学分");
	for(i=0;i<length;i++)
	{
	printf("\n%-4d %-4s %-4s %-8d %-8d %-4f %-3f %-3f %-8f %-8f\n",student[i].num2,student[i].name2,student[i].xing,student[i].num3,student[i].tele,student[i].score[1],student[i].score[2],student[i].score[3],student[i].zong,student[i].fen2);
	printf("\n");
	}
	printf("\n\n");
}
 /*******************************************************       
  功能:主函数
  参数：无   
  返回值：无
 *******************************************************/

main()
{
	STUDENT student[N];
	LESSON LESSON[3];
    int choice=0,choice2=0; /*select and store menu item  */
    int s=0,arrayLength=0,stuNum2,stuNum3;
    char password[10],stuname2[10];

    /*====验证用户的口令，直到正确为止====*/
	do{
		printf("请输入口令：");
		scanf("%s",password);

		s=login(password);
     }while(s==0);

	arrayLength=readFromFile(student);

    /*====根据用户的选择，执行相应的操作.====*/
    while(1)
    {

		displayMenu();

		printf("\n 请选择您的操作(1,2,3,4,5,6,7,8)：\n");
        scanf("%d",&choice);

		switch(choice)
        {

			case 1:
				inputInfo1(LESSON);
				break;

			case 2:
				arrayLength=inputInfo2(student,arrayLength);
				printf("\n现有%d个学生信息\n",arrayLength);
				break;
			case 3:
                printf("请选择：\n");
                printf("1:根据学号查找\n");
                printf("2:根据姓名查找\n");
                printf("3:根据宿舍号码查找\n");
                scanf("%d",&choice2);
                switch(choice2)
				{
                   case 1:
                   printf("请输入欲查找的学号：\n");
                   scanf("%d",&stuNum2);
                   xuehao(student,arrayLength,stuNum2);
		           break;
                   case 2:
                   printf("请输入欲查找的姓名：\n");
                   scanf("%s",&stuname2);
                   name(student,arrayLength,stuname2);
		           break;
                   case 3:
                   printf("请输入欲查找的宿舍号码查找\n");
                   scanf("%d",& stuNum3);
                   suse(student,arrayLength, stuNum3);
		           break;
				}
			case 4:
				searchNum(student,arrayLength);
				break;
            case 5:
			
            case 6:
				turm(student,arrayLength);
				outputInfo(student,arrayLength);
				break;
			case 7:
				exit(0);
				break;
				
        }
    }

}