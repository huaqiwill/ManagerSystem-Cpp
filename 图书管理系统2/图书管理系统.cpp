/** File KTVSystem.cpp KTV����ϵͳ
 * ��Ŀ��ַ��
 * CSDN���ͣ�https://blog.csdn.net/HuaQi666
 * �����ߣ�http://bingbingfuhao.cn
 * ���䣺3173484026@qq.com
 * ����ʱ��: 2023/8/21
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
		printf("|       ��ӭʹ��ͼ�����ϵͳ               |\n");
		printf("|******************************************|\n");
		printf("|            ͼ�����                      |\n");
		printf("|==========================================|\n");
		printf("|            1,����ͼ����Ϣ                |\n");
		printf("|            2,ɾ��ͼ��                    |\n");
		printf("|            3,����ͼ��                    |\n");
		printf("|            4,�����Ʋ�ѯͼ��              |\n");
		printf("|            5,�����߲�ѯͼ��              |\n");
        printf("|            6,����������Ϣ                |\n");
        printf("|            7,�޸Ķ�����Ϣ                |\n");
		printf("|==========================================|\n");
		printf("|         ����ͻ������                   |\n");
		printf("|******************************************|\n");
		printf("|            8,����                        |\n");
		printf("|            9,����                        |\n");
        printf("|            0,�˳�ϵͳ                    |\n");
		printf("============================================\n");
		printf("\n���ã���������ѡ��(1,2,3,4,5,6,7,8,9,0):\n"); 
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
//************************1����ͼ����Ϣ***********************//
void Bookfound()
{
	FILE *fp=NULL; 
    book a; 
	char filename[20]=""; 
	int h=1; 
	printf("\nΪ�˴洢ͼ����Ϣ������һ���ļ���.\n");
	scanf("%s",filename);
    if((fp=fopen(filename,"wb+"))==NULL)
	{
		printf("\ncan not open this file");
		return;
	}
    printf("�����������Ϣ\n");
	printf("�������������Ϊ0���ʾ���������\n");
	while(h<=size)
	{
		printf("���������:\n");
		scanf("%ld",&a.booknumber);
		if(a.booknumber==0)
	    break;
        printf("����������:\n");
		scanf("%s",a.bookname);
		printf("����������:\n");
		scanf("%s",a.auther);
		printf("�����������:\n");
		scanf("%s",a.press );
		printf("������۸�:\n");
		scanf("%f",&a.price );
		printf("�����뵱ǰ������:\n");
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
	printf("�����������Ϣ�Ѿ��ɹ��洢���ļ�����\n");
	printf("�����ļ�����������:\n");
	if((fp=fopen(filename,"rb+"))==NULL)
	{
		printf("can not open the file.\n");
		return;
	}
	printf("\n���\t����\t����\t������\t�۸�\t����\n"); 
	while(fread(&a,sizeof(book),1,fp)!=0)
	{
		printf("\n%ld\t%s\t%s\t%s\t%f\t%d\n",a.booknumber,a.bookname,a.auther,a.press,a.price ,a.nownum );
	}
	fclose(fp);
}
//************************ɾ��ͼ����Ϣ***********************//
void Bookdel()
{
	int i;
	long No;
	book a;
	book s[size];
	int R;
	char filename[30];
	FILE *fp;
    printf("\n������������ļ���.\n");
	scanf("%s",filename);
    if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("\ncan not open this file");
		return;
	}
    printf("��������Ҫɾ�������:\n");
	scanf("%ld",&No);
	printf("��Ҫɾ�������Ϊ:%ld\n",No);
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
	printf("ɾ���Ժ��ļ������������:\n");
	printf("\n���r\t����\t����\t������\t�۸�\t����\n");
    while(fread(&a,sizeof(book),1,fp)!=0)
	{
		if(a.booknumber!=0)
			printf("\n%ld\t%s\t%s\t%s\t%f\t%d\n",a.booknumber,a.bookname,a.auther,a.press,a.price,a.nownum);
	}
	fclose(fp);
	 
}
//************************����ͼ����Ϣ***********************//
 void Bookadd()
{
	FILE *fp=NULL; 
    book a; 
	char filename[30]; 
	int h=1; 
	printf("\n������������ļ���.\n");
	scanf("%s",filename);
    if((fp=fopen(filename,"a+"))==NULL)
	{
		printf("\ncan not open this file");
		return;
	}
    printf("��������Ҫ��ӵ������Ϣ\n");
	printf("�������������Ϊ0�����ʾ�������\n");
	while(h<=size)
	{
		printf("���������\n");
		scanf("%ld",&a.booknumber);
		if(a.booknumber==0)
			break;
		printf("����������:\n");
		scanf("%s",a.bookname);
		printf("����������:\n");
		scanf("%s",a.auther);
		printf("�����������:\n");
		scanf("%s",a.press);
		printf("������۸�\n");
		scanf("%f",&a.price);
		printf("�����뵱ǰ������:\n");
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
		printf("\n�Բ����������볬����");
	fclose(fp);
	printf("����������ݳɹ��洢���ļ���\n");
	printf("��������:\n");
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("cannot open the file\n");
		return;
	}
	printf("\n���\t����\t����\t������\t�۸�\t����\n"); 
	while(fread(&a,sizeof(book),1,fp)!=0)
	{
		printf("\n%ld\t%s\t%s\t%s\t%f\t%d\n",a.booknumber,a.bookname,a.auther,a.press ,a.price,a.nownum );
	}
	fclose(fp);
}
//***********************��������ѯͼ����Ϣ************************//
void Booklook()
	{
	 	FILE *fp;
		book a;	
		char shum[20];
	    int result=0;
		char filename[20];
		printf("��������Ҫ��ѯ������:\n");
		scanf("%s",shum);
		result=0;
		printf("\n������洢����ļ���.\n");
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
					printf(":\n��Ҫ���ҵ�ͼ����Ϣ����:\n");
					printf("����:%s\n",a.bookname);
					printf("���:%ld\n",a.booknumber);
					printf("�۸�:%f\n",a.price);
					printf("����:%s\n",a.auther);
					printf("������:%s\n",a.press);
					printf("��ǰ����:%d\n",a.nownum);
					result=1;
				}
			}
			
		}
		fclose(fp);
		if(result==0)
		{
			printf("�Բ���û����Ҫ�ҵ���");
		}
}
//***********************�����߲�ѯͼ����Ϣ************************//
void Booksearch()
	{
	 	FILE *fp;
		book a;	
		char zuoz[20];
	    int result=0;
		char filename[20];
		printf("��������Ҫ��ѯͼ�������:\n");
		scanf("%s",zuoz);
		result=0;
		printf("\n������洢����ļ���.\n");
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
					printf(":\nninҪ���ҵ�ͼ����Ϣ����:\n");
					printf("����:%s\n",a.bookname);
					printf("���:%ld\n",a.booknumber);
					printf("�۸�:%f\n",a.price);
                    printf("����:%s\n",a.auther);                      
					printf("������:%s\n",a.press);
					printf("��ǰ����:%d\n",a.nownum);
					result=1;
				}
			}
			
		}
		fclose(fp);
		if(result==0)
		{
			printf("�Բ���û����Ҫ�ҵ���");
		}
}

//************************����������Ϣ************************//
void Memberadd()
{
	FILE *fp=NULL; 
    Member a; 
	char Datafile[30]=""; 
	int count=1; 
	printf("\n������洢���ߵ��ļ���\n");	 
	scanf("%s",Datafile);     
	if((fp=fopen(Datafile,"a+"))==NULL)
	{
		printf("\ncan not open this file");
		return;
	}     
	printf("��������ߵ���Ϣ\n");
	printf("\n�������Ŀ���Ϊ0��ʾ�������\n");	 
	while(count<=size)
	{		 
		printf("�����뿨��:\n");
		scanf("%ld",&a.cardnumber);
		if(a.cardnumber==0)
			break;
        printf("����������:\n");
		scanf("%s",a.name);	 
        printf("�������Ա�:\n");
		scanf("%s",a.sex);
		printf("�������ֻ�����:\n");
		scanf("%ld",&a.tel);		 
        printf("������༶:\n");
		scanf("%s",a.clas);
		printf("���������״̬:\n");
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
		printf("\n�Բ���������Ķ�����������\n");
	fclose(fp);
	printf("������Ķ�����Ϣ�Ѿ��ɹ��洢�ڻ�Ա�ļ���\n");
	printf("��������������:\n");
	if((fp=fopen(Datafile,"rb"))==NULL)
	{
		printf("cannot open the file\n");
		return;
	}
	printf("\n����\t����\t�Ա�\t�ֻ�����\t�༶\t����״̬\n"); 
	while(fread(&a,sizeof(Member),1,fp)!=0)
	{
		printf("\n%ld\t%s\t%s\t%ld\t%s\t%s\n",a.cardnumber,a.name,a.sex,a.tel,a.clas,a.condition);
	}
	fclose(fp);
}
//************************������Ϣ�޸�*****************************//
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
	printf("\n������洢���ߵ��ļ���\n");
	scanf("%s",filename);
    if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("\nopen file %s fail",filename);
		return;
	}
	printf("��������Ҫ�޸ĵĶ��ߵĿ���:\n");
	scanf("%ld",&num);
	cardnumber=num;
	printf("����������:\n");
	scanf("%s",name);
	printf("�������Ա�:\n");
	scanf("%s",sex );
	printf("���������ڵ��ֻ�����:\n");
    scanf("%ld",&tel);
	printf("���������ڵİ༶:\n");
    scanf("%s",clas);
	printf("���������״̬:\n");
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
     printf("���޸Ķ���������Ϣ�Ѿ��ɹ��洢���ļ���\n");
	 printf("�޸ĺ����������:\n");
	 if((fp=fopen(filename,"rb"))==NULL)
	 {
		 printf("can not open the file\n");
		 return;
	 }
	 printf("\n����\t����\t�Ա�\t�ֻ�����\t�༶\t����״̬\n"); 
	 while(fread(&a,sizeof(Member),1,fp)!=0)
	 {
		 if(a.cardnumber!=0)
			 printf("\n%ld\t%s\t%s\t%ld\t%s\t%s\n",a.cardnumber,a.name,a.sex,a.tel,a.clas,a.condition);
	 }
	 fclose(fp);
}
//***********************����***********************//
void Bookborrow()
{
	FILE *fp;
	book a;
	Member b;
	int mflag=0,flag=0;
	char bookname[20],membername[20];
	char filename[20];
	printf("����������:\n");
	scanf("%s",membername);
	printf("\n������洢���ߵ��ļ���:");
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
	printf("����Խ���\n");
	printf("��������Ҫ�������:\n");
	scanf("%s",bookname);
	printf("������洢ͼ����ļ���:\n");
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
				printf("�Ȿ�����\n");
				printf("��ϲ�������ɹ���\n");
				flag=1;
			}
		}
	}
	if(flag==0)		
	{
		printf("�Բ����Ȿ�鱻���˽�����\n");
		printf("����ʧ����\n");
	}
	if(flag==1)
	{
       printf("���޸�ͼ��Ͷ�����Ϣ���Ѹ������Ϣ��ӵ�ͼ����Ϣ�ļ��У��Ѷ��ߵ�״̬��Ϊ�ѽ���״̬\n");
       printf("��ȥѡ����Ӧ�Ĺ��ܽ����޸�\n");
	}
	fclose(fp);
  }
}

//************************����************************//
void Bookreturn()
{
	FILE *fp;
	book a;
	Member b;
	int mflag=0,flag=0;
	char bookname[20],membername[20];
	char filename[20];
	printf("����������:\n");
	scanf("%s",membername);
	printf("\n������洢���ļ���:");
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
		printf("�������!�㲻�Ƕ���,�㲻���Ի���!\n");
	}
  if(mflag==1)
  {
	printf("�����Ի���!\n");
	fclose(fp);
	printf("������Ҫ��������:\n");
	scanf("%s",bookname);
	printf("������洢ͼ����ļ���:\n");
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
				printf("��ϲ��,����ɹ�!\n");
				flag=1;
			}
			
		}
	}
	if(flag==0)		
	{
	  printf("�Բ����������ˡ��Ȿ�鲻������ͼ��ݵ�!\n");
	  printf("�Բ���,����ʧ��\n");
	  flag=0;
	}
			
	if(flag==1)
	{
		printf("���޸�ͼ��Ͷ�����Ϣ���Ѹ������Ϣ��ӵ�ͼ����Ϣ�ļ��У��Ѷ��ߵ�״̬��Ϊ�ѻ���״̬\n");
		printf("��ѡ����Ӧ�Ĺ��ܽ����޸�\n");
	}
	fclose(fp);
  }
}
