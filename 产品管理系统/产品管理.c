/** File KTVSystem.cpp KTV����ϵͳ
 * ��Ŀ��ַ��
 * CSDN���ͣ�https://blog.csdn.net/HuaQi666
 * �����ߣ�http://bingbingfuhao.cn
 * ���䣺3173484026@qq.com
 * ����ʱ��: 2023/8/21
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
    int number1;        /*��Ʒ���*/
    char name1[10];     /*��Ʒ����*/
    int number2;        /*��Ʒ���ͱ��*/
    char name2[10];     /*��Ʒ���*/
    char name3[10];     /*������λ*/
    int d2;             /*��Ʒ����*/
    int d3;             /*�ο��۸�*/
    struct date jhrq;   /*��������*/
    struct date yxrq;   /*��Ч����*/


};

/*******************************************************       
����:��ʾ�˵�
��������   
����ֵ����
 *******************************************************/
 void displayMenu()
 {

        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               ��Ʒ��Ϣ����ϵͳ2.0                     +\n");
        printf("+                                                       +\n");
        printf("+                 1. ������Ϣ                           +\n");
        printf("+                 2. ��Ʒ��Ϣ���޸�                     +\n");
        printf("+                 3. ��Ʒ��Ϣ��ɾ��                     +\n");
        printf("+                 4. ���ݲ�Ʒ���Ʋ�ѯ��Ʒ��Ϣ��         +\n");
        printf("+                 5. ��ʾȫ����Ʒ��¼                   +\n");
        printf("+                 6. ���ο��۸��С������ʾ��¼         +\n");
        printf("+                 7. ��ʾȫ�����ڲ�Ʒ��Ϣ               +\n");
        printf("+                 8. ���浽�ļ�                         +\n");
        printf("+                 9. ���ļ���                           +\n");
        printf("+                 10.�������                           +\n");
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
     static char key[10]="123";
     if(strcmp(password,key)==0)
       return 1;
     else
       return 0;
  }
  /*******************************************************       
����:���ļ�����Ϣ���ṹ��������
������
����1��chanpin[]
  ���ͣ�CHANPIN []
  ˵���������洢���ļ������Ĳ�Ʒ��Ϣ
����ֵ��i
  ���ͣ�int
  ˵������ʾʵ�ʶ�ȡ���ĸ���
 *******************************************************/
 int readFromFile(struct chanpin stu[])
 {
    FILE *fp;
    int i=0;
    if((fp=fopen(FILENAME,"rb"))==NULL) /*���ļ�*/
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
     printf("���(0�˳�)\n��");
    
        
    while(i<N)
    {
    
        while(1)
        {
            int flag;
            printf("���\n:");
            scanf("%d",&stu[i].number1);
            if(stu[i].number1==0)
            {
                endFlag=1;
                break;
            }
            flag=unique(stu,i,stu[i].number1,i);
            if(flag) break;
            printf("�ñ���Ѿ����ڣ�����������!\n");
        }
        if(endFlag==1)
            break;
    printf("����\n��");
    scanf("%s",stu[i].name1);
    printf("���ͱ��\n��");
    scanf("%d",&stu[i].number2);
    printf("��Ʒ���\n��");
    scanf("%s",stu[i].name2);
    printf("������λ\n��");
    scanf("%s",stu[i].name3);
    printf("��Ʒ����\n��");
    scanf("%d",&stu[i].d2);
    printf("�ο��۸�\n��");
    scanf("%d",&stu[i].d3);
    printf("��������\n��");
    scanf("%d-%d-%d",&stu[i].jhrq.year,&stu[i].jhrq.month,&stu[i].jhrq.day);
    printf("��Ч����\n��");
    scanf("%d-%d-%d",&stu[i].yxrq.year,&stu[i].yxrq.month,&stu[i].yxrq.day);
    i++;
    }
    
    
    
   return i;

}
/*******************************************************       
����:���ṹ�������еĲ�Ʒ��Ϣ��ʾ����Ļ
������
����1��chanpin[]
  ���ͣ�chanpin stu[]
  ���������洢��Ʒ��Ϣ������
����2��N
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����ֵ����
 *******************************************************/
void print(struct chanpin stu[],int n)
{
    int i=0;
    if (n>0)
        printf("%-4s %-10s %-4s %-4s %-4s %-4s %-4s %-4s %-4s","��Ʒ���","����","���ͱ��","��Ʒ���","������λ",
        "��Ʒ����","�ο��۸�","��������","��Ч��\n\n");
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
����:�������ƴ������в��Ҳ�Ʒ
������
����1��chanpin[]
  ���ͣ�chanpin stu[]
  ˵���������洢��Ʒ��Ϣ������
����2��N
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����3��stuName
  ���ͣ�char
  ˵������ʾҪ���ҵĲ�Ʒ������
����ֵ����
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
                printf("�ҵ���\n");
                printf("%-4s %-10s %-4s %-4s %-4s %-4s %-4s %-4s %-4s","��Ʒ���","����","���ͱ��","��Ʒ���","������λ",
        "��Ʒ����","�ο��۸�","��������","��Ч��\n\n");
            }
        printf("%-4d %6s %10d %9s %9s %8d %8d %9d-%d-%d %6d-%d-%d",stu[i].number1,stu[i].name1,stu[i].number2,
        stu[i].name2,stu[i].name3,stu[i].d2,stu[i].d3,stu[i].jhrq.year,stu[i].jhrq.month,stu[i].jhrq.day,
        stu[i].yxrq.year,stu[i].yxrq.month,stu[i].yxrq.day);
        }
    }
    if(found==0)
        printf("\nָ�������Ʋ�����!\n");
}


void writeToFile(struct chanpin stu[],int n)
{
    FILE *fp=NULL;
    int i=0;

    fp=fopen(FILENAME,"wb");

    if(fp==NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }

    for(i=0;i<n;i++)
        fwrite(&stu[i],sizeof(struct chanpin),1,fp);

    fclose(fp);

}

/*******************************************************       
����:���ݱ���޸������б��
������
����1��chanpin
  ���ͣ�stu []
  ˵���������洢��Ʒ��Ϣ�������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����3��stuNumber
  ���ͣ�int
  ˵������ʾҪ�޸ĵĲ�Ʒ�ı��
����ֵ����
 *******************************************************/
void editInfoByNumber(struct chanpin stu[],int length,int stuNumber)
{
    int i=0;
    int choice,flag;
    for(i=0;i<length;i++)
    {
        if(stuNumber==stu[i].number1)
       {
            printf("�ҵ���!�����±���:%d\n", i);

            printf("%-4s %-10s %-4s %-4s %-4s %-4s %-4s %-4s %-4s","��Ʒ���","����","���ͱ��","��Ʒ���","������λ",
        "��Ʒ����","�ο��۸�","��������","��Ч��\n\n");
     printf("%-4d %6s %10d %9s %9s %8d %8d %9d-%d-%d %6d-%d-%d",stu[i].number1,stu[i].name1,stu[i].number2,
        stu[i].name2,stu[i].name3,stu[i].d2,stu[i].d3,stu[i].jhrq.year,stu[i].jhrq.month,stu[i].jhrq.day,
        stu[i].yxrq.year,stu[i].yxrq.month,stu[i].yxrq.day);
     do{
                printf("\n");
                printf("***********************\n");
                printf("   1:���    \n");
                printf("   2:����    \n");
                printf("   3:���ͱ��\n");
                printf("   4:��Ʒ���\n");
                printf("   5:������λ\n");
                printf("   6:��Ʒ����\n");
                printf("   7:�ο��۸�\n");
                printf("   8:��������\n");
                printf("   9:��Ч��  \n");
                printf("***********************\n");          
                printf("���������޸ĵ��ֶ�(0�˳�):");
                scanf("%d",&choice);
                switch(choice)
                { case 1: 
                       printf("��������:");
                       scanf("%d",&stuNumber);
                       flag=unique(stu,length,stuNumber,i);
                       if(!flag)
                           printf("�ñ���Ѿ�����!\n");
                       else
                       {   stu[i].number1=stuNumber;
                           printf("�޸ĳɹ�\n");
                       } 
                       break;
                   case 2: 
                       printf("����������:");
                       scanf("%s",stu[i].name1);
                       printf("�޸ĳɹ�\n");
                       break;
                   case 3: 
                       printf("���������ͱ��:");
                       scanf("%d",&stu[i].number2);
                       printf("�޸ĳɹ�\n");
                       break;
                   case 4: 
                       printf("�������Ʒ���:");
                       scanf("%s",stu[i].name2);
                       printf("�޸ĳɹ�\n");
                       break;
                   case 5: 
                       printf("�����������λ:");
                       scanf("%s",stu[i].name3);
                       printf("�޸ĳɹ�\n");
                       break;
                   case 6: 
                       printf("�������Ʒ����:");
                       scanf("%d",&stu[i].d2);
                       printf("�޸ĳɹ�\n");
                       break;
                   case 7: 
                       printf("������ο��۸�:");
                       scanf("%d",&stu[i].d3);
                       printf("�޸ĳɹ�\n");
                       break;
                   case 8: 
                       printf("�������������:");
                       scanf("%d,%d,%d",&stu[i].jhrq.year,&stu[i].jhrq.month,&stu[i].jhrq.day);
                       printf("�޸ĳɹ�\n");
                       break;
                    case 9: 
                       printf("��������Ч��:");
                       scanf("%d,%d,%d",&stu[i].yxrq.year,&stu[i].yxrq.month,&stu[i].yxrq.day);
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
        printf("\nָ���ı�Ų�����!\n");
}
 /*******************************************************       
����:���ݱ��ɾ�������б��
������
����1��chanpin
  ���ͣ�stu []
  ˵���������洢������Ϣ������
����2��length
  ���ͣ�int
  ˵������ʾʵ������ĳ��� 
����3��stuNumber
  ���ͣ�int
  ˵������ʾҪ�޸ĵ����Ƶı��
����ֵ��length
        ɾ�������Ƶĸ���        
 *******************************************************/
int deleteInfoByNumber(struct chanpin stu[],int length,int stuNumber)
{
    int i,j;
    char choice;
    for(i=0;i<length;i++)
    {
        if(stuNumber==stu[i].number1)
       {
            printf("�ҵ���!�����±���:%d\n", i);

              printf("%-4s %-10s %-4s %-4s %-4s %-4s %-4s %-4s %-4s","��Ʒ���","����","���ͱ��","��Ʒ���","������λ",
        "��Ʒ����","�ο��۸�","��������","��Ч��\n\n");
         printf("%-4d %6s %10d %9s %9s %8d %8d %9d-%d-%d %6d-%d-%d",stu[i].number1,stu[i].name1,stu[i].number2,
        stu[i].name2,stu[i].name3,stu[i].d2,stu[i].d3,stu[i].jhrq.year,stu[i].jhrq.month,stu[i].jhrq.day,
        stu[i].yxrq.year,stu[i].yxrq.month,stu[i].yxrq.day);
           break; 
        }
    }
    if(i<length)
    {
        printf("��ȷʵҪɾ�����������?(Y/N)\n");
        getchar();
        scanf("%c",&choice);
        if(choice=='Y'||choice=='y')
        {
            for(j=i;j<length;j++)
                stu[j]=stu[j+1];
            length--;
            printf("ɾ���ɹ�!\n");
        }                
    }
    else
        printf("\nָ�������Ʋ�����!\n");
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
   printf("��������\n��");
   scanf("%d,%d,%d",&year,&month,&day);
   for(i=0;i<n;i++)
   {
    if((year>stu[i].yxrq.year) || ((year==stu[i].yxrq.year) && (month>stu[i].yxrq.month)) ||
        ((year==stu[i].yxrq.year) && (month==stu[i].yxrq.month) && (day>stu[i].yxrq.day)))
             printf("%-4s %-10s %-4s %-4s %-4s %-4s %-4s %-4s %-4s","��Ʒ���","����","���ͱ��","��Ʒ���","������λ",
        "��Ʒ����","�ο��۸�","��������","��Ч��\n\n");
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


    /*====��֤�û��Ŀ��ֱ����ȷΪֹ====*/
    do{
        printf("��������");
        scanf("%s",password);

        s=login(password);
     }while(s==0);
     
    /*====�����û���ѡ��ִ����Ӧ�Ĳ���.====*/
   while(1)
    {

        displayMenu();
       
        printf("\n ��ѡ�����Ĳ���(1,2,3,4,5,6,7,8,9,10)��\n");
        scanf("%d",&choice);

        switch(choice)
        {

            case 1:
                n=scan(stu,n);
                break;

            case 2:
                printf("���������޸ĵ����Ƶı��:\n");
                scanf("%d",&stuNumber);
                editInfoByNumber(stu,n,stuNumber);
                break;
            case 3:
                printf("��������ɾ�������Ƶı��:\n");
                scanf("%d",&stuNumber);
                deleteInfoByNumber(stu,n,stuNumber);
                break;
            case 4:
                printf("�����������ҵ����ƣ�\n");
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
