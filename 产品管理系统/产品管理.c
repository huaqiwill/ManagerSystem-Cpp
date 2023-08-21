/** File KTVSystem.cpp KTV歌曲系统
 * 项目地址：
 * CSDN博客：https://blog.csdn.net/HuaQi666
 * 开发者：http://bingbingfuhao.cn
 * 邮箱：3173484026@qq.com
 * 创建时间: 2023/8/21
 */
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

#define N 50
#define FILENAME "chanpin.txt"
struct date 
{
 int month;
 int day;
 int year;
};
struct  chanpin
{
    int number1;        /*产品编号*/
    char name1[10];     /*产品姓名*/
    int number2;        /*产品类型编号*/
    char name2[10];     /*产品规格*/
    char name3[10];     /*计量单位*/
    int d2;             /*产品数量*/
    int d3;             /*参考价格*/
    struct date jhrq;   /*进货日期*/
    struct date yxrq;   /*有效日期*/


};

/*******************************************************       
功能:显示菜单
参数：无   
返回值：无
 *******************************************************/
 void displayMenu()
 {

        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               产品信息管理系统2.0                     +\n");
        printf("+                                                       +\n");
        printf("+                 1. 输入信息                           +\n");
        printf("+                 2. 产品信息的修改                     +\n");
        printf("+                 3. 产品信息的删除                     +\n");
        printf("+                 4. 根据产品名称查询产品信息。         +\n");
        printf("+                 5. 显示全部产品记录                   +\n");
        printf("+                 6. 按参考价格从小到大显示记录         +\n");
        printf("+                 7. 显示全部过期产品信息               +\n");
        printf("+                 8. 保存到文件                         +\n");
        printf("+                 9. 从文件读                           +\n");
        printf("+                 10.程序结束                           +\n");
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
     static char key[10]="123";
     if(strcmp(password,key)==0)
       return 1;
     else
       return 0;
  }
  /*******************************************************       
功能:从文件读信息到结构体数组中
参数：
参数1：chanpin[]
  类型：CHANPIN []
  说明：用来存储从文件读到的产品信息
返回值：i
  类型：int
  说明：表示实际读取到的个数
 *******************************************************/
 int readFromFile(struct chanpin stu[])
 {
    FILE *fp;
    int i=0;
    if((fp=fopen(FILENAME,"rb"))==NULL) /*打开文件*/
    {
      printf("cannot open file\n");
      exit(0);
    }
    while(fread(&stu[i],sizeof(struct chanpin),1,fp)==1)
    {
        
        i++;
    }
    fclose(fp);
    return i;
}

int unique(struct chanpin stu[],int length,int stuNumber,int cur)
{
    int flag=1,i;
    for(i=0;i<length;i++)
    {
        if(stu[i].number1==stuNumber&&i!=cur)
        { 
            flag=0;
            break;
        }
    }
return flag;
}

int scan(struct chanpin stu[],int n)
{
    int i=n;
    int endFlag=0;
     printf("编号(0退出)\n：");
    
        
    while(i<N)
    {
    
        while(1)
        {
            int flag;
            printf("编号\n:");
            scanf("%d",&stu[i].number1);
            if(stu[i].number1==0)
            {
                endFlag=1;
                break;
            }
            flag=unique(stu,i,stu[i].number1,i);
            if(flag) break;
            printf("该编号已经存在，请重新输入!\n");
        }
        if(endFlag==1)
            break;
    printf("名称\n：");
    scanf("%s",stu[i].name1);
    printf("类型编号\n：");
    scanf("%d",&stu[i].number2);
    printf("产品规格\n：");
    scanf("%s",stu[i].name2);
    printf("计量单位\n：");
    scanf("%s",stu[i].name3);
    printf("产品数量\n：");
    scanf("%d",&stu[i].d2);
    printf("参考价格\n：");
    scanf("%d",&stu[i].d3);
    printf("进货日期\n：");
    scanf("%d-%d-%d",&stu[i].jhrq.year,&stu[i].jhrq.month,&stu[i].jhrq.day);
    printf("有效日期\n：");
    scanf("%d-%d-%d",&stu[i].yxrq.year,&stu[i].yxrq.month,&stu[i].yxrq.day);
    i++;
    }
    
    
    
   return i;

}
/*******************************************************       
功能:将结构体数组中的产品信息显示到屏幕
参数：
参数1：chanpin[]
  类型：chanpin stu[]
  明：用来存储产品信息的数组
参数2：N
  类型：int
  说明：表示实际数组的长度 
返回值：无
 *******************************************************/
void print(struct chanpin stu[],int n)
{
    int i=0;
    if (n>0)
        printf("%-4s %-10s %-4s %-4s %-4s %-4s %-4s %-4s %-4s","产品编号","名称","类型编号","产品规格","计量单位",
        "产品数量","参考价格","进货日期","有效期\n\n");
    for(i=0;i<n;i++)
    {
    printf("%-4d %6s %10d %9s %9s %8d %8d %9d-%d-%d %6d-%d-%d",stu[i].number1,stu[i].name1,stu[i].number2,
        stu[i].name2,stu[i].name3,stu[i].d2,stu[i].d3,stu[i].jhrq.year,stu[i].jhrq.month,stu[i].jhrq.day,
        stu[i].yxrq.year,stu[i].yxrq.month,stu[i].yxrq.day);
    printf("\n");
    }
    printf("\n\n");
}
 /*******************************************************       
功能:根据名称从数组中查找产品
参数：
参数1：chanpin[]
  类型：chanpin stu[]
  说明：用来存储产品信息的数组
参数2：N
  类型：int
  说明：表示实际数组的长度 
参数3：stuName
  类型：char
  说明：表示要查找的产品的名称
返回值：无
 *******************************************************/
void chazhao(struct chanpin stu[],int length,char stuName[])
{
    int i=0;
    int found=0;
    for(i=0;i<length;i++)
    {
        if(strcmp(stuName,stu[i].name1)==0)
        {   found++;
            if(found==1)
            {
                printf("找到啦\n");
                printf("%-4s %-10s %-4s %-4s %-4s %-4s %-4s %-4s %-4s","产品编号","名称","类型编号","产品规格","计量单位",
        "产品数量","参考价格","进货日期","有效期\n\n");
            }
        printf("%-4d %6s %10d %9s %9s %8d %8d %9d-%d-%d %6d-%d-%d",stu[i].number1,stu[i].name1,stu[i].number2,
        stu[i].name2,stu[i].name3,stu[i].d2,stu[i].d3,stu[i].jhrq.year,stu[i].jhrq.month,stu[i].jhrq.day,
        stu[i].yxrq.year,stu[i].yxrq.month,stu[i].yxrq.day);
        }
    }
    if(found==0)
        printf("\n指定的名称不存在!\n");
}


void writeToFile(struct chanpin stu[],int n)
{
    FILE *fp=NULL;
    int i=0;

    fp=fopen(FILENAME,"wb");

    if(fp==NULL)
    {
        printf("打开文件出错！\n");
        exit(0);
    }

    for(i=0;i<n;i++)
        fwrite(&stu[i],sizeof(struct chanpin),1,fp);

    fclose(fp);

}

/*******************************************************       
功能:根据编号修改数组中编号
参数：
参数1：chanpin
  类型：stu []
  说明：用来存储产品信息的数组出
参数2：length
  类型：int
  说明：表示实际数组的长度 
参数3：stuNumber
  类型：int
  说明：表示要修改的产品的编号
返回值：无
 *******************************************************/
void editInfoByNumber(struct chanpin stu[],int length,int stuNumber)
{
    int i=0;
    int choice,flag;
    for(i=0;i<length;i++)
    {
        if(stuNumber==stu[i].number1)
       {
            printf("找到啦!它的下标是:%d\n", i);

            printf("%-4s %-10s %-4s %-4s %-4s %-4s %-4s %-4s %-4s","产品编号","名称","类型编号","产品规格","计量单位",
        "产品数量","参考价格","进货日期","有效期\n\n");
     printf("%-4d %6s %10d %9s %9s %8d %8d %9d-%d-%d %6d-%d-%d",stu[i].number1,stu[i].name1,stu[i].number2,
        stu[i].name2,stu[i].name3,stu[i].d2,stu[i].d3,stu[i].jhrq.year,stu[i].jhrq.month,stu[i].jhrq.day,
        stu[i].yxrq.year,stu[i].yxrq.month,stu[i].yxrq.day);
     do{
                printf("\n");
                printf("***********************\n");
                printf("   1:编号    \n");
                printf("   2:名称    \n");
                printf("   3:类型编号\n");
                printf("   4:产品规格\n");
                printf("   5:计量单位\n");
                printf("   6:产品数量\n");
                printf("   7:参考价格\n");
                printf("   8:进货日期\n");
                printf("   9:有效期  \n");
                printf("***********************\n");          
                printf("请输入欲修改的字段(0退出):");
                scanf("%d",&choice);
                switch(choice)
                { case 1: 
                       printf("请输入编号:");
                       scanf("%d",&stuNumber);
                       flag=unique(stu,length,stuNumber,i);
                       if(!flag)
                           printf("该编号已经存在!\n");
                       else
                       {   stu[i].number1=stuNumber;
                           printf("修改成功\n");
                       } 
                       break;
                   case 2: 
                       printf("请输入名称:");
                       scanf("%s",stu[i].name1);
                       printf("修改成功\n");
                       break;
                   case 3: 
                       printf("请输入类型编号:");
                       scanf("%d",&stu[i].number2);
                       printf("修改成功\n");
                       break;
                   case 4: 
                       printf("请输入产品规格:");
                       scanf("%s",stu[i].name2);
                       printf("修改成功\n");
                       break;
                   case 5: 
                       printf("请输入计量单位:");
                       scanf("%s",stu[i].name3);
                       printf("修改成功\n");
                       break;
                   case 6: 
                       printf("请输入产品数量:");
                       scanf("%d",&stu[i].d2);
                       printf("修改成功\n");
                       break;
                   case 7: 
                       printf("请输入参考价格:");
                       scanf("%d",&stu[i].d3);
                       printf("修改成功\n");
                       break;
                   case 8: 
                       printf("请输入进货日期:");
                       scanf("%d,%d,%d",&stu[i].jhrq.year,&stu[i].jhrq.month,&stu[i].jhrq.day);
                       printf("修改成功\n");
                       break;
                    case 9: 
                       printf("请输入有效期:");
                       scanf("%d,%d,%d",&stu[i].yxrq.year,&stu[i].yxrq.month,&stu[i].yxrq.day);
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
        printf("\n指定的编号不存在!\n");
}
 /*******************************************************       
功能:根据编号删除数组中编号
参数：
参数1：chanpin
  类型：stu []
  说明：用来存储名称信息的数组
参数2：length
  类型：int
  说明：表示实际数组的长度 
参数3：stuNumber
  类型：int
  说明：表示要修改的名称的编号
返回值：length
        删除后名称的个数        
 *******************************************************/
int deleteInfoByNumber(struct chanpin stu[],int length,int stuNumber)
{
    int i,j;
    char choice;
    for(i=0;i<length;i++)
    {
        if(stuNumber==stu[i].number1)
       {
            printf("找到啦!它的下标是:%d\n", i);

              printf("%-4s %-10s %-4s %-4s %-4s %-4s %-4s %-4s %-4s","产品编号","名称","类型编号","产品规格","计量单位",
        "产品数量","参考价格","进货日期","有效期\n\n");
         printf("%-4d %6s %10d %9s %9s %8d %8d %9d-%d-%d %6d-%d-%d",stu[i].number1,stu[i].name1,stu[i].number2,
        stu[i].name2,stu[i].name3,stu[i].d2,stu[i].d3,stu[i].jhrq.year,stu[i].jhrq.month,stu[i].jhrq.day,
        stu[i].yxrq.year,stu[i].yxrq.month,stu[i].yxrq.day);
           break; 
        }
    }
    if(i<length)
    {
        printf("你确实要删除这个名称吗?(Y/N)\n");
        getchar();
        scanf("%c",&choice);
        if(choice=='Y'||choice=='y')
        {
            for(j=i;j<length;j++)
                stu[j]=stu[j+1];
            length--;
            printf("删除成功!\n");
        }                
    }
    else
        printf("\n指定的名称不存在!\n");
    return length;
}

void f( struct chanpin stu[],int n)
{
  int i,j;
  struct chanpin t;
  for(j=0;j<n-1;j++)
      for(i=0;i<n-j-1;i++)
          if(stu[i].d3>stu[i+1].d3)
          {t=stu[i];
          stu[i]=stu[i+1];
          stu[i+1]=t;
          }

}
void y( struct chanpin stu[],int n)
{
    int i;
    int year;
    int month;
    int day;
   printf("今天日期\n：");
   scanf("%d,%d,%d",&year,&month,&day);
   for(i=0;i<n;i++)
   {
    if((year>stu[i].yxrq.year) || ((year==stu[i].yxrq.year) && (month>stu[i].yxrq.month)) ||
        ((year==stu[i].yxrq.year) && (month==stu[i].yxrq.month) && (day>stu[i].yxrq.day)))
             printf("%-4s %-10s %-4s %-4s %-4s %-4s %-4s %-4s %-4s","产品编号","名称","类型编号","产品规格","计量单位",
        "产品数量","参考价格","进货日期","有效期\n\n");
        printf("%-4d %-10s %-3d %6s %9s %8d %8d %8d-%d-%d %9d-%d-%d",stu[i].number1,stu[i].name1,stu[i].number2,
        stu[i].name2,stu[i].name3,stu[i].d2,stu[i].d3,stu[i].jhrq.year,stu[i].jhrq.month,stu[i].jhrq.day,
        stu[i].yxrq.year,stu[i].yxrq.month,stu[i].yxrq.day);
    
   }
}



 main()
{
    struct chanpin stu[10];
    int choice = 0; /*select and store menu item  */
    int s=0;
    char password[10];
    long stuNumber;
    char stuName[10];
    int n=0;
    int i;


    /*====验证用户的口令，直到正确为止====*/
    do{
        printf("请输入口令：");
        scanf("%s",password);

        s=login(password);
     }while(s==0);
     
    /*====根据用户的选择，执行相应的操作.====*/
   while(1)
    {

        displayMenu();
       
        printf("\n 请选择您的操作(1,2,3,4,5,6,7,8,9,10)：\n");
        scanf("%d",&choice);

        switch(choice)
        {

            case 1:
                n=scan(stu,n);
                break;

            case 2:
                printf("请输入欲修改的名称的编号:\n");
                scanf("%d",&stuNumber);
                editInfoByNumber(stu,n,stuNumber);
                break;
            case 3:
                printf("请输入欲删除的名称的编号:\n");
                scanf("%d",&stuNumber);
                deleteInfoByNumber(stu,n,stuNumber);
                break;
            case 4:
                printf("请输入欲查找的名称：\n");
                scanf("%s",stuName);
                chazhao(stu,n,stuName);
                break;
            case 5:
                print(stu,n);
                break;
            case 6:
                f(stu,n);
                for(i=0;i<n;i++)
        printf("%-4d %-10s %-3d %6s %9s %8d %8d %8d-%d-%d %9d-%d-%d",stu[i].number1,stu[i].name1,stu[i].number2,
        stu[i].name2,stu[i].name3,stu[i].d2,stu[i].d3,stu[i].jhrq.year,stu[i].jhrq.month,stu[i].jhrq.day,
        stu[i].yxrq.year,stu[i].yxrq.month,stu[i].yxrq.day);
                break;
            case 7:
                y(stu,n);
                break;
            case 8:
                writeToFile(stu,n);
                break;
            case 9:
                n=readFromFile(stu);
                break;
            case 10:
                writeToFile(stu,n);
                exit(0);
                break;

          
        
        }

   }

    
}
