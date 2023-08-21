/***********************************************************
�ҵ���Ϣ:                                                  *
  ����: ������		����:1985��2��26��                     *
  ��ҵѧУ: 2007���ڳɶ�����ѧ                           *
  �����ַ: �Ĵ�������Ϫ���ɽ��5��                        *
  ��ϵQQ1: 287307421  QQ2: 254540457  QQ3:344245001        *
  ��ϵEmail: wangjianlin1985@126.com 13908064703           *
  �Ա��µ��ַ�� http://taochengxu.taobao.com              *
  ˫���ֳ�������ר����: http://287307421.paipai.com        *
  ��վ: http://www.shuangyulin.com ��������Ч��            *
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
	int num2;      /*ѧ��*/
	char name2[10];/*����*/
	char xing[10];
	int num3;
	int tele;
	float score[3];
	float zong;
	float fen2;
}STUDENT;



/*******************************************************       
����:��ʾ�˵�
��������   
����ֵ����
 *******************************************************/
 void displayMenu()
 {

        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               ѧ���ɼ�����ϵͳ2.0                     +\n");
		printf("+                                                       +\n");
        printf("+                 1. ����γ���Ϣ                       +\n");
        printf("+                 2. ����ѧ����Ϣ�ɼ�                   +\n");
        printf("+                 3. ѧ�����������ѯ                   +\n");
        printf("+                 4. �ɼ���ѯ                           +\n");
        printf("+                 5. ɾ����Ϣ                           +\n");
        printf("+   6. ���ۺϳɼ���ʵ��ѧ���������������ʾ����     +\n");
        printf("+                 7. �������                           +\n");
		printf("+                                                       +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

 }

/*******************************************************       
����:��½��������֤����
������
����1��n
  ���ͣ�char []
  ˵�����û��������   
����ֵ��1��0
  ���ͣ�int
  ˵����1��ʾͨ����֤��0��ʾû��ͨ��
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
����:���ļ�����Ϣ���ṹ��������
������
����1��student[]
  ���ͣ�STUDENT []
  ˵���������洢���ļ�������ѧ����Ϣ
����ֵ��i
  ���ͣ�int
  ˵������ʾʵ�ʶ�ȡ���ĸ���
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
����:�ж�ѧ���Ƿ�Ψһ
������
����1��student[]
  ���ͣ�STUDENT []
  ˵�����洢ѧ����Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����2��stuNumber
  ���ͣ�int
  ˵����Ҫ�жϵ�ѧ�� 
����ֵ��1��0(flag)
  ���ͣ�int
  ˵����1��ʾѧ��Ψһ��0��ʾѧ�Ų�Ψһ
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
	printf("������γ���Ϣ��\n");
	printf("�γ̱�ţ�");
	scanf("%d",&lesson->num1);
	printf("�γ����ƣ�");
	scanf("%s",lesson->name1);
	printf("ѧ�֣�");
	scanf("%d",&lesson->fen);
}
int inputInfo2(STUDENT student[],int length)
{
	int i=length;
	int endFlag=0;

	printf("������ѧ����Ϣ����ѧ��Ϊ0��������\n");
	while(i<N)
	{
		while(1)
		{
			int flag;
			printf("ѧ�ţ�");
			scanf("%d",&student[i].num2);
			if(student[i].num2==0)
			{
				endFlag=1;
				break;
			}
			flag=unique(student,i,student[i].num2);
			if(flag) break;
			printf("��ѧ���Ѿ����ڣ����������룡\n");
		}
		if(endFlag==1)
			break;
		printf("������");
		scanf("%s",student[i].name2);
		printf(" �Ա�");
		scanf("%s",student[i].xing);
		while(1)
		{
			printf("������룺");
			if(scanf("%d",&student[i].num3)==1)
				break;
			printf("�����ʽ���ԣ����������룡\n");
			while(getchar()!='\n')
				continue;
		}
		while(1)
		{
			printf("�绰���룺");
			if(scanf("%d",&student[i].tele)==1)
				break;
			printf("�����ʽ���ԣ����������룡\n");
			while(getchar()!='\n')
				continue;
		}
		while(1)
		{
			printf("ƽʱ�ɼ���");
			if(scanf("%f",&student[i].score[1])==1)
				break;
			printf("�����ʽ���ԣ����������룡\n");
			while(getchar()!='\n')
				continue;
		}
		while(1)
		{
			printf("ʵ��ɼ���");
			if(scanf("%f",&student[i].score[2])==1)
				break;
			printf("�����ʽ���ԣ����������룡\n");
			while(getchar()!='\n')
				continue;
		}
        while(1)
		{
			printf("����ɼ���");
			if(scanf("%f",&student[i].score[3])==1)
				break;
			printf("�����ʽ���ԣ����������룡\n");
			while(getchar()!='\n')
				continue;
		}

		while(getchar()!='\n')
			continue;
		i++;

	}

	return i;
}
/*����һ��ѧ�ţ���������Ļ�����Ϣ����ʾ���*/
void xuehao(STUDENT student[],int length,int stuNum2)
{
	int i=0;
	for(i=0;i<length;i++)
	{
	if(stuNum2==student[i].num2)
	{     
	      printf("�ҵ��������Ļ�����Ϣ�� :%d\n", i);
          printf("%-4s %-4s %-4s %-8s %-8s %-10s %-8s %-8s","ѧ��","����","�Ա�","�������","�绰����","ƽʱ�ɼ�","ʵ��ɼ�","����ɼ�","�ۺϳɼ�","ʵ��ѧ��");
	      printf("\n%-4d %-4s %-4s %-8d %-8d %-4f %-3f %-3f %-8f %-8f\n",student[i].num2,student[i].name2,student[i].xing,student[i].num3,student[i].tele,student[i].score[1],student[i].score[2],student[i].score[3],student[i].zong,student[i].fen2);
	break;
        }
    }
    if(i>=length)
        printf("\n�����ڣ�\n");
}
/*����һ����������������Ļ�����Ϣ����ʾ�����*/
void name(STUDENT student[],int length,char stuname2[])
{
	int i=0;
	for(i=0;i<length;i++)
	{

		if(strcmp(stuname2,student[i].name2)==0)

        {
		printf("�ҵ��������Ļ�����Ϣ�� :%d\n", i);
	printf("%-4s %-4s %-4s %-8s %-8s %-10s %-8s %-8s","ѧ��","����","�Ա�","�������","�绰����","ƽʱ�ɼ�","ʵ��ɼ�","����ɼ�","�ۺϳɼ�","ʵ��ѧ��");
	printf("\n%-4d %-4s %-4s %-8d %-8d %-4f %-3f %-3f %-8f %-8f\n",student[i].num2,student[i].name2,student[i].xing,student[i].num3,student[i].tele,student[i].score[1],student[i].score[2],student[i].score[3],student[i].zong,student[i].fen2);
	break;
        }
    }
    if(i>=length)
        printf("\n�����ڣ�\n");
}
/*����һ��������룬�ɲ�ѯ���������е�ѧ���Ļ�����Ϣ����ʾ�����*/
void suse(STUDENT student[],int length,int stuNum3)
{
	int i=0;
	for(i=0;i<length;i++)
	{
	if(stuNum3==student[i].num3)
        {
	printf("�ҵ��������ǵĻ�����Ϣ�� :%d\n", i);
    printf("%-4s %-4s %-4s %-8s %-8s %-10s %-8s %-8s","ѧ��","����","�Ա�","�������","�绰����","ƽʱ�ɼ�","ʵ��ɼ�","����ɼ�","�ۺϳɼ�","ʵ��ѧ��");
	printf("\n%-4d %-4s %-4s %-8d %-8d %-4f %-3f %-3f %-8f %-8f\n",student[i].num2,student[i].name2,student[i].xing,student[i].num3,student[i].tele,student[i].score[1],student[i].score[2],student[i].score[3],student[i].zong,student[i].fen2);
	break;
        }
    }
    if(i>=length)
        printf("\n�����ڣ�\n");
}
/*����һ��ѧ��ʱ����ѯ�������ĳɼ���ѧ�����*/
void searchNum(STUDENT student[],int length)         //��ѯ
{
 int num2,i;
 printf("\n\t������Ҫ��ѯ��ѧ��:\n\n\t");
 scanf("%d",&num2);
 printf("\n");
 for(i=0;i<length;i++)
 {
  if(num2==student[i].num2)
   break;
 }
 if(i<length)
 {
  printf("\tѧ��\t�ɼ�\n\n");
  printf("\t%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n\n\t",student[i].num2,student[i].name2,student[i].score[1],student[i].score[2],student[i].score[3],student[i].zong,student[i].fen2);
 }
 else
  printf("\t��ѧ�Ų�����\n\n\t");
} 
/**/
void turm(STUDENT student[],int length)
{	int choice,i,j;
    float term;
	printf("���ۺϳɼ�����ѡ��1����ʵ��ѧ������ѡ��2");
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
		/*���ۺϳɼ�����������ʾ���ݡ�*/
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
	/*����ѧ�ֽ���������ʾ���ݡ�*/
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
/*��ӡ*/
void outputInfo(STUDENT student[],int length)
{
	int i=0;
    printf("%-4s %-4s %-4s %-8s %-8s %-10s %-8s %-8s","ѧ��","����","�Ա�","�������","�绰����","ƽʱ�ɼ�","ʵ��ɼ�","����ɼ�","�ۺϳɼ�","ʵ��ѧ��");
	for(i=0;i<length;i++)
	{
	printf("\n%-4d %-4s %-4s %-8d %-8d %-4f %-3f %-3f %-8f %-8f\n",student[i].num2,student[i].name2,student[i].xing,student[i].num3,student[i].tele,student[i].score[1],student[i].score[2],student[i].score[3],student[i].zong,student[i].fen2);
	printf("\n");
	}
	printf("\n\n");
}
 /*******************************************************       
  ����:������
  ��������   
  ����ֵ����
 *******************************************************/

main()
{
	STUDENT student[N];
	LESSON LESSON[3];
    int choice=0,choice2=0; /*select and store menu item  */
    int s=0,arrayLength=0,stuNum2,stuNum3;
    char password[10],stuname2[10];

    /*====��֤�û��Ŀ��ֱ����ȷΪֹ====*/
	do{
		printf("��������");
		scanf("%s",password);

		s=login(password);
     }while(s==0);

	arrayLength=readFromFile(student);

    /*====�����û���ѡ��ִ����Ӧ�Ĳ���.====*/
    while(1)
    {

		displayMenu();

		printf("\n ��ѡ�����Ĳ���(1,2,3,4,5,6,7,8)��\n");
        scanf("%d",&choice);

		switch(choice)
        {

			case 1:
				inputInfo1(LESSON);
				break;

			case 2:
				arrayLength=inputInfo2(student,arrayLength);
				printf("\n����%d��ѧ����Ϣ\n",arrayLength);
				break;
			case 3:
                printf("��ѡ��\n");
                printf("1:����ѧ�Ų���\n");
                printf("2:������������\n");
                printf("3:��������������\n");
                scanf("%d",&choice2);
                switch(choice2)
				{
                   case 1:
                   printf("�����������ҵ�ѧ�ţ�\n");
                   scanf("%d",&stuNum2);
                   xuehao(student,arrayLength,stuNum2);
		           break;
                   case 2:
                   printf("�����������ҵ�������\n");
                   scanf("%s",&stuname2);
                   name(student,arrayLength,stuname2);
		           break;
                   case 3:
                   printf("�����������ҵ�����������\n");
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