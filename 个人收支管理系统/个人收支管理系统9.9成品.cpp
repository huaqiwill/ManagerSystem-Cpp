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
#include "string.h"
#define SIZE 12
#define FILENAME "information.txt"


struct IN
{
    char name[10];      /*����*/
    char sex[5];        /*�Ա�*/
	int  age;			/*����*/
	char address[100];   /*סַ*/
	int  telephone[15]; /*�绰*/
	float  yue;		/*���*/
}infor;

struct MI
{
	int month;
	float into;
	float outto;
	char inaim[20];
	char outaim[20];
}ioi[];/*���ڣ�����/֧��  ���  ������Դ/֧��Ŀ��*/


void displayMenu()
 {

        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               ������֧����ϵͳ                        +\n");
		printf("+                                                       +\n");
        printf("+                 1. ������Ϣ����                       +\n");
        printf("+                 2. ����µ���֧��Ϣ                   +\n");
        printf("+                 3. ���·������ӡ����֧�嵥           +\n");
        printf("+                 4. ɾ��������Ϣ                       +\n");
        printf("+                 5. �޸�������Ϣ                       +\n");
        printf("+                 6. ͳ��������                         +\n");
        printf("+                 7. ͳ����֧��                         +\n");
		printf("+                 8. ��ѯ��ǰ������Ϣ�����             +\n");
	    printf("+                 9.����֧��Ϣ���뵽�ļ�                +\n");
		printf("+                 10.���ļ��ж�����֧��Ϣ               +\n");
		printf("+                 11.�Ѹ�����Ϣ���뵽�ļ�               +\n");
		printf("+                 12.���ļ��ж��������Ϣ               +\n");
		printf("+                 13.��������                           +\n");
		printf("+                                                       +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
 

/*******************************************************       
����:���ļ�����Ϣ���ṹ��������
������
����1��ioi[]
  ���ͣ�MI
  ˵���������洢���ļ���������֧��Ϣ
����ֵ��i
  ���ͣ�int
  ˵������ʾʵ�ʶ�ȡ���ĸ���
 *******************************************************/
 int readFromFile1(MI ioi[])
 {
	FILE *fp=NULL;
	int i=0;

	fp=fopen(FILENAME,"rb");  /*���ļ�*/

	if(fp!=NULL)
	{

		while(!feof(fp))    /*���ļ��ж����·�*/
		{
     
			if(fread(ioi+i,sizeof(MI),1,fp))
				i++;
		}
		printf("��֧��Ϣ�Ѷ���\n");
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
		printf("���ļ�����\n");
		exit(0);
	}
	if(!feof(fp))
		{	fread(infor,sizeof(struct IN),1,fp);
		}
	printf("������Ϣ�Ѷ���\n");
	fclose(fp);
}


void inputInfo1(struct IN *infor)
{
	int endFlag=0;
	printf("�����������Ϣ��\n");
	while(1)
	{
	printf("������");
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
	printf("�Ա�");
	scanf("%s",infor->sex);
	printf("\n");
	break;
	}
	while(1)
	{
	printf("���䣺");
	scanf("%d",&infor->age);
	printf("\n");
	break;
	}
	while(1)
	{
	printf("סַ��");
	scanf("%s",infor->address);
	printf("\n");
	break;
	}
	while(1)
	{
	printf("�绰��");
	scanf("%d",&infor->telephone);
	printf("\n");
	break;
	}
	while(1)
	{
	printf("��");
	scanf("%f",&infor->yue);
	printf("\n");
	break;
	}
	while(getchar()!='\n')
	continue;
}
/*******************************************************       
����:�ж��·��Ƿ�Ψһ
������
����1��ioi[]
  ���ͣ�MI
  ˵�����洢������Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
  ����2�� ioimonth
  ���ͣ�int
  ˵����Ҫ�жϵ��·� 
����ֵ��1��0(flag)
  ���ͣ�int
  ˵����1��ʾ�·�Ψһ��0��ʾ�·ݲ�Ψһ
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

	printf("�Ƿ�ȷ�Ͻ�������0Ϊ��������\n");
	while(i<SIZE)
	{
		while(1)
		{
			int flag;
			printf("�·ݣ�");
			scanf("%d",&ioi[i].month);
			if(ioi[i].month>12||ioi[i].month<0)
				printf("�·��������������룡\n");
			else if(ioi[i].month==0)
			{
				endFlag=1;
				break;
			}
			if(ioi[i].month<=12&&ioi[i].month>0)
			{
				flag=unique(ioi,i,ioi[i].month);
			    if(flag) break;
			    printf("���·��Ѿ����ڣ����������룡\n");
			}
		}

		if(endFlag==1)
			break;
		while(1)
		{
		printf("���룺");
		scanf("%f",&ioi[i].into);
		printf("\n");
		break;
		}
		while(1)
		{
		printf("֧����");
		scanf("%f",&ioi[i].outto);
		printf("\n");
		break;
		}
		while(1)
		{
		printf("������Դ��");
		scanf("%s",ioi[i].inaim);
		printf("\n");
		break;
		}
		while(1)
		{
		printf("֧��Ŀ�ģ�");
		scanf("%s",ioi[i].outaim);
		printf("\n");
		break;
		}
		while(getchar()!='\n')
		continue;
		i++;

	}

	return i;/*������ɺ��ж��ٸ���֧��Ϣ*/
}

			   
/*******************************************************       
����:����֧��Ϣ���·ݴ�С��������(ѡ��)����ӡ
������
����1��ioi
  ���ͣ�IM
  ˵���������洢��֧��Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����ֵ����
 *******************************************************/
void sortScore(MI ioi[],int length)
{
	int i=0,j=0,k=0;
	MI s;

	for(i=0;i<length;i++)
	{       /*  ��δ�ź������֧��Ϣ���ҵ��·���С����С�����±����k */
		k=i;
		for(j=i+1;j<length;j++)
			if(ioi[j].month<ioi[k].month)
				k=j;

        /*  ���� ioi[i] and ioi[k] */
        s=ioi[k];
        ioi[k]=ioi[i];
        ioi[i]=s;
	}

}

void outputInfo(MI ioi[],int length)
{
	int i=0;

	printf("    �·�           ����         ֧��               ������Դ          ֧��Ŀ��\n\n");
	for(;i<length;i++)
	{
	printf("%8d   %14f   %14f   %14s   %14s",ioi[i].month,ioi[i].into,ioi[i].outto,ioi[i].inaim,ioi[i].outaim);
	printf("\n");
	}
	printf("\n\n");
}

/*******************************************************       
����:�����·�ɾ����������֧��Ϣ
������
����1��ioi
  ���ͣ�IM
  ˵���������洢��֧��Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����3��stuNum
  ���ͣ�int
  ˵������ʾҪɾ�����·�
����ֵ��length
		ɾ�����·ݵĸ���        
 *******************************************************/
int deleteInfoByNumber(MI ioi[],int length,int stuNum)
{
	int i,j;
	char choice;
	for(i=0;i<length;i++)
	{
		if(stuNum==ioi[i].month)
       {
			printf("�ҵ���!�����±���:%d\n", i);

			printf("%d %f %f %s %s","�·�",      "����",     "֧��",      "������Դ",      "֧��Ŀ��\n");
			printf("%d %5f %5f %5s %5s\n",ioi[i].month,ioi[i].into,ioi[i].outto,ioi[i].inaim,ioi[i].outaim);		
			break; 
		}
    }
    if(i<length)
	{
 		printf("��ȷʵҪɾ������µ���֧��Ϣ��?(Y/N)");
		getchar();
		scanf("%c",&choice);
		if(choice=='Y'||choice=='y')
		{
			for(j=i;j<length;j++)
				ioi[j]=ioi[j+1];
			length--;
 	 	    printf("ɾ���ɹ�!\n");
		}                
	}
    else
        printf("\nָ�����·���֧��Ϣ������!\n");
	return length;
}








/******************************************************* 
����:�����·��޸���������Ϣ
������
����1��ioi
  ���ͣ�MI
  ˵���������洢��֧��Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����3��stuNum
  ���ͣ�int
  ˵������ʾҪ�޸ĵ���Ϣ���·�
����ֵ����
 *******************************************************/
void editInfoByNumber(MI ioi[],int length,int stuNum)
{
	int i=0;
	int choice,flag;
	for(i=0;i<length;i++)
	{
		if(stuNum==ioi[i].month)
       {
			printf("�ҵ���!�����±���:%d\n", i);
			printf("%d %f %f %s %s","  �·�",       "����",    "֧��",      "������Դ",     "֧��Ŀ��\n");
			printf("%d %f %f %s %s\n",ioi[i].month,ioi[i].into,ioi[i].outto,ioi[i].inaim,ioi[i].outaim);		
			do{
 				printf("\n");
				printf("***********************\n");
				printf("   1:�·�\n");
				printf("   2:����\n");
				printf("   3:֧��\n");
				printf("   4:������Դ\n");
				printf("   5:֧��Ŀ��\n");
				printf("***********************\n");          
				printf("���������޸ĵ��ֶ�(0�˳�):");
				scanf("%d",&choice);
				switch(choice)
				{ case 1: 
					   printf("�������·�:");
					   scanf("%d",&stuNum);
					   flag=unique(ioi,length,stuNum);
					   if(!flag)
						   printf("���·��Ѿ�����!\n");
					   else
					   {   ioi[i].month=stuNum;
						   printf("�޸ĳɹ�\n");
					   } 
					   break;
				   case 2: 
					   printf("����������:");
					   scanf("%f",ioi[i].into);
					   printf("�޸ĳɹ�\n");
					   break;
				   case 3: 
					   printf("������֧��:");
					   scanf("%f",&ioi[i].outto);
					   printf("�޸ĳɹ�\n");
					   break;
				   case 4: 
					   printf("������������Դ:");
					   scanf("%s",ioi[i].inaim);
					   printf("�޸ĳɹ�\n");
					   break;
				   case 5: 
					   printf("������֧��Ŀ��:");
					   scanf("%s",ioi[i].outaim);
					   printf("�޸ĳɹ�\n");
					   break;
				   case 0: 
					   break;
				}                
			}while(choice!=0);
			break; 
		}
    }
    if(i>=length)
        printf("\nָ�����·ݲ�����!\n");
}
   
float WorkSumInto(MI ioi[],int length)
{
	int m;
	float suminto=0.0;
	for(m=0;m<length;m++)
	suminto=suminto+ioi[m].into;
	printf("Ŀǰ������Ϊ%f\n",suminto);

	return suminto;
}

float WorkSumOutto(MI ioi[],int length)
{
	int i,m;
	float sumoutto=0.0;
	i=length;
	for(m=0;m<i;m++)
	sumoutto=sumoutto+ioi[m].outto;
	printf("Ŀǰ��֧��Ϊ%f\n",sumoutto);
	return sumoutto;
}

void Inputinformation(struct IN infor,struct MI ioi[],int length)
{
	float sum=0.0,i=0.0,j=0.0;
	i=WorkSumOutto(ioi,length);
	j=WorkSumInto(ioi,length);
	sum=infor.yue-i+j;
	printf("������ �Ա� ���䣻 סַ�� �绰�� �� \n");
	printf("%2s %5s %5d %5s %5d %5f\n",infor.name,infor.sex,infor.age,infor.address,infor.telephone,sum);
}




void writeToFile2(struct IN infor)
{
	FILE *fp=NULL;
	int i=0;

	fp=fopen("personal.txt","wb");

	if(fp==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}
	fwrite(&infor,sizeof(struct IN),1,fp);
	printf("��Ϣ�ѱ��浽�ļ�personal.txt��\n");
	fclose(fp);
}







/*******************************************************       
����:�ṹ�������е���֧��Ϣ������ļ�
������
����1��ioi[]
  ���ͣ�MI
  ˵���������洢���ļ�������ѧ����Ϣ
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����ֵ����
 *******************************************************/

void writeToFile1(MI ioi[],int length)
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
		fwrite(ioi+i,sizeof(MI),1,fp);
	printf("��Ϣ�ѱ��浽�ļ�information.txt��\n");
	fclose(fp);

}



void main()
{

    struct IN infor;
	struct MI ioi[SIZE];
	int choice = 0; /*select and store menu item  */
    int s=0,arrayLength=0,ioiy=0,ioix=0;

    /*====�����û���ѡ��ִ����Ӧ�Ĳ���.====*/
    while(1)
    {

		displayMenu();

		printf("\n ��ѡ�����Ĳ���(1,2,3,4,5,6,7,8,9,10,11,12,13)\n");
        scanf("%d",&choice);

		switch(choice)
        {

			case 1:
				printf("ϵͳ��û�и�����Ϣ�����ȳ�ʼ����\n\n");
				inputInfo1(&infor);
				break;
			case 2:
				arrayLength=inputInfo2(ioi,arrayLength);
				if(arrayLength==0)
				printf("ϵͳ��û����֧��Ϣ�����ȳ�ʼ����\n\n");
				arrayLength=inputInfo2(ioi,arrayLength);
				printf("\n����%d������֧��Ϣ\n",arrayLength);
				break;
			case 3:
				sortScore(ioi,arrayLength);
				outputInfo(ioi,arrayLength);
				break;
			case 4:
				printf("��������ɾ���·ݣ�\n");
				scanf("%d",&ioiy);
				deleteInfoByNumber(ioi,arrayLength,ioiy);
				break;
			case 5:
				printf("���������޸��·ݣ�\n");
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

