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
#include "string.h"
#define SIZE 12
#define FILENAME "information.txt"


struct IN
{
    char name[10];      /*姓名*/
    char sex[5];        /*性别*/
	int  age;			/*年龄*/
	char address[100];   /*住址*/
	int  telephone[15]; /*电话*/
	float  yue;		/*余额*/
}infor;

struct MI
{
	int month;
	float into;
	float outto;
	char inaim[20];
	char outaim[20];
}ioi[];/*日期，收入/支出  金额  收入来源/支出目的*/


void displayMenu()
 {

        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               个人收支管理系统                        +\n");
		printf("+                                                       +\n");
        printf("+                 1. 个人信息输入                       +\n");
        printf("+                 2. 添加新的收支信息                   +\n");
        printf("+                 3. 按月份排序打印出收支清单           +\n");
        printf("+                 4. 删除已有信息                       +\n");
        printf("+                 5. 修改已有信息                       +\n");
        printf("+                 6. 统计总收入                         +\n");
        printf("+                 7. 统计总支出                         +\n");
		printf("+                 8. 查询当前个人信息及余额             +\n");
	    printf("+                 9.把收支信息输入到文件                +\n");
		printf("+                 10.从文件中读入收支信息               +\n");
		printf("+                 11.把个人信息输入到文件               +\n");
		printf("+                 12.从文件中读入个人信息               +\n");
		printf("+                 13.结束程序                           +\n");
		printf("+                                                       +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
 

/*******************************************************       
功能:从文件读信息到结构体数组中
参数：
参数1：ioi[]
  类型：MI
  说明：用来存储从文件读到的收支信息
返回值：i
  类型：int
  说明：表示实际读取到的个数
 *******************************************************/
 int readFromFile1(MI ioi[])
 {
	FILE *fp=NULL;
	int i=0;

	fp=fopen(FILENAME,"rb");  /*打开文件*/

	if(fp!=NULL)
	{

		while(!feof(fp))    /*从文件中读入月份*/
		{
     
			if(fread(ioi+i,sizeof(MI),1,fp))
				i++;
		}
		printf("收支信息已读入\n");
		fclose(fp);
	}
    return i;
}





void readFromFile2(struct IN *infor)
{
	FILE *fp=NULL;
	int i=0;

	fp=fopen("personal.txt","rb");

	if(fp==NULL)
	{
		printf("打开文件出错！\n");
		exit(0);
	}
	if(!feof(fp))
		{	fread(infor,sizeof(struct IN),1,fp);
		}
	printf("个人信息已读入\n");
	fclose(fp);
}


void inputInfo1(struct IN *infor)
{
	int endFlag=0;
	printf("请输入个人信息：\n");
	while(1)
	{
	printf("姓名：");
	scanf("%s",infor->name);
	if(infor->name==0)
		{
			endFlag=1;
			break;
		}
	printf("\n");
	break;
	}
	while(1)
	{
	printf("性别：");
	scanf("%s",infor->sex);
	printf("\n");
	break;
	}
	while(1)
	{
	printf("年龄：");
	scanf("%d",&infor->age);
	printf("\n");
	break;
	}
	while(1)
	{
	printf("住址：");
	scanf("%s",infor->address);
	printf("\n");
	break;
	}
	while(1)
	{
	printf("电话：");
	scanf("%d",&infor->telephone);
	printf("\n");
	break;
	}
	while(1)
	{
	printf("余额：");
	scanf("%f",&infor->yue);
	printf("\n");
	break;
	}
	while(getchar()!='\n')
	continue;
}
/*******************************************************       
功能:判断月份是否唯一
参数：
参数1：ioi[]
  类型：MI
  说明：存储个人信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
  参数2： ioimonth
  类型：int
  说明：要判断的月份 
返回值：1或0(flag)
  类型：int
  说明：1表示月份唯一；0表示月份不唯一
 *******************************************************/
int unique(MI ioi[],int length,int ioimonth)
{
	int flag=1,i;
	for(i=0;i<length;i++)
	{
		if(ioi[i].month==ioimonth)
		{ 
			flag=0;
			break;
		}
	}
return flag;
}


 int inputInfo2(struct MI ioi[],int length)
{
	int i=length;
	int endFlag=0;

	printf("是否确认结束（以0为结束）：\n");
	while(i<SIZE)
	{
		while(1)
		{
			int flag;
			printf("月份：");
			scanf("%d",&ioi[i].month);
			if(ioi[i].month>12||ioi[i].month<0)
				printf("月份有误，请重新输入！\n");
			else if(ioi[i].month==0)
			{
				endFlag=1;
				break;
			}
			if(ioi[i].month<=12&&ioi[i].month>0)
			{
				flag=unique(ioi,i,ioi[i].month);
			    if(flag) break;
			    printf("该月份已经存在，请重新输入！\n");
			}
		}

		if(endFlag==1)
			break;
		while(1)
		{
		printf("收入：");
		scanf("%f",&ioi[i].into);
		printf("\n");
		break;
		}
		while(1)
		{
		printf("支出：");
		scanf("%f",&ioi[i].outto);
		printf("\n");
		break;
		}
		while(1)
		{
		printf("收入来源：");
		scanf("%s",ioi[i].inaim);
		printf("\n");
		break;
		}
		while(1)
		{
		printf("支出目的：");
		scanf("%s",ioi[i].outaim);
		printf("\n");
		break;
		}
		while(getchar()!='\n')
		continue;
		i++;

	}

	return i;/*新增完成后，有多少个收支信息*/
}

			   
/*******************************************************       
功能:将收支信息按月份从小到大排序(选择法)并打印
参数：
参数1：ioi
  类型：IM
  说明：用来存储收支信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
返回值：无
 *******************************************************/
void sortScore(MI ioi[],int length)
{
	int i=0,j=0,k=0;
	MI s;

	for(i=0;i<length;i++)
	{       /*  从未排好序的收支信息中找到月份最小的最小，记下标放入k */
		k=i;
		for(j=i+1;j<length;j++)
			if(ioi[j].month<ioi[k].month)
				k=j;

        /*  交换 ioi[i] and ioi[k] */
        s=ioi[k];
        ioi[k]=ioi[i];
        ioi[i]=s;
	}

}

void outputInfo(MI ioi[],int length)
{
	int i=0;

	printf("    月份           收入         支出               收入来源          支出目的\n\n");
	for(;i<length;i++)
	{
	printf("%8d   %14f   %14f   %14s   %14s",ioi[i].month,ioi[i].into,ioi[i].outto,ioi[i].inaim,ioi[i].outaim);
	printf("\n");
	}
	printf("\n\n");
}

/*******************************************************       
功能:根据月份删除数组中收支信息
参数：
参数1：ioi
  类型：IM
  说明：用来存储收支信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
参数3：stuNum
  类型：int
  说明：表示要删除的月份
返回值：length
		删除后月份的个数        
 *******************************************************/
int deleteInfoByNumber(MI ioi[],int length,int stuNum)
{
	int i,j;
	char choice;
	for(i=0;i<length;i++)
	{
		if(stuNum==ioi[i].month)
       {
			printf("找到啦!它的下标是:%d\n", i);

			printf("%d %f %f %s %s","月份",      "收入",     "支出",      "收入来源",      "支出目的\n");
			printf("%d %5f %5f %5s %5s\n",ioi[i].month,ioi[i].into,ioi[i].outto,ioi[i].inaim,ioi[i].outaim);		
			break; 
		}
    }
    if(i<length)
	{
 		printf("你确实要删除这个月的收支信息吗?(Y/N)");
		getchar();
		scanf("%c",&choice);
		if(choice=='Y'||choice=='y')
		{
			for(j=i;j<length;j++)
				ioi[j]=ioi[j+1];
			length--;
 	 	    printf("删除成功!\n");
		}                
	}
    else
        printf("\n指定的月份收支信息不存在!\n");
	return length;
}








/******************************************************* 
功能:根据月份修改数组中信息
参数：
参数1：ioi
  类型：MI
  说明：用来存储收支信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
参数3：stuNum
  类型：int
  说明：表示要修改的信息的月份
返回值：无
 *******************************************************/
void editInfoByNumber(MI ioi[],int length,int stuNum)
{
	int i=0;
	int choice,flag;
	for(i=0;i<length;i++)
	{
		if(stuNum==ioi[i].month)
       {
			printf("找到啦!它的下标是:%d\n", i);
			printf("%d %f %f %s %s","  月份",       "收入",    "支出",      "收入来源",     "支出目的\n");
			printf("%d %f %f %s %s\n",ioi[i].month,ioi[i].into,ioi[i].outto,ioi[i].inaim,ioi[i].outaim);		
			do{
 				printf("\n");
				printf("***********************\n");
				printf("   1:月份\n");
				printf("   2:收入\n");
				printf("   3:支出\n");
				printf("   4:收入来源\n");
				printf("   5:支出目的\n");
				printf("***********************\n");          
				printf("请输入欲修改的字段(0退出):");
				scanf("%d",&choice);
				switch(choice)
				{ case 1: 
					   printf("请输入月份:");
					   scanf("%d",&stuNum);
					   flag=unique(ioi,length,stuNum);
					   if(!flag)
						   printf("该月份已经存在!\n");
					   else
					   {   ioi[i].month=stuNum;
						   printf("修改成功\n");
					   } 
					   break;
				   case 2: 
					   printf("请输入收入:");
					   scanf("%f",ioi[i].into);
					   printf("修改成功\n");
					   break;
				   case 3: 
					   printf("请输入支出:");
					   scanf("%f",&ioi[i].outto);
					   printf("修改成功\n");
					   break;
				   case 4: 
					   printf("请输入收入来源:");
					   scanf("%s",ioi[i].inaim);
					   printf("修改成功\n");
					   break;
				   case 5: 
					   printf("请输入支出目的:");
					   scanf("%s",ioi[i].outaim);
					   printf("修改成功\n");
					   break;
				   case 0: 
					   break;
				}                
			}while(choice!=0);
			break; 
		}
    }
    if(i>=length)
        printf("\n指定的月份不存在!\n");
}
   
float WorkSumInto(MI ioi[],int length)
{
	int m;
	float suminto=0.0;
	for(m=0;m<length;m++)
	suminto=suminto+ioi[m].into;
	printf("目前总收入为%f\n",suminto);

	return suminto;
}

float WorkSumOutto(MI ioi[],int length)
{
	int i,m;
	float sumoutto=0.0;
	i=length;
	for(m=0;m<i;m++)
	sumoutto=sumoutto+ioi[m].outto;
	printf("目前总支出为%f\n",sumoutto);
	return sumoutto;
}

void Inputinformation(struct IN infor,struct MI ioi[],int length)
{
	float sum=0.0,i=0.0,j=0.0;
	i=WorkSumOutto(ioi,length);
	j=WorkSumInto(ioi,length);
	sum=infor.yue-i+j;
	printf("姓名； 性别； 年龄； 住址； 电话； 余额； \n");
	printf("%2s %5s %5d %5s %5d %5f\n",infor.name,infor.sex,infor.age,infor.address,infor.telephone,sum);
}




void writeToFile2(struct IN infor)
{
	FILE *fp=NULL;
	int i=0;

	fp=fopen("personal.txt","wb");

	if(fp==NULL)
	{
		printf("打开文件出错！\n");
		exit(0);
	}
	fwrite(&infor,sizeof(struct IN),1,fp);
	printf("信息已保存到文件personal.txt中\n");
	fclose(fp);
}







/*******************************************************       
功能:结构体数组中的收支信息输出到文件
参数：
参数1：ioi[]
  类型：MI
  说明：用来存储从文件读到的学生信息
参数2：length
  类型：int
  说明：表示实际数组的长度 
返回值：无
 *******************************************************/

void writeToFile1(MI ioi[],int length)
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
		fwrite(ioi+i,sizeof(MI),1,fp);
	printf("信息已保存到文件information.txt中\n");
	fclose(fp);

}



void main()
{

    struct IN infor;
	struct MI ioi[SIZE];
	int choice = 0; /*select and store menu item  */
    int s=0,arrayLength=0,ioiy=0,ioix=0;

    /*====根据用户的选择，执行相应的操作.====*/
    while(1)
    {

		displayMenu();

		printf("\n 请选择您的操作(1,2,3,4,5,6,7,8,9,10,11,12,13)\n");
        scanf("%d",&choice);

		switch(choice)
        {

			case 1:
				printf("系统中没有个人信息，请先初始化！\n\n");
				inputInfo1(&infor);
				break;
			case 2:
				arrayLength=inputInfo2(ioi,arrayLength);
				if(arrayLength==0)
				printf("系统中没有收支信息，请先初始化！\n\n");
				arrayLength=inputInfo2(ioi,arrayLength);
				printf("\n现有%d个月收支信息\n",arrayLength);
				break;
			case 3:
				sortScore(ioi,arrayLength);
				outputInfo(ioi,arrayLength);
				break;
			case 4:
				printf("请输入欲删除月份：\n");
				scanf("%d",&ioiy);
				deleteInfoByNumber(ioi,arrayLength,ioiy);
				break;
			case 5:
				printf("请输入欲修改月份：\n");
				scanf("%d",&ioix);
				editInfoByNumber(ioi,arrayLength,ioix);
				break;
			case 6:
				WorkSumInto(ioi,arrayLength);
				break;
			case 7:
				WorkSumOutto(ioi,arrayLength);
				break;
			case 8:
				Inputinformation(infor,ioi,arrayLength);
				break;
			case 9:
				writeToFile1(ioi,arrayLength);
				break;
			case 10:
				arrayLength=readFromFile1(ioi);
				break;
			case 11:
				writeToFile2(infor);
				break;
			case 12:
				readFromFile2(&infor);
				break;
			case 13:
				exit(0);
				break;	
		}
	}
}

