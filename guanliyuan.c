#include<stdio.h>
#include<getch.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>



struct Admini{//帐号，密码，姓名，
    int  id;
	char pw[20];
	char back;
	char flag;
};
typedef struct Admini Admini;
struct Teacher{
	int id;
	char pw[10];
	char name[20];
	char sex[10];
	char age;
	char ls;
	char flag;
	char back;
};
typedef struct Teacher Teacher;
int count=1;
int count_tea=1;
int count_admini=10;
Admini adm[100]={{34567890,"abc",1,-1}};
Teacher tea[100]={{20304050,"123","张三","男",55,20,-1,1}};
int start_tea_id=20304050;

void show_admini(void)
{
	system("clear");
	puts("******欢迎管理员使用******");
	puts("1:添加教师，单个加或者批量添加");
	puts("2:删除教师，删除后的老师记作离职");
	puts("3:修改教师基本信息");
	puts("4:重置教师密码");
	puts("5:解锁教师帐号");
	puts("6:根据姓名查询教师基本信息");
	puts("7:显示所有离职教师");
	puts("8:显示所有在职教师");
	puts("9:修改登陆密码");
	puts("0:退出这个界面");
	puts("--------------------------------");
	puts("请输入你的指令");
	key();
}
 int find_id_adm(int id)
 { 
	 for(int i=0;i<100;i++)
	 {
		 if(adm[i].id==id )
		 {
			
			 return i;
		 }
	}		  
	 return -1;

 }
 int find_id_tea(int id)
 {
	 for(int i=0;i<100;i++)
	 {
		 if(tea[i].id==id && tea[i].back)
		 {
			 return i;
		 }
	}
 return -1;
 }
void clear(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
}

 int find_name_tea(char*str)
 {
	 for(int i=0;i<100;i++)
	 {
		 if(strcmp(tea[i].name,str)==0)
		 {
			 return i;
		 }
	 }
	 return -1;
 }
void key(void)
	{	
	        	switch (getch())
			{
				case 49:add_tea();break;
				case 50:del_tea();break;
				case 51:change_tea();break;
				case 52:reset_tea();break;
				case 53:jie_tea();break;
				case 54:find_tea();break;
				case 55:allno_tea();break;
				case 56:allyes_tea();break;
                case 57:change_password();break;
                case 48:return ;
			}
	} 
void login_admini(void)
{
   system("clear");
   int id=0,count=0;
   char pw_in[20]={};

   system("clear");
   printf("*****伟大的管理员欢迎你********\n");
 
   printf("请输入用户名:");
   scanf("%d",&id);
   getchar();
   if(find_id_adm(id)==-1)
   {
	   printf("没有此用户,重新输入\n");
	   back2();
          
    }
	else 
	{
		while(1)
		{
			printf("请输入密码:");
			gets(pw_in);
		if(0==strcmp(adm[find_id_adm(id)].pw,pw_in))
		     {
				 show_admini();
				 break;
			 }
	     else
		 {
			 count++;
		 }
		 if(count<3)
		 {
			 continue;
		 }
		 else
		 {
			 printf("密码错误多次且限制登陆");break;
			 
		 }
		}
		back2();
    }


}


void add_tea(void)
{  
	system("clear");
	int num=0;

	printf("请输入你要添加的老师个数\n");
	scanf("%d",&num);
	stdin->_IO_read_ptr=stdin->_IO_read_end;
//	FILE*frp=fopen("teacher.txt","r");

	for(int i=0;i<num;i++)
	{
	    char name[20]={};	
system("clear");
	    //printf("请输入教师的工号");
		//clear();
		//scanf("%d",&tea[i].id);
		tea[count].id=start_tea_id+count;
		strcpy(tea[count].pw,"abc");
		printf("请输入教师的姓名:");
		clear();
		scanf("%s",tea[count].name);
		printf("请输入老师的性别:");
		clear();
		scanf("%s",tea[count].sex);
		printf("请输入老师的年龄:");
		clear();
		scanf("%hhd",&tea[count].age);
		printf("请输入老师的工龄:");
		clear();
		scanf("%hhd",&tea[count].ls);
		clear();
		tea[count].back=1;
	//	printf("下一个教师");
		count++;
		count_tea++;
	}
        printf("添加教师完成\n");
		
        back1();
}
void back1(void)
{
	printf("***按任意键返回上一级菜单***\n");
	getch();
	show_admini();
}
void back2(void)
{
	getch();
	login_admini();
	
}
void del_tea(void)
{
	system("clear");
	int num=0;
	
    printf("请输入你要删除的老师工号:");
    clear();
	scanf("%d",&num);
	getchar();
	if(find_id_tea(num)==-1)
	{
		printf("此人不存在\n");		
    }
	else if(tea[find_id_tea(num)].back==0)
	{
		printf("删除该教师记载为离职\n");
	}
	else
	{
		printf("删除成功");
		tea[find_id_tea(num)].back=0;
    }

	
	back1();
}
void change_tea(void)
{
	system("clear");
  int num=0;
  printf("请输入老师工号");
  scanf("%d",&num);
  getchar();
  if(find_id_tea(num)==-1|| tea[find_id_tea(num)].back==0)
  {
	  printf("此人不存在或者已经离职\n");
	 
	  
  }
  else
  {
	  int n;
	  printf("需要修改姓名吗？(1/0)");
	  
	  scanf("%d",&n);
      clear();
	  if(n==1)
	  {
		 printf("请输入你要修改的姓名:");
          gets(tea[find_id_tea(num)].name);
		 printf("修改姓名成功\n");
	  }
	  printf("请输入你是否修改性别(1/0)");
	  scanf("%d",&n);
	  clear();
	  if(n==1)
	  {
		  printf("你要修改的教师的性别:");
		  gets(tea[find_id_tea(num)].sex);
		  printf("修改性别成功\n");
	  }
      

  }
  back1();
}



void reset_tea(void)
{
	system("clear");
	printf("*****重改密码****\n");
	int id=0;
	printf("请输入重改密码的教师工号：");
	scanf("%d",&id);
	clear();
  
	if(find_id_tea(id)==-1)
	{
		printf("没有此人或者此人已经离职\n");
	}
	else

	{  
		printf("请输入新的密码\n");
		scanf("%s",tea[find_id_tea(id)].pw);
	    clear();
		
		
		
		printf("重改密码成功!\n");
	}
      back1();
}
void jie_tea(void)
{ 
 
  system("clear");
  printf("***解锁教师帐号****");
  int id=0;
 printf("请输入要解锁的老师工号");
  scanf("%d",&id);
  stdin->_IO_read_ptr=stdin->_IO_read_end;
	 if(find_id_tea(id)==-1)
	 {
		 printf("没有此人\n");
	 }
	 else if(tea[find_id_tea(id)].flag<3)
	 {
		 printf("此人不需要解锁\n");
	 }
	 else
	 {
		 tea[find_id_tea(id)].flag=0;
		 printf("解锁成功\n");
	 }
back1();
  ///////back?

} 
void find_tea(void)
{
  
  system("clear");
  char na[20]={};
  printf("请输入要查询的老师的名字");
  gets(na);
  if(find_name_tea(na)==-1)
  {
	  printf("没有此人!\n");
  }

  else 
  {  
	  for(int i=0;i<count;i++)
	  {
		  if(strcmp(na,tea[i].name) == 0)
		  {
	  		printf("帐号" ,"密码","姓名" ,"性别","年龄","工龄\n");
	  		printf("%d %s %s %s %hhd %hhd\n",tea[i].id,tea[i].pw,tea [i].name,tea[i].sex,tea[i].age,tea[i].ls);
	  	  }
	  }
  back1();
  }
}
void allno_tea(void)
{
  system("clear");
  printf("***显示离职教师***\n");
  for(int i=0;i<count_tea;i++)
	  {
		  if(tea[i].back==0)
		  {
			  		
		  printf("离职教师\n姓名：%s 性别：%s  工号：%d 密码：%s\n",tea[i].name,tea[i].sex,tea[i].id,tea[i].pw);
  }

}
back1();
  
}
	  
/*void  anykey_continue(void)
{
	puts("按任意一个键返回");
	getch();
}*/
void allyes_tea(void)
{
  system("clear");
  for(int j=0;j<100;j++)
  {
	  if(tea[j].back == 1)
	  {
		  printf("在职教师\n姓名：%s 性别：%s  工号：%d 密码：%s\n",tea[j].name,tea[j].sex,tea[j].id,tea[j].pw);
      }

  }
  back1();
}
void change_password(void)
{
 
}
char get_cmd(char start,char end)
{
	while(1)
	{
		char cmd=getch();
		if(cmd>=start && cmd<=end)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
}
 
int main()
{ 
	login_admini();
	//show_admini();
			
	
}
