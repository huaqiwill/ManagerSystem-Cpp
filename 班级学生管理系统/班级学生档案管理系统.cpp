/** File KTVSystem.cpp KTV����ϵͳ
 * ��Ŀ��ַ��
 * CSDN���ͣ�https://blog.csdn.net/HuaQi666
 * �����ߣ�http://bingbingfuhao.cn
 * ���䣺3173484026@qq.com
 * ����ʱ��: 2023/8/21
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define N 100
struct student                           /*ѧ���������*/
{
	 int num;                            /*ѧ��*/
	 int position;                       /*ְλ1Ϊ�೤2Ϊ���೤3Ϊ��֧���*/
	 char name[8];                       /*����*/
	 char sex[2];                        /*�Ա�fΪŮmΪ��*/
	 int age;                            /*����*/
	 int cult;                           /*�Ļ��̶�1Ϊ��һ2Ϊ���3Ϊ����4Ϊ����5Ϊ����*/
	 int result;                         /*�ɼ�*/                        
}em[N];
struct communication                     /*ѧ��ͨѶ¼*/
{
	 char name[8];
	 char hometel[13];
	 char handtel[13];
	 char address[13];
}empc[N];
struct empresult                         /*ѧ���ɼ����������ļ�*/
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
                     /*  ѧ����Ϣ����ϵͳ��������--ϵͳ����*/
////////////////////////////////////////////////////////////////////////////////
main()
{
	 int choice;
	 char s[7];
	 int flag=0;
	 int m=1;
	 do
	 {
		  printf("������������:\n");
		  scanf("%s",s);
		  if(!strcmp(s,password))               /*��������ȷ*/
		  {
			   printf("��ϲ��ɹ���½��\n\n\n");
			   flag=1;
             break;
		  }
		  else 
		  {
			   printf("�����д�������������:\n");
			   m++;
		  }
	}while(m<4);
    if(!flag)
	 {
		printf("�����������ѵ��ټ�\n");
	 }
	 do
	 {
		  printf("~~~~~~~~~~~~~~\t\t\t~~~~~~~~~~~~~~~~\n");
		  printf("\t\t��ӭ����༶ѧ������ϵͳ���İ�\n");
		  printf("������:������ ����� ʯ����\t�༶:09ͨ��\tѧ��:09030423 09030436 09030422\n");
		  printf("��ϵ��ַ:���ݹ�ѧԺ�������Ϣ����ѧԺ\n");
		  printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
		  printf("\t\t����ѡ���������:\n");
		  printf("**************\t\t**************\n");
		  printf("\t\t1�������ϵͳ\n");
		  printf("\t\t2�����ѯϵͳ\n");
		  printf("\t\t3����ͨѶ¼\n");
		  printf("\t\t0�˳�ϵͳ\n");
		  printf("**************\t\t**************\n");
		  printf("˵��:��Ȩ����������Υ�߱ؾ�\n\n\n\n");
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
			printf("ллʹ���ټ�\n");
			 exit(0);
		   }
		  default:
		   {
			   printf("�����д�������������:\n");
		   }
		}
	}while(1);
	getch();
}
////////////////////////////////////////////////////////////////////////////////
                            /*����ϵͳ*/
//////////////////////////////////////////////////////////////////////////////// 
void manage()
{
	 int choicemanage;
	 char choice='y';
	 while(choice=='y'||choice=='Y')
	 {
		  printf("\t\t��ӭ�������ϵͳ\n");
		  printf("===================\n");
		  printf("\t\t����ѡ���������:\n");
		  printf("\t\t1����ѧ����Ϣ\n");
		  printf("\t\t2��ʾѧ����Ϣ\n");
		  printf("\t\t3�޸�ѧ����Ϣ\n");
		  printf("\t\t4׷��һ��ѧ����Ϣ\n");
		  printf("\t\t5ɾ��һ��ѧ����Ϣ\n");
		  printf("\t\t0����\n");
		  printf("=====================\n");
		  scanf("%d",&choicemanage);
		  switch(choicemanage)
		  {
		  case 1:
			   input();                            /*����ѧ����Ϣ*/
			   break;
		  case 2:
			   display();                          /*��ʾѧ����Ϣ*/
			   break;
		  case 3:
			   change();                           /*�޸�ѧ����Ϣ*/
			   break;
		  case 4:
			   add();                              /*׷��һ��ѧ����Ϣ*/
			   break;
		  case 5:
			   del();                              /*ɾ��һ��ѧ����Ϣ*/
			   break;
		  case 0:
			   printf("лл���ʹ���ټ�\n");
			   return;
		  default:
				printf("��������д�����������\n");
		  }
		  printf("�Ƿ��������?(y/n)");
		  scanf("%s",&choice);
	 }
	 if(toupper(choice)=='N'||(choice)=='n')
	 {
		 printf("�������,���������\n");
		 getch();
		 return;
	 }
}
////////////////////////////////////////////////////////////////////////////////
                           /*����ѧ����Ϣ*/ 
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
		  printf("��%d��ѧ��\n",i);
		  printf("\n");
		  printf("��������ѧ��:\n");/*����ѧ��*/
		  scanf("%d",&em[i].num);
		  printf("\n");
		  printf("��������ְλ:\n");/*����ְλ*/
		  printf("1Ϊ�೤2Ϊ���೤3Ϊ��֧��\n");
		  printf("4ΪѧϰίԱ5Ϊ����ίԱ6Ϊ��֯ίԱ\n");
		  printf("7Ϊ����ίԱ8Ϊ����ίԱ9Ϊ����\n");
		  scanf("%d",&em[i].position);
		  printf("\n");
		  printf("������������:\n");/*��������*/
		  scanf("%s",em[i].name);
		  printf("\n");
		  printf("���������Ա���mΪ��fΪŮ:\n");/*�����Ա�*/
		  scanf("%s",em[i].sex);
		  printf("\n");
		  printf("���������Ļ��̶�:\n");/*�����Ļ��̶�*/
		  printf("1Ϊ��һ2Ϊ���3Ϊ����4Ϊ����5Ϊ����\n");
		  scanf("%d",&em[i].cult);
		  printf("\n");
		  printf("��������ɼ�:\n");/*����ɼ�*/
		  scanf("%d",&em[i].result);
		  printf("\n"); 
		  printf("�Ƿ��������?(y/n)\n");
		  scanf("%s",&choiceinput);
		  fwrite(&em[i],sizeof(struct student),1,fp);
	 }
	 if(toupper(choiceinput)=='N')
	 {
		  fclose(fp);
		  printf("�������,���������\n");
		  getch();
		  return;
	 }
}
////////////////////////////////////////////////////////////////////////////////
                              /*��ʾѧ����Ϣ*/
////////////////////////////////////////////////////////////////////////////////
void display()
{
	 FILE *fp;
	 int i;
	 if((fp=fopen("d:\\student.txt","r"))==NULL)
	  return;
	 printf("������:\n");
	 printf("ѧ��  ְλ  ����  �Ա�  �Ļ��̶�  �ɼ�  �������\n");
	 for(i=0;fread(&em[i],sizeof(struct student),1,fp)!=0;i++)
	 {
		  printf("ѧ��%d\n",em[i].num);
		  printf("ְλΪ%d\n",em[i].position);
		  printf("1Ϊ�೤2Ϊ���೤3Ϊ��֧��\n");
		  printf("4ΪѧϰίԱ5Ϊ����ίԱ6Ϊ��֯ίԱ\n");
		  printf("7Ϊ����ίԱ8Ϊ����ίԱ9Ϊ����\n");
		  printf("����Ϊ%s\n",em[i].name);
		  printf("�Ա�Ϊ%s\n",em[i].sex);
		  printf("����mΪ��fΪŮ\n");
		  printf("�Ļ��̶�Ϊ%d\n",em[i].cult);
		  printf("1Ϊ��һ2Ϊ���3Ϊ����4Ϊ����5Ϊ����\n");
		  printf("�ɼ�Ϊ%d\n",em[i].result);
	 }
	 printf("��ϰ����������\n");
	 getch();
	 fclose(fp);
	 return;
}
////////////////////////////////////////////////////////////////////////////////
                             /*�޸�ѧ����Ϣ*/
//////////////////////////////////////////////////////////////////////////////// 
void change()
{
	 FILE *fp;
	 int i;
	 char chname[8];
	 int choicechange;
	 printf("��������Ҫ�޸ĵ��˵�����:\n");
	 scanf("%s",&chname);
	 if((fp=fopen("d:\\student.txt","w+"))==NULL)
	 {
		  printf("���ܹ�������ļ�\n");
		  return;
	 }
	 for(i=0;i<N;i++)
	 {
		  if(strcmp(chname,em[i].name)==0)
		  {
			   printf("������Ҫ�޸ĵ��˵���Ϣ\n");
			   printf("��Ϊ%dְλΪ%d����Ϊ%s�Ա�Ϊ%s�Ļ��̶�Ϊ%d�ɼ�Ϊ%d\n",em[i].num,em[i].position,em[i].name,em[i].sex,em[i].cult,em[i].result);
			   printf("------------------------------------------------------------\n");
			   printf("��������Ҫ�޸ĵĲ���:\n");
			   printf("======================\n");
			   printf("1�޸�ְλ\n");
			   printf("2�޸��Ļ��̶�\n");
			   printf("3�޸ĳɼ�\n");
			   printf("0�˳�ϵͳ\n");
			   printf("======================\n");
			   printf("��ѡ��\n");
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
					printf("�����д���");
			   }
			   fwrite(&em[i],sizeof(struct student),1,fp);
		  }
	 } 
	 fclose(fp);
	 printf("������ɰ����������\n");
	 getch();
	 return;
}
////////////////////////////////////////////////////////////////////////////////
                                /*�޸�ѧ��ְλ */
//////////////////////////////////////////////////////////////////////////////// 
int changeposition()
{
	 int newposition;
	 printf("����������ְλ:\n");
	 printf("1Ϊ�೤2Ϊ���೤3Ϊ��֧��\n");
	 printf("4ΪѧϰίԱ5Ϊ����ίԱ6Ϊ��֯ίԱ\n");
	 printf("7Ϊ����ίԱ8Ϊ����ίԱ9Ϊ����\n");
	 scanf("%d",&newposition);
	 return(newposition);
}
////////////////////////////////////////////////////////////////////////////////
                              /*�޸�ѧ���Ļ��̶�*/ 
////////////////////////////////////////////////////////////////////////////////
int changecult()
{
	 int newcult;
	 printf("���������µ���ƾ:\n");
	 printf("1Ϊ��һ2Ϊ���3Ϊ����4Ϊ����5Ϊ����\n");
	 scanf("%d",&newcult);
	 return(newcult);
}
////////////////////////////////////////////////////////////////////////////////
                             /*�޸�ѧ���ɼ�*/
////////////////////////////////////////////////////////////////////////////////                              
int changeresult()
{
	 int newresult;
	 printf("���������µĳɼ�:\n");
	 scanf("%d",&newresult);
	 return(newresult);
}
////////////////////////////////////////////////////////////////////////////////  
                              /*׷��һ��ѧ����Ϣ*/
////////////////////////////////////////////////////////////////////////////////
void add()                              
{
	 struct student emp;
	 FILE *fp;
	 int i=0;
	 if((fp=fopen("d:\\student.txt","ab+"))==NULL)
	 {
		  printf("���ܹ�������ļ�\n");
		  getch();
		  return;
	 }
	 printf("�����������˵�����:\n");
	 printf("��������ѧ��:\n");         /*����ѧ��*/
	 scanf("%d",&emp.num);
	 printf("��������ְλ:\n");         /*����ְλ*/
	 printf("1Ϊ�೤2Ϊ���೤3Ϊ��֧��\n");
	 printf("4ΪѧϰίԱ5Ϊ����ίԱ6Ϊ��֯ίԱ\n");
	 printf("7Ϊ����ίԱ8Ϊ����ίԱ9Ϊ����\n");
	 scanf("%d",&emp.position);
	 printf("������������:\n");         /*��������*/
	 scanf("%s",emp.name);
	 printf("���������Ա���mΪ��fΪŮ:\n");/*�����Ա�*/
	 scanf("%s",emp.sex);
	 printf("���������Ļ��̶�:\n");     /*�����Ļ��̶�*/
	 printf("1Ϊ��һ2Ϊ���3Ϊ����4Ϊ����5Ϊ����\n");
	 scanf("%d",&emp.cult);
	 printf("��������ɼ�:\n");         /*����ɼ�*/
	 scanf("%d",&emp.result);
	 fwrite(&emp,sizeof(struct student),1,fp);
	 rewind(fp);
	 printf("������ϣ������������\n");
	 getch();
	 fclose(fp);
	 return;
}
////////////////////////////////////////////////////////////////////////////////
                                 /*ɾ��һ��ѧ����Ϣ*/
//////////////////////////////////////////////////////////////////////////////// 
void del()                           
{
	 int i=0;
	 char delname[8];
	 FILE *fp;
	 if((fp=fopen("d:\\student.txt","w"))==NULL)
	 {
		  printf("�ļ�Ϊ�գ����ܹ���\n");
		  printf("�����������\n");
		  getch();
		  return;
	 }
	 printf("��������Ҫɾ�����˵�����:\n");      /*ɾ����ѧ������Ϣ*/
	 scanf("%s",delname);
	 for(i=0;fread(&em[i],sizeof(struct student),1,fp)!=0;i++)
	 {
		  if(strcmp(em[i].name,delname)!=0)
		   fwrite(&em[i],sizeof(struct student),1,fp);
	 }
	  fclose(fp);
	  if((fp=fopen("d:\\student.txt","r"))==NULL)     /*��ʾ�µ�ѧ������Ϣ*/
		return;
	  printf("�µ�ѧ������ϢΪ:\n");
	  for(i=0;fread(&em[i],sizeof(struct student),1,fp)!=0;i++)
	  {
		  printf("ѧ��%d",em[i].num);
		  printf("ְλΪ%d",em[i].position);
		  printf("1Ϊ�೤2Ϊ���೤3Ϊ��֧��\n");
		  printf("4ΪѧϰίԱ5Ϊ����ίԱ6Ϊ��֯ίԱ\n");
		  printf("7Ϊ����ίԱ8Ϊ����ίԱ9Ϊ����\n");
		  printf("����Ϊ%s",em[i].name[8]);
		  printf("�Ա�Ϊ%s",em[i].sex[2]);
		  printf("����mΪ��fΪŮ");
		  printf("�Ļ��̶�Ϊ%d",em[i].cult);
		  printf("1Ϊ��һ2Ϊ���3Ϊ����4Ϊ����5Ϊ����\n");
		  printf("�ɼ�Ϊ%d",em[i].result);
		  fclose(fp);
	  }
}
////////////////////////////////////////////////////////////////////////////////
                            /*��ѯѧ������Ϣ*/
////////////////////////////////////////////////////////////////////////////////                            
void query()
{
	 FILE *fp;
 
	 char quename[8];
	 int i=0;
	 if((fp=fopen("d:\\student.txt","r"))==NULL)
	 {
		  printf("���ܹ����ļ��������������\n");
		  getch();
		  return;
	 }
	 printf("��������Ҫ��ѯ���˵�����\n");
	 scanf("%s",quename);
	 for(i=0;fread(&em[i],sizeof(struct student),1,fp)!=0;i++)
	 {
		  if(strcmp(em[i].name,quename)==0)  /*�ҵ�,����ʾ��ѧ����¼*/
		  {
				printf("\t\t\n��ѯ����ѧ���Ż�����Ϊ����Ϣ����:\n");
				printf("��������Ҫ��ѯ���˵���Ϣ\n");
				printf("ѧ��%d\n",em[i].num);
				printf("ְλΪ%d\n",em[i].position);
				printf("\t1Ϊ�೤2Ϊ���೤3Ϊ��֧��\n");
				printf("\t4ΪѧϰίԱ5Ϊ����ίԱ6Ϊ��֯ίԱ\n");
				printf("\t7Ϊ����ίԱ8Ϊ����ίԱ9Ϊ����\n");
				printf("����Ϊ%s\n",em[i].name);
				printf("�Ա�Ϊ%s\n",em[i].sex);
				printf("\t����mΪ��fΪŮ");
				printf("�Ļ��̶�Ϊ%d",em[i].cult);
				printf("\t1Ϊ��һ2Ϊ���3Ϊ����4Ϊ����5Ϊ����\n");
				printf("�ɼ�Ϊ%d",em[i].result);
				printf("\n");
				printf("��ѯ��ϣ������������\n");
				getch();
				fclose(fp);
				return;
		  }
	 }
	 printf("û���������ˣ������������\n");
	 getch();
     fclose(fp);
     return;
}
////////////////////////////////////////////////////////////////////////////////
                              /*�޸�ѧ���Ļ��̶�*/
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
		 printf("������Ϊ:\n");
		 printf("����%d",em[i].num);
		 printf("ְλΪ%d",em[i].position);
		 printf("1Ϊ�೤2Ϊ���೤3Ϊ��֧��\n");
		 printf("4ΪѧϰίԱ5Ϊ����ίԱ6Ϊ��֯ίԱ\n");
		 printf("7Ϊ����ίԱ8Ϊ����ίԱ9Ϊ����\n");
		 printf("����Ϊ%s",em[i].name[8]);
		 printf("�Ա�Ϊ%s",em[i].sex[2]);
		 printf("����mΪ��fΪŮ");
		 printf("�Ļ��̶�Ϊ%d",em[i].cult);
		 printf("1Ϊ��һ2Ϊ���3Ϊ����4Ϊ����5Ϊ����\n");
		 printf("�ɼ�Ϊ%d",em[i].result);
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
                             /*׷��һ��ѧ����ͨѶ¼*/
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
                            /*����ͨѶ¼ϵͳ*/ 
////////////////////////////////////////////////////////////////////////////////
void communicate()
{
    int choicecommunicate;
    printf("��ӭ����ͨѶ¼ϵͳ\n");  
    printf("����ѡ���������:\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("1Ϊ����ͨѶ¼��Ϣ\n");
    printf("2Ϊ��ѯͨѶ¼��Ϣ\n");
    printf("3Ϊ�޸�ͨѶ¼��Ϣ\n");
    printf("0Ϊ�˳�ͨѶ¼ϵͳ\n");
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
			printf("ллʹ���ټ�\n");
			printf("�����������\n");
			getch();
			return;
		  }
		default:
			printf("�����д�\n");
	}
        
}   
 ///////////////////////////////////////////////////////////////////////////////
                               /*����ͨѶ¼��Ϣ*/
////////////////////////////////////////////////////////////////////////////////                                  
void inputcommunicate()
{
        FILE *fp;
        int choiceincom='y';
        int i=0;
        if((fp=fopen("empcom.txt","w"))==NULL)
		{
                  printf("���ܹ����ļ�\n"); 
                  printf("���������\n");
                  getch();
                  return;
		}
        printf("��������ͨѶ¼����Ϣ:\n");
        while(choiceincom=='y'||choiceincom=='Y')
        {
               i++;
               printf("��%d��ѧ��\n",i);
               printf("������������:\n");
               scanf("%s",empc[i].name);
               printf("���������ͥ�绰����:\n");
               scanf("%s",empc[i].hometel);
               printf("���������ֻ�����:\n"); 
               scanf("%s",empc[i].handtel);
               printf("���������ַ:\n"); 
               scanf("%s",empc[i].address);
               printf("�Ƿ��������?(y/n)\n");
               choiceincom=getch();
			   fwrite(&empc[i],sizeof(struct communication),1,fp);
       }
       if(toupper(choiceincom)=='N')
       {
         fclose(fp);
         printf("�������,���������\n");
         return;
	   }       
}
////////////////////////////////////////////////////////////////////////////////
                          /*��ѯѧ��ͨѶ¼*/ 
////////////////////////////////////////////////////////////////////////////////
void querycommunicate()
{
       FILE *fp;
       int i=0;
       char qcname[8]; 
       if((fp=fopen("empcom.txt","r"))==NULL)
       {
			 printf("���ܹ����ļ��������������\n");
			 getch();
			 return;
       }
		printf("��������Ҫ��ѯ���˵�����:\n");
		scanf("%s",qcname);
		for(i=0;fread(&empc[i],sizeof(struct communication),1,fp)!=0;i++)
		{
			   if(strcmp(empc[i].name,qcname)==0)
			   {
				   printf("����Ϊ����Ҫ�����Ϣ:\n");
				   printf("����Ϊ%s\n",empc[i].name);
				   printf("��ͥ�绰����Ϊ%s\n",empc[i].hometel); 
				   printf("�ֻ�����Ϊ%s\n",empc[i].handtel);
				   printf("��ͥ��ַΪ%s\n",empc[i].address);
				   printf("��ѯ��ϣ������������\n");
				   getch();
				   fclose(fp);
				   return;
			   }
		}
        printf("û���������ˣ������������\n");
        getch();
        fclose(fp);
        return;
}
////////////////////////////////////////////////////////////////////////////////
                           /*�޸�ѧ��ͨѶ¼*/
////////////////////////////////////////////////////////////////////////////////                            
void changecommunicate()
{
	FILE *fp;
	int i=0;
	char chcname[8];
	int choicecom;
	if((fp=fopen("empcom.txt","w+"))==NULL)
	{
		printf("�򲻿��ļ������������\n");
		getch();
		return;
	}
	printf("����������Ҫ�޸ĵ��˵�����:\n");
	scanf("%s",chcname);
	for(i=0;fread(&empc[i],sizeof(struct communication),1,fp)!=0;i++)
	{
		if(strcmp(empc[i].name,chcname)==0)
		{
			printf("����Ϊ����Ҫ�޸ĵ��˵���Ϣ:\n");
			printf("����Ϊ%s\n",empc[i].name);
			printf("��ͥ�绰����Ϊ%s\n",empc[i].hometel); 
			printf("�ֻ�����Ϊ%s\n",empc[i].handtel);
			printf("��ͥ��ַΪ%s\n",empc[i].address);
			printf("����ѡ��Ҫ�޸ĵĶ���:\n");
			printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
			printf("1�޸ļ�ͥ�绰����\n");
			printf("2�޸��ֻ��绰����\n");
			printf("0�˳�ϵͳ\n");
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
			  printf("�����д�\n");
			}
       
		  }
	}
}
////////////////////////////////////////////////////////////////////////////////
                        /*�޸�ѧ���绰����*/ 
////////////////////////////////////////////////////////////////////////////////
void changetel1()
{
	printf("......��\n");
}

void changetel2()
{
	printf("......��\n");
}

void changetel3()
{
	printf("......��\n");
}
