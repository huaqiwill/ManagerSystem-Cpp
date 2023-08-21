/** File KTVSystem.cpp KTV歌曲系统
 * 项目地址：
 * CSDN博客：https://blog.csdn.net/HuaQi666
 * 开发者：http://bingbingfuhao.cn
 * 邮箱：3173484026@qq.com
 * 创建时间: 2023/8/21
 */
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>


typedef struct Info
{
   char name[15];     
   char city[10];    
   char province[10]; 
   char state[10];    
   char tel[15];     
};
typedef struct node
{
   struct Info data;
   struct node *next;
} Node, *link;

void stringinput(char *t, int lens, char *notice)
{
   char n[50];
   do
   {
      printf(notice); 
      scanf("%s", n); 
      if (strlen(n) > lens)
         printf("\n exceed the required length! \n"); 
   } while (strlen(n) > lens);
   strcpy(t, n); 
}
void enter(link l) 
{
   Node *p, *q;
   q = l;
   while (1)
   {
      p = (Node *)malloc(sizeof(Node)); 
      if (!p)                          
      {
         printf("memory malloc fail\n");
         return;
      }
      stringinput(p->data.name, 15, "enter name:"); 
      if (strcmp(p->data.name, "0") == 0)           
         break;
      stringinput(p->data.city, 10, "enter city:");         
      stringinput(p->data.province, 10, "enter province:"); 
      stringinput(p->data.state, 10, "enter status:");     
      stringinput(p->data.tel, 15, "enter telephone:");     
      p->next = NULL;
      q->next = p;
      q = p;
   }
}

void del(link l)
{
   Node *p, *q;
   char s[20];
   q = l;
   p = q->next;
   printf("enter name:");
   scanf("%s", s);
   while (p)
   {
      if (strcmp(s, p->data.name) == 0) 
      {
         q->next = p->next; 
         free(p);           
         printf("delete successfully!");
         break;
      }
      else
      {
         q = p;
         p = q->next;
      }
   }
   getch();
}
void display(Node *p)
{
   printf("MESSAGE \n");
   printf("name:%15s\n", p->data.name);
   printf("city:    %10s\n", p->data.city);
   printf("province:%10s\n", p->data.province);
   printf("state:   %10s\n", p->data.state);
   printf("telphone:%15s\n", p->data.tel);
}
void search(link l)
{
   char name[20];
   Node *p;
   p = l->next;
   printf("enter name to find:");
   scanf("%s", name); 
   while (p)
   {
      if (strcmp(p->data.name, name) == 0) 
      {
         display(p); 
         getch();
         break;
      }
      else
         p = p->next;
   }
}
void list(link l)
{
   Node *p;
   p = l->next;
   while (p != NULL) 
   {
      display(p);
      p = p->next;
   }
   getch();
}

void save(link l)
{
   Node *p;
   FILE *fp;
   p = l->next;
   if ((fp = fopen("f:\\adresslist", "wb")) == NULL)
   {
      printf("can not open file\n");
      exit(1);
   }
   printf("\nSaving file\n");
   while (p) 
   {
      fwrite(p, sizeof(Node), 1, fp);
      p = p->next;
   }
   fclose(fp);
   getch();
}
void load(link l)
{
   Node *p, *r;
   FILE *fp;
   l->next = NULL;
   r = l;
   if ((fp = fopen("f:\\adresslist", "rb")) == NULL)
   {
      printf("can not open file\n");
      exit(1);
   };
   printf("\nLoading file\n");
   while (!feof(fp))
   {
      p = (Node *)malloc(sizeof(Node)); 
      if (!p)
      {
         printf("memory malloc fail!");
         return;
      }
      if (fread(p, sizeof(Node), 1, fp) != 1) 
         break;
      else
      {
         p->next = NULL;
         r->next = p; 
         r = p;
      }
   }
   fclose(fp);
   getch();
}
menu_select()
{
   int i;
   printf("\n\n\t *************************ADDRESS LIST*************************\n");
   printf("\t|*			1.input record			      *|\n");
   printf("\t|*			2.delete record			      *|\n");
   printf("\t|*			3.list record			      *|\n");
   printf("\t|*			4.search record			      *|\n");
   printf("\t|*			5.save record			      *|\n");
   printf("\t|*			6.load record			      *|\n");
   printf("\t|*			7.Quit                                *|\n");
   printf("\t **************************************************************\n");
   do
   {
      printf("\n\tEnter your choice:");
      scanf("%d", &i);
   } while (i < 0 || i > 7);
   return i;
}
main()
{
   link l;
   l = (Node *)malloc(sizeof(Node));
   if (!l)
   {
      printf("\n allocate memory failure "); 
      return;                                
   }
   l->next = NULL;
   system("cls");
   while (1)
   {
      system("cls");
      switch (menu_select())
      {
      case 1:
         enter(l);
         break;
      case 2:
         del(l);
         break;
      case 3:
         list(l);
         break;
      case 4:
         search(l);
         break;
      case 5:
         save(l);
         break;
      case 6:
         load(l);
         break;
      case 7:
         exit(0);
      }
   }
}
