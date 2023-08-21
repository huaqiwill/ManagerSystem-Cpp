/** File KTVSystem.cpp KTV歌曲系统
 * 项目地址：
 * CSDN博客：https://blog.csdn.net/HuaQi666
 * 开发者：http://bingbingfuhao.cn
 * 邮箱：3173484026@qq.com
 * 创建时间: 2023/8/21
 */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define FILENAME "worker.bin"
#define N 20
struct worker
{
    int number;         /*工号*/
    char name[10];      /*姓名*/
	char sex;          /*性别*/
    int age;          /*年龄*/
	int cult;          /*学历*/
	int income;      /*工资*/
	char address[20];     /*住址*/ 
	int phone;       /*电话*/
	int counts;      /*数量*/
	int grade;       /*等级*/

};
/*******************************************************       
             定义
 *******************************************************/
 void xinxi()
 {

        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               职工工作量统计系统2.0                     +\n");
		printf("+                                                         +\n");
        printf("+                 1. 职工基本信息输入                     +\n");
        printf("+                 2. 输出信息                             +\n");
        printf("+                 3. 工作量输入                           +\n");
        printf("+                 4. 按工作量排序 打印出职工名次          +\n");
        printf("+                 5. 按职工工号查询                       +\n");
		printf("+                 6. 按职工姓名查询                       +\n");
        printf("+                 7. 按职工工号进行信息删除               +\n");
        printf("+                 8. 程序结束                             +\n");
		printf("+                                                         +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

 } 
/*******************************************************       
                    显示菜单
 *******************************************************/
int readFromFile(struct worker w[])
 {
	FILE *fp=NULL;
	int i=0;

	fp=fopen(FILENAME,"rb");  /*打开文件*/

	if(fp!=NULL)
	{

		while(!feof(fp))    /*从文件中读入学生*/
		{
     
			if(i>=N)
				break;
			if(fread(w+i,sizeof(worker),1,fp)==1)
				i++;
		}

		fclose(fp);
	}
    return i;
}
/*******************************************************       
                从文件读信息到结构体数组中
 *******************************************************/
void output(struct worker w[],int length)
{
	int i=0;
	if(length==0)
	{
		printf("系统中没有职工信息，请先初始化!\n\n");
		return;
	}
	printf("%s %s %s %s %s %s   %s   %s","职工号","姓名","性别","年龄","学历","工资","住址","电话");
	for(i=0;i<length;i++)
	{
		printf("\n  %d  %5s %5c %5d %3d %5d  %5s %5d\n",w[i].number,w[i].name,w[i].sex,w[i].age,w[i].cult,w[i].income,w[i].address,w[i].phone);
		printf("\n");
	}
}
/*******************************************************       
                信息显示到屏幕
 *******************************************************/
 int f(struct worker w[],int length)
{
	
	 int i=length;
	 while(i<N)
	 {
		  printf("第%d个职工\n",i);
		  printf("\n");
		  printf("请你输入工号(以职工号为0结束):\n");/*输入工号*/
		  scanf("%d",&w[i].number);
		  if(w[i].number==0)
			  break;
		  printf("\n");
		  printf("\n");
		  printf("请你输入姓名:\n");/*输入姓名*/
		  scanf("%s",w[i].name);
		  printf("\n");
		  printf("请你输入性别以m为男f为女:\n");/*输入性别*/
		  scanf("%s",&w[i].sex);
		  printf("\n");
		  printf("请你输入学历:\n");/*输入学历*/
		  printf("1为大专2为本科3为其他\n");
		  scanf("%d",&w[i].cult);
		  printf("\n");
          printf("请你输入年龄:\n");/*输入年龄*/
		  scanf("%d",&w[i].age);
		  printf("\n"); 
          printf("请你输入工资:\n");/*输入工资*/
		  scanf("%d",&w[i].income);
		  printf("\n"); 
		  printf("请你输入住址:\n");/*输入地址*/
		  scanf("%s",w[i].address);
		  printf("\n"); 
          printf("请你输入电话:\n");/*输入电话*/
		  scanf("%d",&w[i].phone);
		  printf("\n"); 
          printf("请你输入数量:\n");/*输入数量*/
		  scanf("%d",&w[i].counts);
		  printf("\n"); 
		  i++;
	 }
	
 	 return i;
	 }
 
/*******************************************************       
      功能:输入职工基本信息  
 *******************************************************/
 void input(struct worker w[],int length)
 {
     int i=1;
	 int number,counts;
     printf("请输入工号:");
	 scanf("%d",&number);  
     while(number!=0)
	 {  
		printf("请输入完成数量:\n");
		scanf("%d",&counts);
		 for(i=0;i<length;i++)
			if(w[i].number==number)
			{
				w[i].counts+=counts;
                break;
			}
		if(i>=length) 
			printf("工号不存在:\n");
		printf("请输入工号:");
		scanf("%d",&number);  
	 }
}
/*******************************************************       
      功能:工作量输入并累加 
 *******************************************************/
void sortCounts(struct worker w[],int length)
{
	int i=0,j=0,k=0;
	struct worker s;
	for(i=0;i<length;i++)
	{      
		k=i;
		for(j=i+1;j<length;j++)
			if(w[j].counts>w[k].counts)
				k=j;
        /*  交换 w[i] and w[k] */
        s = w[k];
        w[k] =w[i];
        w[i] = s;
    }
	if(length>0)
		w[0].grade =1;
	for(i=1;i<length;i++)
		if(w[i].counts==w[i-1].counts)
			w[i].grade=w[i-1].grade;
		else
			w[i].grade=w[i-1].grade+1;  
 

}

////////////////////////////////////////////////////////////////////////////////
                     /* 按工作量从大到小排序并标上名次 */
////////////////////////////////////////////////////////////////////////////////
void sortNumber(struct worker w[],int length)
{
	int i=0;
	int grade,count;
    if(length>0)
	{   while(i<length)
		{      
		   count=0;
		   grade=w[i].grade;
		   printf("名次:%d ", grade);
		   printf(" 工作量:%d\n",w[i].counts);
		   printf("%s %s","工号","姓名\n");
		   while(i<length)
		   {
			  if(grade==w[i].grade)
			  {
				  printf("%2d %6s\n",w[i].number,w[i].name);
				  count++;
			  }
			  else
				break;
			  i++;
           } 
		   printf("人数:%d\n",count);		
		}
	}
	else
		printf("职工数据不存在!\n");


}
////////////////////////////////////////////////////////////////////////////////
       /* 打印出职工名次输出名次、同一名次的职工人数及他们的工号，姓名*/
////////////////////////////////////////////////////////////////////////////////
void queryInfo(struct worker w[],int length,int stuNum)
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if(stuNum==w[i].number)
        {
			printf("找到啦!它的下标是:%d\n", i);
		    printf("%s %s %s %s %s %s   %s   %s","职工号","姓名","性别","年龄","学历","工资","住址","电话");
		    printf("\n  %d  %5s %5c %5d %3d %5d  %5s %5d\n",w[i].number,w[i].name,w[i].sex,w[i].age,w[i].cult,w[i].income,w[i].address,w[i].phone);
			break;
		}	 
	}
    if(i>=length)
        printf("\n输入有误！\n");
}


 /*******************************************************       
              按职工工号查询
 *******************************************************/
void cha(struct worker w[],int length,char stuName[])
{
	int i=0;
    int found=0;
	for(i=0;i<length;i++)
	{
		if(strcmp(stuName,w[i].name)==0)
        {   found++;
		    if(found==1)
			{
				printf("找到啦\n");
				printf("%s %s %s %s %s %s   %s   %s","职工号","姓名","性别","年龄","学历","工资","住址","电话");
			}
		        printf("\n  %d %5s %5c %5d %3d %5d  %5s %5d\n",w[i].number,w[i].name,w[i].sex,w[i].age,w[i].cult,w[i].income,w[i].address,w[i].phone);
		}
	 }
	 if(found==0)
		 printf("没有这样的人\n");
}
/***********************************************************
                   按职工姓名查询
***********************************************************/
int delet(struct worker w[],int length,int stuNum)
{
	int i,j;
	char choice;
	for(i=0;i<length;i++)
	{
		if(stuNum==w[i].number)
       {
			printf("下标是:%d", i);
		    printf("%s %s %s %s %s %s   %s   %s","职工号","姓名","性别","年龄","学历","工资","住址","电话");
		    printf("\n  %d %5s %5c %5d %3d %5d  %5s %5d\n",w[i].number,w[i].name,w[i].sex,w[i].age,w[i].cult,w[i].income,w[i].address,w[i].phone);	
			break; 
		}
    }
    if(i<length)
	{
 		printf("你确实要删除这个职工吗?(Y/N)");
		scanf("%c",&choice);
		if(choice=='Y'||choice=='y')
		{
			for(j=i;j<length;j++)
				w[j]=w[j+1];
			length--;
 	 	    printf("删除成功!\n");
		}                
	}
    else
        printf("\n指定的职工不存在!\n");
	return length;
}

/********************************************************
                 按职工号删除职工信息
********************************************************/
void writeToFile(struct worker w[],int length)
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
		fwrite(w+i,sizeof(worker),1,fp);

	fclose(fp);

}
/********************************************************
                结构体数组中的职工信息输出到文件
********************************************************/
void main ()
{   
	 int choice;
	 struct worker w[N];
	 int NUM;char stuName[100];
	 int stuNum;
	 int length=0;
	 length=readFromFile(w);//读入
     do
	 {    xinxi();
	      
		  scanf("%d",&choice);
		  switch(choice)
		{ case 1:
			  length=f(w,length);
		     break;
          case 2:
			  output(w,length);
			 break;
		  case 3:
			  input(w,length);
		     break;
		  case 4:
		      sortCounts(w,length);
		      sortNumber(w,length);
		      break; 
		  case 5:  
			  printf("请输入欲查询的职工号");
			  scanf("%d",&NUM);
		      queryInfo(w,length,NUM);
		     break; 
		  case 6:
		      printf("请输入欲查找的姓名:");
			  scanf("%s",&stuName);
			  cha(w,length,stuName);
		     break; 
          case 7:
              printf("请输入欲删除的职工号");
			  scanf("%d",&stuNum);
		      length=delet(w,length,stuNum);
		     break; 
		  case 8:
			  {    
				   writeToFile(w,length);//保存
			       printf("谢谢使用再见\n");
			       exit(0);
			  }
		   default:
			   {
			       printf("输入有错误请重新输入:\n");
			   }
		  }
	}while(1);
}
////////////////////////////////////////////////////////////////////////////////
                     /*  职工信息管理系统的主函数--系统函数*/
////////////////////////////////////////////////////////////////////////////////