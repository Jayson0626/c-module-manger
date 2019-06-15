#pragma once
#if 0
#include <stdio.h>

char a[100];
char b[100][100]; //数组中元素类型为char型
int main(int argc,char *argv[])
{
	char i,t=100;
	char *p=a,*p2=&a[10],*p3=&a[20];
	printf_s("%d,%d,%p\n",sizeof(int),sizeof(a),a);//4,1x100=100，(如果是int a[100]则为4*100)，地址
	for (i=0;i<100;i++)
	{
		a[i]=i;
	}
	printf_s("%d,%p,%d\n",a,a,*a);//(18904256,012074C0,0),第一个a是十进制，第二个是十六进制，第三个是数组a第一个元素的值(数组名是数组的首地址=第一个元素地址)；

	
	while(t--)
	{
		printf_s("%d\n",*(p++));
	}

	printf_s("%d\n",p3 - p2);//10
	printf_s("%p\n",p3 - p2);//0000 000A

	printf_s("%d\n",sizeof(b));
	return 0;
}
#endif

/************************************************************************/
/* &数组名                                                                     */
/************************************************************************/
#if 0
#include <stdio.h>
int a[4]={1,2,3,4};
int *p=a;
int main()
{
	printf_s("a=%p\n",a);
	printf_s("p=%p\n\n",p);

	printf_s("&a=%p\n",&a);
	printf_s("&p=%p\n\n",&p);

	printf_s("a+1=%p\n",a+1);
	printf_s("&a+1=%p\n\n",&a+1);
	
	printf_s("sizeof(a)=%d,sizeof(p)=%d\n",sizeof(a),sizeof(p));
}
/************************************************************************/
/* 上面显示结果：
a=003D7000
p=003D7000

&a=003D7000
&p=003D7010

a+1=003D7004
&a+1=003D7010     //&a+1却跳过了整个数组的所有元素个数，指向数组之后的位置。

sizeof(a)=16,sizeof(p)=4 //sizeof(数组名)=整个数组空间大小，sizeof(p=a)=数组第一个元素的空间大小
*/
/************************************************************************/

#endif

/************************************************************************/
/*             char str[]与char *str的区别                                 */
/************************************************************************/
#if 0

#include <stdio.h>

char* get_str(void)  
{  
	char str[] = {"abcd"};  
	return str;  //警告	1	warning C4172: 返回局部变量或临时变量的地址	

}

/*定义一个指针函数，函数体内声明一个局部的char型指针变量，存储在全局静态存储区，最后返回的地址上的结果也是正确的*/
char* get_str(void)  
{  
	char *str = {"abcd"};  
	return str;  //最好返回常量指针，因为你不能去改变字符串常量的值
} 

#endif

/************************************************************************/
/*            Switch函数的使用中，分支后必须加break                         */
/************************************************************************/
#if 0
#include <stdio.h>
#include <conio.h>

char str[]="Hello";
char * str1 = "Hello";
char a;
//char * str2 = {0};
int main()
{

//	printf_s("Sizeof(str)=%d\n",sizeof(str)); //结果：Sizeof(str)=6，因为字符串后面还有一个结束标志符号'\0'
//	printf_s("Sizeof(str1)=%d\n",sizeof(str1)); //sizeof(str) == 4(x86) or 8(x64)，str1位地址所占的空间大小
	while(1)
	{
		scanf_s("%c",&a);
		switch (a)
		{
		case 'A':
			printf_s("85~100\n");
			break;
		case 'B':
			printf_s("70~84\n");
			break;
		case 'C':
			printf_s("60~69\n");
			break;
		default:printf_s("ERROR\n");
			break;
		}
		getchar();
	}
	return 0;
}
#endif

/************************************************************************/
/*       同时定义了形参和函数中的局部变量, 
		 函数形参可如下形式定义！                                  */
/************************************************************************/

#if 0

#include <stdio.h>

int max(x,y)int x,y;
{
	int z;
	z=x>y?x:y;
	return z;
}
int main(int argc,char *argv[])
{
	//int x,y;

	int a=1,b=2,c;
		c=max(a,b);
		printf_s("%d\n",c);
		return 0;

}
#endif

/************************************************************************/
/* char *str 和char str[]的区别                                      */
/************************************************************************/

#if 0

#include <stdio.h>
#include <malloc.h>


int a;
int *const p1=&a;
(*p1)=8;


int main()
{
#if 0
	char *p=(char *)malloc(sizeof(char)*10);//这种情况下可对指针p进行类似数组的操作。
	//char *p = "abcd";这种情况下为 指针指向 储存在 静态存储区 的 字符串常量，不可以类似数组的下标操作！
	char str[10];
	//p[0]="hello";
	p[0]='h';
	str[0]='h';
	printf_s("%c\n",p[0]);
	printf_s("%c\n",str[0]);
	printf_s("sizeof(p)=%d \n",sizeof(p));
	printf_s("sizeof(str)=%d \n",sizeof(str));
	free(p);	//释放动态申请的内存
	p=NULL;		//将指向原来申请的动态空间的 指针 指向空指针，否则容易出现野指针！

	printf_s("a=%d\n",a);

	 //*ptr = 2;
	// a=2;
	 //const int b=3;
	// ptr = &b;
#endif

	printf_s("%d\n",a);
	return 0; 
}
#endif

/************************************************************************/
/* malloc函数申请空间的指针p大小（sizeof）   */
/************************************************************************/

#if 0
#include <stdio.h>
#include <malloc.h>
//链表中存放的不是基本数据类型，需要用结构体实现自定义：
typedef struct Link{
	char elem;//代表数据域
	struct Link * next;//代表指针域，指向直接后继元素
}link;


void main()
{
	link * p=(link*)malloc(sizeof(link));//创建一个头结点，p为指向头结点的指针(可以把 link结构体 看作结点)
	printf_s("sizeof(p)=%d\n",sizeof(p)); //sizeof(p)=4
	printf_s("sizeof(link)=%d\n",sizeof(link));//sizeof(link)=8····················
	//printf_s("sizeof(struct)=%d\n",sizeof(struct));//出错
	//printf_s("sizeof(Link)=%d\n",sizeof(Link));	//同上
}
#endif


#include <stdio.h>

int main()
{
	char *a="Hello";
	int (*b)[10]={0};
	printf_s("Arra A Is：%s\n",a);
	printf_s("Arra B Is:%d\n",b[0]);
	printf_s("%d %d\n",sizeof (a),sizeof(b));

	return 0;
}