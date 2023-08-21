/** File KTVSystem.cpp KTV歌曲系统
 * 项目地址：
 * CSDN博客：https://blog.csdn.net/HuaQi666
 * 开发者：http://bingbingfuhao.cn
 * 邮箱：3173484026@qq.com
 * 创建时间: 2023/8/21
 */

# include "stdio.h"     
# include "stdlib.h"    
# include "string.h"   
# define size 100 
typedef struct         
{
	long booknumber;											 
	char bookname[15];										 
	char auther[20];											  
	char press[20];										 
	float price;
	int nownum;
}book;
typedef struct
{
	long cardnumber;
	char name[20];
	char sex[10];
	long tel;
	char clas[20];
	char condition[20];
}Member;
 void Bookfound();							    
 void Bookdel();
 void Bookadd();						         
 void Booklook();
 void Booksearch();
 void Memberadd();
 void Memberchange();
 void Bookborrow();					  
 void Bookreturn();
 
 //***********************************************//
int login(char password[])
 {
     static char key[10]="123";
     if(strcmp(password,key)==0)
       return 1;
     else
       return 0;
  }  
void main()
{
	int choice;
   do
	{
		printf("|==========================================|\n");
		printf("|       欢迎使用图书管理系统               |\n");
		printf("|******************************************|\n");
		printf("|            图书管理                      |\n");
		printf("|==========================================|\n");
		printf("|            1,创建图书信息                |\n");
		printf("|            2,删除图书                    |\n");
		printf("|            3,增添图书                    |\n");
		printf("|            4,按名称查询图书              |\n");
		printf("|            5,按作者查询图书              |\n");
        printf("|            6,创建读者信息                |\n");
        printf("|            7,修改读者信息                |\n");
		printf("|==========================================|\n");
		printf("|         借书和还书管理                   |\n");
		printf("|******************************************|\n");
		printf("|            8,借书                        |\n");
		printf("|            9,还书                        |\n");
        printf("|            0,退出系统                    |\n");
		printf("============================================\n");
		printf("\n您好！请输您的选择(1,2,3,4,5,6,7,8,9,0):\n"); 
		scanf("%d",&choice);
		switch(choice)
		{
    	 case 1:Bookfound();break;					  
		 case 2:Bookdel();break;					 
	 	 case 3:Bookadd();break;
		 case 4:Booklook();break;
		 case 5:Booksearch();break; 
		 case 6: Memberadd();break;
         case 7: Memberchange();break;
		 case 8:Bookborrow();break;					  
		 case 9:Bookreturn();break;
		 case 0:exit(0);break;					 
		}
	}while(1);
}
//************************1输入图书信息***********************//
void Bookfound()
{
	FILE *fp=NULL; 
    book a; 
	char filename[20]=""; 
	int h=1; 
	printf("\n为了存储图书信息请输入一个文件名.\n");
	scanf("%s",filename);
    if((fp=fopen(filename,"wb+"))==NULL)
	{
		printf("\ncan not open this file");
		return;
	}
    printf("请输入书的信息\n");
	printf("如过你输入的书号为0则表示输入结束了\n");
	while(h<=size)
	{
		printf("请输入书号:\n");
		scanf("%ld",&a.booknumber);
		if(a.booknumber==0)
	    break;
        printf("请输入书名:\n");
		scanf("%s",a.bookname);
		printf("请输入作者:\n");
		scanf("%s",a.auther);
		printf("请输入出版社:\n");
		scanf("%s",a.press );
		printf("请输入价格:\n");
		scanf("%f",&a.price );
		printf("请输入当前的数量:\n");
		scanf("%d",&a.nownum);
		printf("==================================\n");
		if(fwrite(&a,sizeof(book),1,fp)!=1)
			{
				printf("write file %s fail",filename);
					return;
			}
		h++;	
	}
	fclose(fp);
	printf("你输入书的信息已经成功存储在文件里了\n");
	printf("输入文件的内容如下:\n");
	if((fp=fopen(filename,"rb+"))==NULL)
	{
		printf("can not open the file.\n");
		return;
	}
	printf("\n书号\t书名\t作者\t出版社\t价格\t数量\n"); 
	while(fread(&a,sizeof(book),1,fp)!=0)
	{
		printf("\n%ld\t%s\t%s\t%s\t%f\t%d\n",a.booknumber,a.bookname,a.auther,a.press,a.price ,a.nownum );
	}
	fclose(fp);
}
//************************删除图书信息***********************//
void Bookdel()
{
	int i;
	long No;
	book a;
	book s[size];
	int R;
	char filename[30];
	FILE *fp;
    printf("\n请输入存放书的文件名.\n");
	scanf("%s",filename);
    if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("\ncan not open this file");
		return;
	}
    printf("请输入你要删除的书号:\n");
	scanf("%ld",&No);
	printf("你要删除的书号为:%ld\n",No);
	R=0;
    while(fread(&a,sizeof(book),1,fp)!=0)
	{
		if(a.booknumber!=No)
		{
			s[R].booknumber=a.booknumber;
            strcpy(s[R].bookname,a.bookname);
            strcpy(s[R].auther,a.auther);
            strcpy(s[R].press,a.press);
			s[R].price =a.price;
			s[R].nownum =a.nownum ;
            R++;
		}
	}
	fclose(fp);
	if((fp=fopen(filename,"wb+"))==NULL)
	{
		printf("\ncan not open this file");
		return;
	}
	for(i=0;i<R;i++)
	{
		if(fwrite(&s[i],sizeof(book),1,fp)!=1)
			{
				printf("write file %s fail",filename);
					return;
			}
	}
	fclose(fp);
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("\ncan not open this file");
		return;
	}
	printf("删除以后文件里的内容如下:\n");
	printf("\n书号r\t书名\t作者\t出版社\t价格\t数量\n");
    while(fread(&a,sizeof(book),1,fp)!=0)
	{
		if(a.booknumber!=0)
			printf("\n%ld\t%s\t%s\t%s\t%f\t%d\n",a.booknumber,a.bookname,a.auther,a.press,a.price,a.nownum);
	}
	fclose(fp);
	 
}
//************************增加图书信息***********************//
 void Bookadd()
{
	FILE *fp=NULL; 
    book a; 
	char filename[30]; 
	int h=1; 
	printf("\n请输入存放书的文件名.\n");
	scanf("%s",filename);
    if((fp=fopen(filename,"a+"))==NULL)
	{
		printf("\ncan not open this file");
		return;
	}
    printf("请输入你要添加的书的信息\n");
	printf("如果你输入的书号为0，这表示输入结束\n");
	while(h<=size)
	{
		printf("请输入书号\n");
		scanf("%ld",&a.booknumber);
		if(a.booknumber==0)
			break;
		printf("请输入书名:\n");
		scanf("%s",a.bookname);
		printf("请输入作者:\n");
		scanf("%s",a.auther);
		printf("请输入出版社:\n");
		scanf("%s",a.press);
		printf("请输入价格\n");
		scanf("%f",&a.price);
		printf("请输入当前的数量:\n");
		scanf("%d",&a.nownum);
		printf("==================================\n");
		if(fwrite(&a,sizeof(book),1,fp)!=1)
			{
				printf("write file %s fail",filename);
				return;
			}
		h++;	
	}
	if(h>size)
		printf("\n对不起，您的输入超量了");
	fclose(fp);
	printf("您输入的内容成功存储在文件中\n");
	printf("内容如下:\n");
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("cannot open the file\n");
		return;
	}
	printf("\n书号\t书名\t作者\t出版社\t价格\t数量\n"); 
	while(fread(&a,sizeof(book),1,fp)!=0)
	{
		printf("\n%ld\t%s\t%s\t%s\t%f\t%d\n",a.booknumber,a.bookname,a.auther,a.press ,a.price,a.nownum );
	}
	fclose(fp);
}
//***********************按书名查询图书信息************************//
void Booklook()
	{
	 	FILE *fp;
		book a;	
		char shum[20];
	    int result=0;
		char filename[20];
		printf("请输入您要查询的书名:\n");
		scanf("%s",shum);
		result=0;
		printf("\n请输入存储书的文件名.\n");
		scanf("%s",filename);
		if((fp=fopen(filename,"rb"))==NULL)
		{
			printf("\ncan  not open this file.");
			return;
		}
		while(feof(fp)==0) 
		{
			{if(fread(&a,sizeof(book),1,fp)!=0)
			
				if(strcmp(shum,a.bookname)==0)
				{
					printf(":\n您要查找的图书信息如下:\n");
					printf("书名:%s\n",a.bookname);
					printf("书号:%ld\n",a.booknumber);
					printf("价格:%f\n",a.price);
					printf("作者:%s\n",a.auther);
					printf("出版社:%s\n",a.press);
					printf("当前数量:%d\n",a.nownum);
					result=1;
				}
			}
			
		}
		fclose(fp);
		if(result==0)
		{
			printf("对不起没有你要找的书");
		}
}
//***********************按作者查询图书信息************************//
void Booksearch()
	{
	 	FILE *fp;
		book a;	
		char zuoz[20];
	    int result=0;
		char filename[20];
		printf("请输入您要查询图书的作者:\n");
		scanf("%s",zuoz);
		result=0;
		printf("\n请输入存储书的文件名.\n");
		scanf("%s",filename);
		if((fp=fopen(filename,"rb"))==NULL)
		{
			printf("\ncan  not open this file.");
			return;
		}
		while(feof(fp)==0) 
		{
			{if(fread(&a,sizeof(book),1,fp)!=0)
			
				if(strcmp(zuoz,a.bookname)==0)
				{
					printf(":\nnin要查找的图书信息如下:\n");
					printf("书名:%s\n",a.bookname);
					printf("书号:%ld\n",a.booknumber);
					printf("价格:%f\n",a.price);
                    printf("作者:%s\n",a.auther);                      
					printf("出版社:%s\n",a.press);
					printf("当前数量:%d\n",a.nownum);
					result=1;
				}
			}
			
		}
		fclose(fp);
		if(result==0)
		{
			printf("对不起没有你要找的书");
		}
}

//************************创建读者信息************************//
void Memberadd()
{
	FILE *fp=NULL; 
    Member a; 
	char Datafile[30]=""; 
	int count=1; 
	printf("\n请输入存储读者的文件名\n");	 
	scanf("%s",Datafile);     
	if((fp=fopen(Datafile,"a+"))==NULL)
	{
		printf("\ncan not open this file");
		return;
	}     
	printf("请输入读者的信息\n");
	printf("\n如果输入的卡号为0表示输入结束\n");	 
	while(count<=size)
	{		 
		printf("请输入卡号:\n");
		scanf("%ld",&a.cardnumber);
		if(a.cardnumber==0)
			break;
        printf("请输入名字:\n");
		scanf("%s",a.name);	 
        printf("请输入性别:\n");
		scanf("%s",a.sex);
		printf("请输入手机号码:\n");
		scanf("%ld",&a.tel);		 
        printf("请输入班级:\n");
		scanf("%s",a.clas);
		printf("请输入借书状态:\n");
		scanf("%s",a.condition );
		printf("----------------------------------\n");
		if(fwrite(&a,sizeof(Member),1,fp)!=1)
		{
			printf("write file %s fail",Datafile);
			return;
		}
		count++;	
	}
	if(count>size)
		printf("\n对不起，您输入的读者数量超量\n");
	fclose(fp);
	printf("您增添的读者信息已经成功存储在会员文件中\n");
	printf("增添后的内容如下:\n");
	if((fp=fopen(Datafile,"rb"))==NULL)
	{
		printf("cannot open the file\n");
		return;
	}
	printf("\n卡号\t姓名\t性别\t手机号码\t班级\t借书状态\n"); 
	while(fread(&a,sizeof(Member),1,fp)!=0)
	{
		printf("\n%ld\t%s\t%s\t%ld\t%s\t%s\n",a.cardnumber,a.name,a.sex,a.tel,a.clas,a.condition);
	}
	fclose(fp);
}
//************************读者信息修改*****************************//
void Memberchange()
{   
	FILE *fp;
	long num;
	long cardnumber;
	char name[20];
	char sex[10];
	long tel;
	char clas[20];
	char condition[20];
	Member a;
	Member s[size];
	int R,i;
	char filename[30];
	printf("\n请输入存储读者的文件名\n");
	scanf("%s",filename);
    if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("\nopen file %s fail",filename);
		return;
	}
	printf("请输入你要修改的读者的卡号:\n");
	scanf("%ld",&num);
	cardnumber=num;
	printf("请输入名字:\n");
	scanf("%s",name);
	printf("请输入性别:\n");
	scanf("%s",sex );
	printf("请输入现在的手机号码:\n");
    scanf("%ld",&tel);
	printf("请输入现在的班级:\n");
    scanf("%s",clas);
	printf("请输入借书状态:\n");
    scanf("%s",condition);
    R=0;
	while(fread(&a,sizeof(Member),1,fp)!=0)
	{
		if(a.cardnumber!=num)
		{
			s[R].cardnumber=a.cardnumber;
            strcpy(s[R].name,a.name); 
            strcpy(s[R].sex,a.sex);
            strcpy(s[R].clas,a.clas);
			strcpy(s[R].condition,a.condition);
			s[R].tel=a.tel;
			R++;
		}
		else
		{
			s[R].cardnumber=cardnumber;
            strcpy(s[R].name,name); 
            strcpy(s[R].sex,sex);
            strcpy(s[R].clas,clas);
			strcpy(s[R].condition,a.condition);
			s[R].tel=tel;
			R++;			  
		}
	 }
     fclose(fp);
     if((fp=fopen(filename,"wb+"))==NULL)
	 {
		 printf("cannot open the file\n");
		 return;
	 }
	 for(i=0;i<R;i++)
	 {
		 if(fwrite(&s[i],sizeof(Member),1,fp)!=1)
		 {
			 printf("\nopen the file %s fail",filename);
			 return;
		 }
	 }
	 fclose(fp);
     printf("你修改读者内容信息已经成功存储在文件中\n");
	 printf("修改后的内容如下:\n");
	 if((fp=fopen(filename,"rb"))==NULL)
	 {
		 printf("can not open the file\n");
		 return;
	 }
	 printf("\n卡号\t姓名\t性别\t手机号码\t班级\t借书状态\n"); 
	 while(fread(&a,sizeof(Member),1,fp)!=0)
	 {
		 if(a.cardnumber!=0)
			 printf("\n%ld\t%s\t%s\t%ld\t%s\t%s\n",a.cardnumber,a.name,a.sex,a.tel,a.clas,a.condition);
	 }
	 fclose(fp);
}
//***********************借书***********************//
void Bookborrow()
{
	FILE *fp;
	book a;
	Member b;
	int mflag=0,flag=0;
	char bookname[20],membername[20];
	char filename[20];
	printf("请输入名字:\n");
	scanf("%s",membername);
	printf("\n请输入存储读者的文件名:");
	scanf("%s",filename);
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("cannot open the file\n");
		return;
	}
	while(feof(fp)==0)
	{
		if(fread(&b,sizeof(Member),1,fp)!=0)
		{
			if(strcmp(membername,b.name)==0)
			{
				mflag=1;
				break;
			}
		}
	}
	fclose(fp);
  if(mflag==1)
  {
	printf("你可以借书\n");
	printf("请输入你要借的书名:\n");
	scanf("%s",bookname);
	printf("请输入存储图书的文件名:\n");
	scanf("%s",filename);
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("cannot open file\n");
		return;
	}
	while(feof(fp)==0)
	{
		if(fread(&a,sizeof(book),1,fp)!=0)
		{
			if(strcmp(bookname,a.bookname)==0)
			{
				printf("这本书存在\n");
				printf("恭喜你你借书成功了\n");
				flag=1;
			}
		}
	}
	if(flag==0)		
	{
		printf("对不起，这本书被别人借走了\n");
		printf("借书失败了\n");
	}
	if(flag==1)
	{
       printf("请修该图书和读者信息，把该书的信息添加到图书信息文件中，把读者的状态改为已借书状态\n");
       printf("请去选择相应的功能进行修改\n");
	}
	fclose(fp);
  }
}

//************************还书************************//
void Bookreturn()
{
	FILE *fp;
	book a;
	Member b;
	int mflag=0,flag=0;
	char bookname[20],membername[20];
	char filename[20];
	printf("请输入名字:\n");
	scanf("%s",membername);
	printf("\n请输入存储的文件名:");
	scanf("%s",filename);
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("cannot open the file\n");
		return;
	}
	while(feof(fp)==0)
	{
		if(fread(&b,sizeof(Member),1,fp)!=0)
		{
			if(strcmp(membername,b.name)==0)
			{
				mflag=1;
				break;
			}
		}
	}
	if(mflag==0)
	{
		printf("别忽悠人!你不是读者,你不可以还书!\n");
	}
  if(mflag==1)
  {
	printf("您可以还书!\n");
	fclose(fp);
	printf("请输入要还的书名:\n");
	scanf("%s",bookname);
	printf("请输入存储图书的文件名:\n");
	scanf("%s",filename);
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("cannot open file\n");
		return;
	}
	while(feof(fp)==0)
	{
		if(fread(&a,sizeof(book),1,fp)!=0)
		{
			if(strcmp(bookname,a.bookname)==0)
			{
				printf("恭喜您,还书成功!\n");
				flag=1;
			}
			
		}
	}
	if(flag==0)		
	{
	  printf("对不起，您还错了。这本书不是我们图书馆的!\n");
	  printf("对不起,还书失败\n");
	  flag=0;
	}
			
	if(flag==1)
	{
		printf("请修该图书和读者信息，把该书的信息添加到图书信息文件中，把读者的状态改为已换书状态\n");
		printf("请选择相应的功能进行修改\n");
	}
	fclose(fp);
  }
}
