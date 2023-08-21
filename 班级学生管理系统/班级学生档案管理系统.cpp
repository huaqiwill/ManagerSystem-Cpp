/** File KTVSystem.cpp KTV歌曲系统
 * 项目地址：
 * CSDN博客：https://blog.csdn.net/HuaQi666
 * 开发者：http://bingbingfuhao.cn
 * 邮箱：3173484026@qq.com
 * 创建时间: 2023/8/21
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define N 100
struct student                           /*学生基本情况*/
{
	 int num;                            /*学号*/
	 int position;                       /*职位1为班长2为副班长3为团支书等*/
	 char name[8];                       /*姓名*/
	 char sex[2];                        /*性别f为女m为男*/
	 int age;                            /*年龄*/
	 int cult;                           /*文化程度1为大一2为大二3为大三4为大四5为其他*/
	 int result;                         /*成绩*/                        
}em[N];
struct communication                     /*学生通讯录*/
{
	 char name[8];
	 char hometel[13];
	 char handtel[13];
	 char address[13];
}empc[N];
struct empresult                         /*学生成绩与姓名的文件*/
{
	 char name[8];
	 int result;
}emps[N];
void manage();
void query();
void communicate();
void input();
void display();
void change();
void del();
void add();
int changeposition();
int changecult();
int changeresult();
void queryresult();
void creat();
void inputcommunicate();
void querycommunicate();
void changecommunicate();
void changetel1();
void changetel2();
void changetel3();
char password[7]="111111";
////////////////////////////////////////////////////////////////////////////////
                     /*  学生信息管理系统的主函数--系统函数*/
////////////////////////////////////////////////////////////////////////////////
main()
{
	 int choice;
	 char s[7];
	 int flag=0;
	 int m=1;
	 do
	 {
		  printf("请你输入密码:\n");
		  scanf("%s",s);
		  if(!strcmp(s,password))               /*若密码正确*/
		  {
			   printf("恭喜你成功登陆了\n\n\n");
			   flag=1;
             break;
		  }
		  else 
		  {
			   printf("输入有错误请重新输入:\n");
			   m++;
		  }
	}while(m<4);
    if(!flag)
	 {
		printf("你的输入次数已到再见\n");
	 }
	 do
	 {
		  printf("~~~~~~~~~~~~~~\t\t\t~~~~~~~~~~~~~~~~\n");
		  printf("\t\t欢迎进入班级学生管理系统中文版\n");
		  printf("制作人:宋苗苗 朱碧云 石丹丹\t班级:09通信\t学号:09030423 09030436 09030422\n");
		  printf("联系地址:常州工学院计算机信息工程学院\n");
		  printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
		  printf("\t\t请你选择操作类型:\n");
		  printf("**************\t\t**************\n");
		  printf("\t\t1进入管理系统\n");
		  printf("\t\t2进入查询系统\n");
		  printf("\t\t3进入通讯录\n");
		  printf("\t\t0退出系统\n");
		  printf("**************\t\t**************\n");
		  printf("说明:版权归作者所有违者必究\n\n\n\n");
		  scanf("%d",&choice);
		  switch(choice)
		  {
		  case 1:
			  manage();
		   break;
		  case 2:
			  query();
		   break;
		  case 3:
		   communicate();
		   break;
		  case 0:
		   {
			printf("谢谢使用再见\n");
			 exit(0);
		   }
		  default:
		   {
			   printf("输入有错误请重新输入:\n");
		   }
		}
	}while(1);
	getch();
}
////////////////////////////////////////////////////////////////////////////////
                            /*管理系统*/
//////////////////////////////////////////////////////////////////////////////// 
void manage()
{
	 int choicemanage;
	 char choice='y';
	 while(choice=='y'||choice=='Y')
	 {
		  printf("\t\t欢迎进入管理系统\n");
		  printf("===================\n");
		  printf("\t\t请你选择操作类型:\n");
		  printf("\t\t1输入学生信息\n");
		  printf("\t\t2显示学生信息\n");
		  printf("\t\t3修改学生信息\n");
		  printf("\t\t4追加一个学生信息\n");
		  printf("\t\t5删除一个学生信息\n");
		  printf("\t\t0返回\n");
		  printf("=====================\n");
		  scanf("%d",&choicemanage);
		  switch(choicemanage)
		  {
		  case 1:
			   input();                            /*输入学生信息*/
			   break;
		  case 2:
			   display();                          /*显示学生信息*/
			   break;
		  case 3:
			   change();                           /*修改学生信息*/
			   break;
		  case 4:
			   add();                              /*追加一个学生信息*/
			   break;
		  case 5:
			   del();                              /*删除一个学生信息*/
			   break;
		  case 0:
			   printf("谢谢你的使用再见\n");
			   return;
		  default:
				printf("你的输入有错请重新输入\n");
		  }
		  printf("是否继续管理?(y/n)");
		  scanf("%s",&choice);
	 }
	 if(toupper(choice)=='N'||(choice)=='n')
	 {
		 printf("输入完毕,任意键返回\n");
		 getch();
		 return;
	 }
}
////////////////////////////////////////////////////////////////////////////////
                           /*输入学生信息*/ 
////////////////////////////////////////////////////////////////////////////////
void input()
{
	 FILE *fp;
	 int i=0;
	 char choiceinput='y';
	 if((fp=fopen("d:\\student.txt","w"))==NULL)
	  return;
	 while(choiceinput=='y'||choiceinput=='Y')
	 {
		  i++;
		  printf("第%d个学生\n",i);
		  printf("\n");
		  printf("请你输入学号:\n");/*输入学号*/
		  scanf("%d",&em[i].num);
		  printf("\n");
		  printf("请你输入职位:\n");/*输入职位*/
		  printf("1为班长2为副班长3为团支书\n");
		  printf("4为学习委员5为生活委员6为组织委员\n");
		  printf("7为文艺委员8为体育委员9为其他\n");
		  scanf("%d",&em[i].position);
		  printf("\n");
		  printf("请你输入姓名:\n");/*输入姓名*/
		  scanf("%s",em[i].name);
		  printf("\n");
		  printf("请你输入性别以m为男f为女:\n");/*输入性别*/
		  scanf("%s",em[i].sex);
		  printf("\n");
		  printf("请你输入文化程度:\n");/*输入文化程度*/
		  printf("1为大一2为大二3为大三4为大四5为其他\n");
		  scanf("%d",&em[i].cult);
		  printf("\n");
		  printf("请你输入成绩:\n");/*输入成绩*/
		  scanf("%d",&em[i].result);
		  printf("\n"); 
		  printf("是否继续输入?(y/n)\n");
		  scanf("%s",&choiceinput);
		  fwrite(&em[i],sizeof(struct student),1,fp);
	 }
	 if(toupper(choiceinput)=='N')
	 {
		  fclose(fp);
		  printf("输入完毕,任意键返回\n");
		  getch();
		  return;
	 }
}
////////////////////////////////////////////////////////////////////////////////
                              /*显示学生信息*/
////////////////////////////////////////////////////////////////////////////////
void display()
{
	 FILE *fp;
	 int i;
	 if((fp=fopen("d:\\student.txt","r"))==NULL)
	  return;
	 printf("输出结果:\n");
	 printf("学号  职位  姓名  性别  文化程度  成绩  身体情况\n");
	 for(i=0;fread(&em[i],sizeof(struct student),1,fp)!=0;i++)
	 {
		  printf("学号%d\n",em[i].num);
		  printf("职位为%d\n",em[i].position);
		  printf("1为班长2为副班长3为团支书\n");
		  printf("4为学习委员5为生活委员6为组织委员\n");
		  printf("7为文艺委员8为体育委员9为其他\n");
		  printf("姓名为%s\n",em[i].name);
		  printf("性别为%s\n",em[i].sex);
		  printf("其中m为男f为女\n");
		  printf("文化程度为%d\n",em[i].cult);
		  printf("1为大一2为大二3为大三4为大四5为其他\n");
		  printf("成绩为%d\n",em[i].result);
	 }
	 printf("完毕按任意键返回\n");
	 getch();
	 fclose(fp);
	 return;
}
////////////////////////////////////////////////////////////////////////////////
                             /*修改学生信息*/
//////////////////////////////////////////////////////////////////////////////// 
void change()
{
	 FILE *fp;
	 int i;
	 char chname[8];
	 int choicechange;
	 printf("请你输入要修改的人的姓名:\n");
	 scanf("%s",&chname);
	 if((fp=fopen("d:\\student.txt","w+"))==NULL)
	 {
		  printf("不能够打开这个文件\n");
		  return;
	 }
	 for(i=0;i<N;i++)
	 {
		  if(strcmp(chname,em[i].name)==0)
		  {
			   printf("这是你要修改的人的信息\n");
			   printf("号为%d职位为%d姓名为%s性别为%s文化程度为%d成绩为%d\n",em[i].num,em[i].position,em[i].name,em[i].sex,em[i].cult,em[i].result);
			   printf("------------------------------------------------------------\n");
			   printf("请你输入要修改的部分:\n");
			   printf("======================\n");
			   printf("1修改职位\n");
			   printf("2修改文化程度\n");
			   printf("3修改成绩\n");
			   printf("0退出系统\n");
			   printf("======================\n");
			   printf("请选择\n");
			   scanf("%d",&choicechange);
			   switch(choicechange)
			   {
				case 1:
					em[i].position=changeposition();
					break;
				case 2:
					em[i].cult=changecult();
					break;
			   case 3:
					em[i].result=changeresult();
					break;
			   case 0:
					return;
			   default :
					printf("输入有错误");
			   }
			   fwrite(&em[i],sizeof(struct student),1,fp);
		  }
	 } 
	 fclose(fp);
	 printf("操作完成按任意键返回\n");
	 getch();
	 return;
}
////////////////////////////////////////////////////////////////////////////////
                                /*修改学生职位 */
//////////////////////////////////////////////////////////////////////////////// 
int changeposition()
{
	 int newposition;
	 printf("请你输入新职位:\n");
	 printf("1为班长2为副班长3为团支书\n");
	 printf("4为学习委员5为生活委员6为组织委员\n");
	 printf("7为文艺委员8为体育委员9为其他\n");
	 scanf("%d",&newposition);
	 return(newposition);
}
////////////////////////////////////////////////////////////////////////////////
                              /*修改学生文化程度*/ 
////////////////////////////////////////////////////////////////////////////////
int changecult()
{
	 int newcult;
	 printf("请你输入新的文凭:\n");
	 printf("1为大一2为大二3为大三4为大四5为其他\n");
	 scanf("%d",&newcult);
	 return(newcult);
}
////////////////////////////////////////////////////////////////////////////////
                             /*修改学生成绩*/
////////////////////////////////////////////////////////////////////////////////                              
int changeresult()
{
	 int newresult;
	 printf("请你输入新的成绩:\n");
	 scanf("%d",&newresult);
	 return(newresult);
}
////////////////////////////////////////////////////////////////////////////////  
                              /*追加一个学生信息*/
////////////////////////////////////////////////////////////////////////////////
void add()                              
{
	 struct student emp;
	 FILE *fp;
	 int i=0;
	 if((fp=fopen("d:\\student.txt","ab+"))==NULL)
	 {
		  printf("不能够打开这个文件\n");
		  getch();
		  return;
	 }
	 printf("请你输入新人的内容:\n");
	 printf("请你输入学号:\n");         /*输入学号*/
	 scanf("%d",&emp.num);
	 printf("请你输入职位:\n");         /*输入职位*/
	 printf("1为班长2为副班长3为团支书\n");
	 printf("4为学习委员5为生活委员6为组织委员\n");
	 printf("7为文艺委员8为体育委员9为其他\n");
	 scanf("%d",&emp.position);
	 printf("请你输入姓名:\n");         /*输入姓名*/
	 scanf("%s",emp.name);
	 printf("请你输入性别以m为男f为女:\n");/*输入性别*/
	 scanf("%s",emp.sex);
	 printf("请你输入文化程度:\n");     /*输入文化程度*/
	 printf("1为大一2为大二3为大三4为大四5为其他\n");
	 scanf("%d",&emp.cult);
	 printf("请你输入成绩:\n");         /*输入成绩*/
	 scanf("%d",&emp.result);
	 fwrite(&emp,sizeof(struct student),1,fp);
	 rewind(fp);
	 printf("插入完毕，按任意键返回\n");
	 getch();
	 fclose(fp);
	 return;
}
////////////////////////////////////////////////////////////////////////////////
                                 /*删除一个学生信息*/
//////////////////////////////////////////////////////////////////////////////// 
void del()                           
{
	 int i=0;
	 char delname[8];
	 FILE *fp;
	 if((fp=fopen("d:\\student.txt","w"))==NULL)
	 {
		  printf("文件为空，不能够打开\n");
		  printf("按任意键返回\n");
		  getch();
		  return;
	 }
	 printf("请你输入要删除的人的姓名:\n");      /*删除的学生的信息*/
	 scanf("%s",delname);
	 for(i=0;fread(&em[i],sizeof(struct student),1,fp)!=0;i++)
	 {
		  if(strcmp(em[i].name,delname)!=0)
		   fwrite(&em[i],sizeof(struct student),1,fp);
	 }
	  fclose(fp);
	  if((fp=fopen("d:\\student.txt","r"))==NULL)     /*显示新的学生的信息*/
		return;
	  printf("新的学生的信息为:\n");
	  for(i=0;fread(&em[i],sizeof(struct student),1,fp)!=0;i++)
	  {
		  printf("学号%d",em[i].num);
		  printf("职位为%d",em[i].position);
		  printf("1为班长2为副班长3为团支书\n");
		  printf("4为学习委员5为生活委员6为组织委员\n");
		  printf("7为文艺委员8为体育委员9为其他\n");
		  printf("姓名为%s",em[i].name[8]);
		  printf("性别为%s",em[i].sex[2]);
		  printf("其中m为男f为女");
		  printf("文化程度为%d",em[i].cult);
		  printf("1为大一2为大二3为大三4为大四5为其他\n");
		  printf("成绩为%d",em[i].result);
		  fclose(fp);
	  }
}
////////////////////////////////////////////////////////////////////////////////
                            /*查询学生的信息*/
////////////////////////////////////////////////////////////////////////////////                            
void query()
{
	 FILE *fp;
 
	 char quename[8];
	 int i=0;
	 if((fp=fopen("d:\\student.txt","r"))==NULL)
	 {
		  printf("不能够打开文件，按任意键返回\n");
		  getch();
		  return;
	 }
	 printf("请你输入要查询的人的姓名\n");
	 scanf("%s",quename);
	 for(i=0;fread(&em[i],sizeof(struct student),1,fp)!=0;i++)
	 {
		  if(strcmp(em[i].name,quename)==0)  /*找到,并显示该学生记录*/
		  {
				printf("\t\t\n查询到的学生号或姓名为的信息如下:\n");
				printf("以下是你要查询的人的信息\n");
				printf("学号%d\n",em[i].num);
				printf("职位为%d\n",em[i].position);
				printf("\t1为班长2为副班长3为团支书\n");
				printf("\t4为学习委员5为生活委员6为组织委员\n");
				printf("\t7为文艺委员8为体育委员9为其他\n");
				printf("姓名为%s\n",em[i].name);
				printf("性别为%s\n",em[i].sex);
				printf("\t其中m为男f为女");
				printf("文化程度为%d",em[i].cult);
				printf("\t1为大一2为大二3为大三4为大四5为其他\n");
				printf("成绩为%d",em[i].result);
				printf("\n");
				printf("查询完毕，按任意键返回\n");
				getch();
				fclose(fp);
				return;
		  }
	 }
	 printf("没有这样的人，按任意键返回\n");
	 getch();
     fclose(fp);
     return;
}
////////////////////////////////////////////////////////////////////////////////
                              /*修改学生文化程度*/
//////////////////////////////////////////////////////////////////////////////// 
void queryresult()
{
	 int i;
	 FILE *fp1,*fp2;
	 creat();
	 if((fp1=fopen("d:\\student.txt","w+"))==NULL)
	  return;
	 for(i=0;fread(&em[i],sizeof(struct student),1,fp1)!=0;i++)
	 {
		 printf("输出结果为:\n");
		 printf("工号%d",em[i].num);
		 printf("职位为%d",em[i].position);
		 printf("1为班长2为副班长3为团支书\n");
		 printf("4为学习委员5为生活委员6为组织委员\n");
		 printf("7为文艺委员8为体育委员9为其他\n");
		 printf("姓名为%s",em[i].name[8]);
		 printf("性别为%s",em[i].sex[2]);
		 printf("其中m为男f为女");
		 printf("文化程度为%d",em[i].cult);
		 printf("1为大一2为大二3为大三4为大四5为其他\n");
		 printf("成绩为%d",em[i].result);
	     strcpy(emps[i].name,em[i].name);
	     emps[i].result=em[i].result;
	 }
	 if((fp2=fopen("empresult.txt","w"))==NULL)
	     return;
	 for(i=0;i<N;i++)
	     fwrite(&emps[i],sizeof(struct empresult),1,fp2);  
	 fclose(fp1);
	 fclose(fp2);
}
////////////////////////////////////////////////////////////////////////////////
                             /*追加一个学生的通讯录*/
////////////////////////////////////////////////////////////////////////////////                            
void creat()
{
	 FILE *fp;
	 if((fp=fopen("d:\\student.txt","w+"))==NULL)
	  return;
	 input();
	 fclose(fp);
}
////////////////////////////////////////////////////////////////////////////////
                            /*进入通讯录系统*/ 
////////////////////////////////////////////////////////////////////////////////
void communicate()
{
    int choicecommunicate;
    printf("欢迎进入通讯录系统\n");  
    printf("请你选择操作类型:\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("1为输入通讯录信息\n");
    printf("2为查询通讯录信息\n");
    printf("3为修改通讯录信息\n");
    printf("0为退出通讯录系统\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    scanf("%d",&choicecommunicate);
    switch(choicecommunicate)
    {
		 case 1:
		  inputcommunicate();
		  break;
		 case 2:
			 querycommunicate();
		  break;
		 case 3:
		  changecommunicate();
		  break;
		 case 0:
		  {
			printf("谢谢使用再见\n");
			printf("按任意键返回\n");
			getch();
			return;
		  }
		default:
			printf("输入有错\n");
	}
        
}   
 ///////////////////////////////////////////////////////////////////////////////
                               /*输入通讯录信息*/
////////////////////////////////////////////////////////////////////////////////                                  
void inputcommunicate()
{
        FILE *fp;
        int choiceincom='y';
        int i=0;
        if((fp=fopen("empcom.txt","w"))==NULL)
		{
                  printf("不能够打开文件\n"); 
                  printf("任意键返回\n");
                  getch();
                  return;
		}
        printf("请你输入通讯录的信息:\n");
        while(choiceincom=='y'||choiceincom=='Y')
        {
               i++;
               printf("第%d个学生\n",i);
               printf("请你输入姓名:\n");
               scanf("%s",empc[i].name);
               printf("请你输入家庭电话号码:\n");
               scanf("%s",empc[i].hometel);
               printf("请你输入手机号码:\n"); 
               scanf("%s",empc[i].handtel);
               printf("请你输入地址:\n"); 
               scanf("%s",empc[i].address);
               printf("是否继续输入?(y/n)\n");
               choiceincom=getch();
			   fwrite(&empc[i],sizeof(struct communication),1,fp);
       }
       if(toupper(choiceincom)=='N')
       {
         fclose(fp);
         printf("输入完毕,任意键返回\n");
         return;
	   }       
}
////////////////////////////////////////////////////////////////////////////////
                          /*查询学生通讯录*/ 
////////////////////////////////////////////////////////////////////////////////
void querycommunicate()
{
       FILE *fp;
       int i=0;
       char qcname[8]; 
       if((fp=fopen("empcom.txt","r"))==NULL)
       {
			 printf("不能够打开文件，按任意键返回\n");
			 getch();
			 return;
       }
		printf("请你输入要查询的人的姓名:\n");
		scanf("%s",qcname);
		for(i=0;fread(&empc[i],sizeof(struct communication),1,fp)!=0;i++)
		{
			   if(strcmp(empc[i].name,qcname)==0)
			   {
				   printf("以下为您所要求的信息:\n");
				   printf("姓名为%s\n",empc[i].name);
				   printf("家庭电话号码为%s\n",empc[i].hometel); 
				   printf("手机号码为%s\n",empc[i].handtel);
				   printf("家庭地址为%s\n",empc[i].address);
				   printf("查询完毕，按任意键返回\n");
				   getch();
				   fclose(fp);
				   return;
			   }
		}
        printf("没有这样的人，按任意键返回\n");
        getch();
        fclose(fp);
        return;
}
////////////////////////////////////////////////////////////////////////////////
                           /*修改学生通讯录*/
////////////////////////////////////////////////////////////////////////////////                            
void changecommunicate()
{
	FILE *fp;
	int i=0;
	char chcname[8];
	int choicecom;
	if((fp=fopen("empcom.txt","w+"))==NULL)
	{
		printf("打不开文件按任意键返回\n");
		getch();
		return;
	}
	printf("请你输入你要修改的人的姓名:\n");
	scanf("%s",chcname);
	for(i=0;fread(&empc[i],sizeof(struct communication),1,fp)!=0;i++)
	{
		if(strcmp(empc[i].name,chcname)==0)
		{
			printf("以下为您所要修改的人的信息:\n");
			printf("姓名为%s\n",empc[i].name);
			printf("家庭电话号码为%s\n",empc[i].hometel); 
			printf("手机号码为%s\n",empc[i].handtel);
			printf("家庭地址为%s\n",empc[i].address);
			printf("请你选择要修改的东西:\n");
			printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
			printf("1修改家庭电话号码\n");
			printf("2修改手机电话号码\n");
			printf("0退出系统\n");
			printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
			scanf("%d",&choicecom);
			switch(choicecom)
			{
			case 1:
			  changetel1();
			  break;
			case 2:
			  changetel2();
			  break;
			case 3:
			  changetel3();
			  break;
			case 0:
			  return;
			default:
			  printf("输入有错\n");
			}
       
		  }
	}
}
////////////////////////////////////////////////////////////////////////////////
                        /*修改学生电话号码*/ 
////////////////////////////////////////////////////////////////////////////////
void changetel1()
{
	printf("......略\n");
}

void changetel2()
{
	printf("......略\n");
}

void changetel3()
{
	printf("......略\n");
}
