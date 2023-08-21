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
#define FILENAME "zhigong.txt"
typedef struct
{
    int num;         /*职工编号*/
    char n1[10];     /*职工名称*/
	char n2[10];     /*性别*/
	int nianling;    /*年龄*/
	char xueli[20];  /*学历*/
    int gongzi;      /*工资*/
    char addr[10];       /*住址*/
    int tele;        /*电话*/
}GONG;
void displayMenu()
 {

        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               职工资源管理系统                                  +\n");
		printf("+                                                                 +\n");
        printf("+            1. 录入职工信息                                      +\n");
        printf("+            2. 显示全部职工信息                                  +\n");
        printf("+            3. 根据工号查询                                      +\n");
        printf("+            4. 根据学历查询                                      +\n");
		printf("+            5. 根据工资查询                                      +\n");
        printf("+            6. 根据工号删除记录                                  +\n");
        printf("+            7. 根据工资从大到小排                                +\n");
        printf("+            8. 保存并结束                                        +\n");
		printf("+                                                                 +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

 }
int login(char password[])
 {
     static char key[10]="123";
     if(strcmp(password,key)==0)
       return 1;
     else
       return 0;
  }
int readFromFile(GONG gong[])
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
			if(fread(gong+i,sizeof(GONG),1,fp))
				i++;
		}

		fclose(fp);
	}
    return i;
}
int unique(GONG gong[],int length,int JN)
{
	int flag=1,i;
	for(i=0;i<length;i++)
	{
		if(gong[i].num==JN)
		{ 
			flag=0;
			break;
		}
	}
return flag;
}
/*输入职工信息记录*/
int inputInfo(GONG gong[],int length)
{
	int i=length;
	int endFlag=0;
	printf("请输入职工信息（以为编号0结束）：\n");
	while(i<N)
	{
		while(1)
		{
			int flag;
			printf("职工编号：");
			scanf("%d",&gong[i].num);
			if(gong[i].num==0)
			{
				endFlag=1;
				break;
			}
			flag=unique(gong,i,gong[i].num);
			if(flag) break;
			printf("该职工已经存在，请重新输入！\n");
		}
		if(endFlag==1)
			break;
		printf("职工名称：");
		scanf("%s",gong[i].n1);
		printf("性别：");
		scanf("%s",gong[i].n2);
		while(1)
		{
			printf("年龄：");
			if(scanf("%d",&gong[i].nianling)==1)
				break;
			printf("输入格式不对，请重新输入！\n");
			while(getchar()!='\n')
				continue;
		}
       	printf("学历：");
		scanf("%s",gong[i].xueli);
        while(1)
		{
			printf("工资：");
			if(scanf("%d",&gong[i].gongzi)==1)
				break;
			printf("输入格式不对，请重新输入！\n");
			while(getchar()!='\n')
				continue;
		}
		printf("住址：");
		scanf("%s",gong[i].addr);
		while(1)
		{
			printf("电话：");
			if(scanf("%d",&gong[i].tele)==1)
				break;
			printf("输入格式不对，请重新输入！\n");
			while(getchar()!='\n')
				continue;
		}

i++;
	
}
return i;
}
/*显示全部职工信息*/
void outputInfo(GONG gong[],int length)
{
	int i=0;

	printf("%-8s %-8s %-4s %-4s %-4s %-4s %-4s %-4s","职工编号","职工名称","性别","年龄","学历","工资","住址","电话\n\n");
	for(i=0;i<length;i++)
	{
		printf("%-8d %-8s %-4s %-4d %-4s %-4d %-4s %-4d",gong[i].num,gong[i].n1,gong[i].n2,gong[i].nianling,gong[i].xueli,gong[i].gongzi,gong[i].addr,gong[i].tele);
	    printf("\n");
	}
	printf("\n\n");
}
/*根据工号查询信息*/
void ghInfo(GONG gong[],int length,int gh)
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if(gh==gong[i].num)
        {
			printf("找到啦！他的信息是:%d\n", i);
		    printf("%-8s %-8s %-4s %-4s %-4s %-4s %-4s %-4s","职工编号","职工名称","性别","年龄","学历","工资","住址","电话\n\n");
		    printf("%-8d %-8s %-4s %-4d %-4s %-4d %-4s %-4d",gong[i].num,gong[i].n1,gong[i].n2,gong[i].nianling,gong[i].xueli,gong[i].gongzi,gong[i].addr,gong[i].tele);
		    break;
        }
    }
    if(i>=length)
    printf("\n不存在！\n");
}
/*根据按学历查询信息*/
void xlInfo(GONG gong[],int length,char xl[])
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if(strcmp(xl,gong[i].xueli)==0)
        {
			printf("找到啦！他的信息是:%d\n", i);
		    printf("%-8s %-8s %-4s %-4s %-4s %-4s %-4s %-4s","职工编号","职工名称","性别","年龄","学历","工资","住址","电话\n\n");
		    printf("%-8d %-8s %-4s %-4d %-4s %-4d %-4s %-4d",gong[i].num,gong[i].n1,gong[i].n2,gong[i].nianling,gong[i].xueli,gong[i].gongzi,gong[i].addr,gong[i].tele);
        }
    }
    if(i>=length)
    printf("\n不存在！\n");
}
/*根据工资查询信息*/
void gzInfo(GONG gong[],int length,int gz)
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if(gz==gong[i].gongzi)
        {
			printf("找到啦！他的信息是:%d\n", i);
		    printf("%-8s %-8s %-4s %-4s %-4s %-4s %-4s %-4s","职工编号","职工名称","性别","年龄","学历","工资","住址","电话\n\n");
		    printf("%-8d %-8s %-4s %-4d %-4s %-4d %-4s %-4d",gong[i].num,gong[i].n1,gong[i].n2,gong[i].nianling,gong[i].xueli,gong[i].gongzi,gong[i].addr,gong[i].tele);
        }
    }
    if(i>=length)
    printf("\n不存在！\n");
}
/*根据工号删除记录*/
int shanchu(GONG gong[],int length,int gh)
{
	int i,j=0;
	for(i=0;i<length;i++)
	{
		if(gh==gong[i].num)
		{
			length=length-1;
			for(j=i;j<length;j++)
			{
				gong[j].num=gong[j+1].num;
				strcpy(gong[j].n1,gong[j+1].n1);
		        strcpy(gong[j].n2,gong[j+1].n2);
				gong[j].nianling=gong[j+1].nianling;
				strcpy(gong[j].xueli,gong[j+1].xueli);
				gong[j].gongzi=gong[j+1].gongzi;
				strcpy(gong[j].addr,gong[j+1].addr);
				gong[j].tele=gong[j+1].tele;				
			}
			i--;
		}
	}
	return length;
}

/*根据工资从大到小排序*/
void sortScore(GONG gong[],int length)
{
	int i=0,j=0,k=0;
	GONG s;
	for(i=0;i<length;i++)
	{
		k=i;
		for(j=i+1;j<length;j++)
			if(gong[j].gongzi>gong[k].gongzi)
				k=j;
        s=gong[k];
        gong[k]=gong[i];
        gong[i]=s;
	}
    printf("%-8s %-8s %-4s %-4s %-4s %-4s %-4s %-4s","职工编号","职工名称","性别","年龄","学历","工资","住址","电话\n\n");
	for(i=0;i<length;i++)
	{
		printf("%-8d %-8s %-4s %-4d %-4s %-4d %-4s %-4d",gong[i].num,gong[i].n1,gong[i].n2,gong[i].nianling,gong[i].xueli,gong[i].gongzi,gong[i].addr,gong[i].tele);
	    printf("\n");
	}
	printf("\n\n");
}
void writeToFile(GONG gong[],int length)
{
	FILE *fp=NULL;
	int i=0;

	fp=fopen(FILENAME,"wb");

	if(fp==NULL)
	{
		printf("打开文件出错！\n");
		exit(0);
	}

	for(i=0;i<length;i++)
		fwrite(gong+i,sizeof(GONG),1,fp);

	fclose(fp);

}

main()
{
	GONG gong[N];

    int choice = 0;
    int s=0,arrayLength=0,gh,gz;
    char password[10];
    char xl[10];
	

    /*====验证用户的口令，直到正确为止====*/
	do{
		printf("请输入口令：");
		scanf("%s",password);

		s=login(password);
     }while(s==0);

	arrayLength=readFromFile(gong);

    /*====根据用户的选择，执行相应的操作.====*/
    while(1)
    {

		displayMenu();

		printf("\n 请选择您的操作(1,2,3,4,5,6,7,8)：\n");
        scanf("%d",&choice);

		switch(choice)
        {

			case 1:
				arrayLength=inputInfo(gong,arrayLength);
				printf("\n现有%d个职工信息\n",arrayLength);
				break;

			case 2:
				if(arrayLength==0)
				printf("系统中没有职工信息，请先初始化！\n\n");
				else
				outputInfo(gong,arrayLength);
				break;
  
			case 3:
				printf("请输入欲查找的职工编号：\n");
				scanf("%d",&gh);
				ghInfo(gong,arrayLength,gh);
				break;
 
			case 4:
				printf("请输入欲查找的学历：\n");
				scanf("%s",&xl);
				xlInfo(gong,arrayLength,xl);
				break;
            case 5:
				printf("请输入欲查找的工资：\n");
				scanf("%d",&gz);
				gzInfo(gong,arrayLength,gz);
				break;
            case 6:
				printf("请输入欲删除的职工编号：\n");
                scanf("%d",&gh);
				shanchu(gong,arrayLength,gh);
				break;
			case 7:
				sortScore(gong,arrayLength);
				break;
            case 8:
				writeToFile(gong,arrayLength);
				exit(0);
				break;
        }
    }

}
