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
#define FILENAME "zhigong.txt"
typedef struct
{
    int num;         /*ְ�����*/
    char n1[10];     /*ְ������*/
	char n2[10];     /*�Ա�*/
	int nianling;    /*����*/
	char xueli[20];  /*ѧ��*/
    int gongzi;      /*����*/
    char addr[10];       /*סַ*/
    int tele;        /*�绰*/
}GONG;
void displayMenu()
 {

        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               ְ����Դ����ϵͳ                                  +\n");
		printf("+                                                                 +\n");
        printf("+            1. ¼��ְ����Ϣ                                      +\n");
        printf("+            2. ��ʾȫ��ְ����Ϣ                                  +\n");
        printf("+            3. ���ݹ��Ų�ѯ                                      +\n");
        printf("+            4. ����ѧ����ѯ                                      +\n");
		printf("+            5. ���ݹ��ʲ�ѯ                                      +\n");
        printf("+            6. ���ݹ���ɾ����¼                                  +\n");
        printf("+            7. ���ݹ��ʴӴ�С��                                +\n");
        printf("+            8. ���沢����                                        +\n");
		printf("+                                                                 +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

 }
int login(char password[])
 {
     static char key[10]="123";
     if(strcmp(password,key)==0)
       return 1;
     else
       return 0;
  }
int readFromFile(GONG gong[])
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
			if(fread(gong+i,sizeof(GONG),1,fp))
				i++;
		}

		fclose(fp);
	}
    return i;
}
int unique(GONG gong[],int length,int JN)
{
	int flag=1,i;
	for(i=0;i<length;i++)
	{
		if(gong[i].num==JN)
		{ 
			flag=0;
			break;
		}
	}
return flag;
}
/*����ְ����Ϣ��¼*/
int inputInfo(GONG gong[],int length)
{
	int i=length;
	int endFlag=0;
	printf("������ְ����Ϣ����Ϊ���0��������\n");
	while(i<N)
	{
		while(1)
		{
			int flag;
			printf("ְ����ţ�");
			scanf("%d",&gong[i].num);
			if(gong[i].num==0)
			{
				endFlag=1;
				break;
			}
			flag=unique(gong,i,gong[i].num);
			if(flag) break;
			printf("��ְ���Ѿ����ڣ����������룡\n");
		}
		if(endFlag==1)
			break;
		printf("ְ�����ƣ�");
		scanf("%s",gong[i].n1);
		printf("�Ա�");
		scanf("%s",gong[i].n2);
		while(1)
		{
			printf("���䣺");
			if(scanf("%d",&gong[i].nianling)==1)
				break;
			printf("�����ʽ���ԣ����������룡\n");
			while(getchar()!='\n')
				continue;
		}
       	printf("ѧ����");
		scanf("%s",gong[i].xueli);
        while(1)
		{
			printf("���ʣ�");
			if(scanf("%d",&gong[i].gongzi)==1)
				break;
			printf("�����ʽ���ԣ����������룡\n");
			while(getchar()!='\n')
				continue;
		}
		printf("סַ��");
		scanf("%s",gong[i].addr);
		while(1)
		{
			printf("�绰��");
			if(scanf("%d",&gong[i].tele)==1)
				break;
			printf("�����ʽ���ԣ����������룡\n");
			while(getchar()!='\n')
				continue;
		}

i++;
	
}
return i;
}
/*��ʾȫ��ְ����Ϣ*/
void outputInfo(GONG gong[],int length)
{
	int i=0;

	printf("%-8s %-8s %-4s %-4s %-4s %-4s %-4s %-4s","ְ�����","ְ������","�Ա�","����","ѧ��","����","סַ","�绰\n\n");
	for(i=0;i<length;i++)
	{
		printf("%-8d %-8s %-4s %-4d %-4s %-4d %-4s %-4d",gong[i].num,gong[i].n1,gong[i].n2,gong[i].nianling,gong[i].xueli,gong[i].gongzi,gong[i].addr,gong[i].tele);
	    printf("\n");
	}
	printf("\n\n");
}
/*���ݹ��Ų�ѯ��Ϣ*/
void ghInfo(GONG gong[],int length,int gh)
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if(gh==gong[i].num)
        {
			printf("�ҵ�����������Ϣ��:%d\n", i);
		    printf("%-8s %-8s %-4s %-4s %-4s %-4s %-4s %-4s","ְ�����","ְ������","�Ա�","����","ѧ��","����","סַ","�绰\n\n");
		    printf("%-8d %-8s %-4s %-4d %-4s %-4d %-4s %-4d",gong[i].num,gong[i].n1,gong[i].n2,gong[i].nianling,gong[i].xueli,gong[i].gongzi,gong[i].addr,gong[i].tele);
		    break;
        }
    }
    if(i>=length)
    printf("\n�����ڣ�\n");
}
/*���ݰ�ѧ����ѯ��Ϣ*/
void xlInfo(GONG gong[],int length,char xl[])
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if(strcmp(xl,gong[i].xueli)==0)
        {
			printf("�ҵ�����������Ϣ��:%d\n", i);
		    printf("%-8s %-8s %-4s %-4s %-4s %-4s %-4s %-4s","ְ�����","ְ������","�Ա�","����","ѧ��","����","סַ","�绰\n\n");
		    printf("%-8d %-8s %-4s %-4d %-4s %-4d %-4s %-4d",gong[i].num,gong[i].n1,gong[i].n2,gong[i].nianling,gong[i].xueli,gong[i].gongzi,gong[i].addr,gong[i].tele);
        }
    }
    if(i>=length)
    printf("\n�����ڣ�\n");
}
/*���ݹ��ʲ�ѯ��Ϣ*/
void gzInfo(GONG gong[],int length,int gz)
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if(gz==gong[i].gongzi)
        {
			printf("�ҵ�����������Ϣ��:%d\n", i);
		    printf("%-8s %-8s %-4s %-4s %-4s %-4s %-4s %-4s","ְ�����","ְ������","�Ա�","����","ѧ��","����","סַ","�绰\n\n");
		    printf("%-8d %-8s %-4s %-4d %-4s %-4d %-4s %-4d",gong[i].num,gong[i].n1,gong[i].n2,gong[i].nianling,gong[i].xueli,gong[i].gongzi,gong[i].addr,gong[i].tele);
        }
    }
    if(i>=length)
    printf("\n�����ڣ�\n");
}
/*���ݹ���ɾ����¼*/
int shanchu(GONG gong[],int length,int gh)
{
	int i,j=0;
	for(i=0;i<length;i++)
	{
		if(gh==gong[i].num)
		{
			length=length-1;
			for(j=i;j<length;j++)
			{
				gong[j].num=gong[j+1].num;
				strcpy(gong[j].n1,gong[j+1].n1);
		        strcpy(gong[j].n2,gong[j+1].n2);
				gong[j].nianling=gong[j+1].nianling;
				strcpy(gong[j].xueli,gong[j+1].xueli);
				gong[j].gongzi=gong[j+1].gongzi;
				strcpy(gong[j].addr,gong[j+1].addr);
				gong[j].tele=gong[j+1].tele;				
			}
			i--;
		}
	}
	return length;
}

/*���ݹ��ʴӴ�С����*/
void sortScore(GONG gong[],int length)
{
	int i=0,j=0,k=0;
	GONG s;
	for(i=0;i<length;i++)
	{
		k=i;
		for(j=i+1;j<length;j++)
			if(gong[j].gongzi>gong[k].gongzi)
				k=j;
        s=gong[k];
        gong[k]=gong[i];
        gong[i]=s;
	}
    printf("%-8s %-8s %-4s %-4s %-4s %-4s %-4s %-4s","ְ�����","ְ������","�Ա�","����","ѧ��","����","סַ","�绰\n\n");
	for(i=0;i<length;i++)
	{
		printf("%-8d %-8s %-4s %-4d %-4s %-4d %-4s %-4d",gong[i].num,gong[i].n1,gong[i].n2,gong[i].nianling,gong[i].xueli,gong[i].gongzi,gong[i].addr,gong[i].tele);
	    printf("\n");
	}
	printf("\n\n");
}
void writeToFile(GONG gong[],int length)
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
		fwrite(gong+i,sizeof(GONG),1,fp);

	fclose(fp);

}

main()
{
	GONG gong[N];

    int choice = 0;
    int s=0,arrayLength=0,gh,gz;
    char password[10];
    char xl[10];
	

    /*====��֤�û��Ŀ��ֱ����ȷΪֹ====*/
	do{
		printf("��������");
		scanf("%s",password);

		s=login(password);
     }while(s==0);

	arrayLength=readFromFile(gong);

    /*====�����û���ѡ��ִ����Ӧ�Ĳ���.====*/
    while(1)
    {

		displayMenu();

		printf("\n ��ѡ�����Ĳ���(1,2,3,4,5,6,7,8)��\n");
        scanf("%d",&choice);

		switch(choice)
        {

			case 1:
				arrayLength=inputInfo(gong,arrayLength);
				printf("\n����%d��ְ����Ϣ\n",arrayLength);
				break;

			case 2:
				if(arrayLength==0)
				printf("ϵͳ��û��ְ����Ϣ�����ȳ�ʼ����\n\n");
				else
				outputInfo(gong,arrayLength);
				break;
  
			case 3:
				printf("�����������ҵ�ְ����ţ�\n");
				scanf("%d",&gh);
				ghInfo(gong,arrayLength,gh);
				break;
 
			case 4:
				printf("�����������ҵ�ѧ����\n");
				scanf("%s",&xl);
				xlInfo(gong,arrayLength,xl);
				break;
            case 5:
				printf("�����������ҵĹ��ʣ�\n");
				scanf("%d",&gz);
				gzInfo(gong,arrayLength,gz);
				break;
            case 6:
				printf("��������ɾ����ְ����ţ�\n");
                scanf("%d",&gh);
				shanchu(gong,arrayLength,gh);
				break;
			case 7:
				sortScore(gong,arrayLength);
				break;
            case 8:
				writeToFile(gong,arrayLength);
				exit(0);
				break;
        }
    }

}
