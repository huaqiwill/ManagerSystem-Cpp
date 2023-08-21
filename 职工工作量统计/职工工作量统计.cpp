/** File KTVSystem.cpp KTV����ϵͳ
 * ��Ŀ��ַ��
 * CSDN���ͣ�https://blog.csdn.net/HuaQi666
 * �����ߣ�http://bingbingfuhao.cn
 * ���䣺3173484026@qq.com
 * ����ʱ��: 2023/8/21
 */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define FILENAME "worker.bin"
#define N 20
struct worker
{
    int number;         /*����*/
    char name[10];      /*����*/
	char sex;          /*�Ա�*/
    int age;          /*����*/
	int cult;          /*ѧ��*/
	int income;      /*����*/
	char address[20];     /*סַ*/ 
	int phone;       /*�绰*/
	int counts;      /*����*/
	int grade;       /*�ȼ�*/

};
/*******************************************************       
             ����
 *******************************************************/
 void xinxi()
 {

        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               ְ��������ͳ��ϵͳ2.0                     +\n");
		printf("+                                                         +\n");
        printf("+                 1. ְ��������Ϣ����                     +\n");
        printf("+                 2. �����Ϣ                             +\n");
        printf("+                 3. ����������                           +\n");
        printf("+                 4. ������������ ��ӡ��ְ������          +\n");
        printf("+                 5. ��ְ�����Ų�ѯ                       +\n");
		printf("+                 6. ��ְ��������ѯ                       +\n");
        printf("+                 7. ��ְ�����Ž�����Ϣɾ��               +\n");
        printf("+                 8. �������                             +\n");
		printf("+                                                         +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

 } 
/*******************************************************       
                    ��ʾ�˵�
 *******************************************************/
int readFromFile(struct worker w[])
 {
	FILE *fp=NULL;
	int i=0;

	fp=fopen(FILENAME,"rb");  /*���ļ�*/

	if(fp!=NULL)
	{

		while(!feof(fp))    /*���ļ��ж���ѧ��*/
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
                ���ļ�����Ϣ���ṹ��������
 *******************************************************/
void output(struct worker w[],int length)
{
	int i=0;
	if(length==0)
	{
		printf("ϵͳ��û��ְ����Ϣ�����ȳ�ʼ��!\n\n");
		return;
	}
	printf("%s %s %s %s %s %s   %s   %s","ְ����","����","�Ա�","����","ѧ��","����","סַ","�绰");
	for(i=0;i<length;i++)
	{
		printf("\n  %d  %5s %5c %5d %3d %5d  %5s %5d\n",w[i].number,w[i].name,w[i].sex,w[i].age,w[i].cult,w[i].income,w[i].address,w[i].phone);
		printf("\n");
	}
}
/*******************************************************       
                ��Ϣ��ʾ����Ļ
 *******************************************************/
 int f(struct worker w[],int length)
{
	
	 int i=length;
	 while(i<N)
	 {
		  printf("��%d��ְ��\n",i);
		  printf("\n");
		  printf("�������빤��(��ְ����Ϊ0����):\n");/*���빤��*/
		  scanf("%d",&w[i].number);
		  if(w[i].number==0)
			  break;
		  printf("\n");
		  printf("\n");
		  printf("������������:\n");/*��������*/
		  scanf("%s",w[i].name);
		  printf("\n");
		  printf("���������Ա���mΪ��fΪŮ:\n");/*�����Ա�*/
		  scanf("%s",&w[i].sex);
		  printf("\n");
		  printf("��������ѧ��:\n");/*����ѧ��*/
		  printf("1Ϊ��ר2Ϊ����3Ϊ����\n");
		  scanf("%d",&w[i].cult);
		  printf("\n");
          printf("������������:\n");/*��������*/
		  scanf("%d",&w[i].age);
		  printf("\n"); 
          printf("�������빤��:\n");/*���빤��*/
		  scanf("%d",&w[i].income);
		  printf("\n"); 
		  printf("��������סַ:\n");/*�����ַ*/
		  scanf("%s",w[i].address);
		  printf("\n"); 
          printf("��������绰:\n");/*����绰*/
		  scanf("%d",&w[i].phone);
		  printf("\n"); 
          printf("������������:\n");/*��������*/
		  scanf("%d",&w[i].counts);
		  printf("\n"); 
		  i++;
	 }
	
 	 return i;
	 }
 
/*******************************************************       
      ����:����ְ��������Ϣ  
 *******************************************************/
 void input(struct worker w[],int length)
 {
     int i=1;
	 int number,counts;
     printf("�����빤��:");
	 scanf("%d",&number);  
     while(number!=0)
	 {  
		printf("�������������:\n");
		scanf("%d",&counts);
		 for(i=0;i<length;i++)
			if(w[i].number==number)
			{
				w[i].counts+=counts;
                break;
			}
		if(i>=length) 
			printf("���Ų�����:\n");
		printf("�����빤��:");
		scanf("%d",&number);  
	 }
}
/*******************************************************       
      ����:���������벢�ۼ� 
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
        /*  ���� w[i] and w[k] */
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
                     /* ���������Ӵ�С���򲢱������� */
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
		   printf("����:%d ", grade);
		   printf(" ������:%d\n",w[i].counts);
		   printf("%s %s","����","����\n");
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
		   printf("����:%d\n",count);		
		}
	}
	else
		printf("ְ�����ݲ�����!\n");


}
////////////////////////////////////////////////////////////////////////////////
       /* ��ӡ��ְ������������Ρ�ͬһ���ε�ְ�����������ǵĹ��ţ�����*/
////////////////////////////////////////////////////////////////////////////////
void queryInfo(struct worker w[],int length,int stuNum)
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if(stuNum==w[i].number)
        {
			printf("�ҵ���!�����±���:%d\n", i);
		    printf("%s %s %s %s %s %s   %s   %s","ְ����","����","�Ա�","����","ѧ��","����","סַ","�绰");
		    printf("\n  %d  %5s %5c %5d %3d %5d  %5s %5d\n",w[i].number,w[i].name,w[i].sex,w[i].age,w[i].cult,w[i].income,w[i].address,w[i].phone);
			break;
		}	 
	}
    if(i>=length)
        printf("\n��������\n");
}


 /*******************************************************       
              ��ְ�����Ų�ѯ
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
				printf("�ҵ���\n");
				printf("%s %s %s %s %s %s   %s   %s","ְ����","����","�Ա�","����","ѧ��","����","סַ","�绰");
			}
		        printf("\n  %d %5s %5c %5d %3d %5d  %5s %5d\n",w[i].number,w[i].name,w[i].sex,w[i].age,w[i].cult,w[i].income,w[i].address,w[i].phone);
		}
	 }
	 if(found==0)
		 printf("û����������\n");
}
/***********************************************************
                   ��ְ��������ѯ
***********************************************************/
int delet(struct worker w[],int length,int stuNum)
{
	int i,j;
	char choice;
	for(i=0;i<length;i++)
	{
		if(stuNum==w[i].number)
       {
			printf("�±���:%d", i);
		    printf("%s %s %s %s %s %s   %s   %s","ְ����","����","�Ա�","����","ѧ��","����","סַ","�绰");
		    printf("\n  %d %5s %5c %5d %3d %5d  %5s %5d\n",w[i].number,w[i].name,w[i].sex,w[i].age,w[i].cult,w[i].income,w[i].address,w[i].phone);	
			break; 
		}
    }
    if(i<length)
	{
 		printf("��ȷʵҪɾ�����ְ����?(Y/N)");
		scanf("%c",&choice);
		if(choice=='Y'||choice=='y')
		{
			for(j=i;j<length;j++)
				w[j]=w[j+1];
			length--;
 	 	    printf("ɾ���ɹ�!\n");
		}                
	}
    else
        printf("\nָ����ְ��������!\n");
	return length;
}

/********************************************************
                 ��ְ����ɾ��ְ����Ϣ
********************************************************/
void writeToFile(struct worker w[],int length)
{
	FILE *fp=NULL;
	int i=0;

	fp=fopen(FILENAME,"wb");

	if(fp==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}

	for(i=0;i<length;i++)
		fwrite(w+i,sizeof(worker),1,fp);

	fclose(fp);

}
/********************************************************
                �ṹ�������е�ְ����Ϣ������ļ�
********************************************************/
void main ()
{   
	 int choice;
	 struct worker w[N];
	 int NUM;char stuName[100];
	 int stuNum;
	 int length=0;
	 length=readFromFile(w);//����
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
			  printf("����������ѯ��ְ����");
			  scanf("%d",&NUM);
		      queryInfo(w,length,NUM);
		     break; 
		  case 6:
		      printf("�����������ҵ�����:");
			  scanf("%s",&stuName);
			  cha(w,length,stuName);
		     break; 
          case 7:
              printf("��������ɾ����ְ����");
			  scanf("%d",&stuNum);
		      length=delet(w,length,stuNum);
		     break; 
		  case 8:
			  {    
				   writeToFile(w,length);//����
			       printf("ллʹ���ټ�\n");
			       exit(0);
			  }
		   default:
			   {
			       printf("�����д�������������:\n");
			   }
		  }
	}while(1);
}
////////////////////////////////////////////////////////////////////////////////
                     /*  ְ����Ϣ����ϵͳ��������--ϵͳ����*/
////////////////////////////////////////////////////////////////////////////////