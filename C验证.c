#pragma once
#if 0
#include <stdio.h>

char a[100];
char b[100][100]; //������Ԫ������Ϊchar��
int main(int argc,char *argv[])
{
	char i,t=100;
	char *p=a,*p2=&a[10],*p3=&a[20];
	printf_s("%d,%d,%p\n",sizeof(int),sizeof(a),a);//4,1x100=100��(�����int a[100]��Ϊ4*100)����ַ
	for (i=0;i<100;i++)
	{
		a[i]=i;
	}
	printf_s("%d,%p,%d\n",a,a,*a);//(18904256,012074C0,0),��һ��a��ʮ���ƣ��ڶ�����ʮ�����ƣ�������������a��һ��Ԫ�ص�ֵ(��������������׵�ַ=��һ��Ԫ�ص�ַ)��

	
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
/* &������                                                                     */
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
/* ������ʾ�����
a=003D7000
p=003D7000

&a=003D7000
&p=003D7010

a+1=003D7004
&a+1=003D7010     //&a+1ȴ�������������������Ԫ�ظ�����ָ������֮���λ�á�

sizeof(a)=16,sizeof(p)=4 //sizeof(������)=��������ռ��С��sizeof(p=a)=�����һ��Ԫ�صĿռ��С
*/
/************************************************************************/

#endif

/************************************************************************/
/*             char str[]��char *str������                                 */
/************************************************************************/
#if 0

#include <stdio.h>

char* get_str(void)  
{  
	char str[] = {"abcd"};  
	return str;  //����	1	warning C4172: ���ؾֲ���������ʱ�����ĵ�ַ	

}

/*����һ��ָ�뺯����������������һ���ֲ���char��ָ��������洢��ȫ�־�̬�洢������󷵻صĵ�ַ�ϵĽ��Ҳ����ȷ��*/
char* get_str(void)  
{  
	char *str = {"abcd"};  
	return str;  //��÷��س���ָ�룬��Ϊ�㲻��ȥ�ı��ַ���������ֵ
} 

#endif

/************************************************************************/
/*            Switch������ʹ���У���֧������break                         */
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

//	printf_s("Sizeof(str)=%d\n",sizeof(str)); //�����Sizeof(str)=6����Ϊ�ַ������滹��һ��������־����'\0'
//	printf_s("Sizeof(str1)=%d\n",sizeof(str1)); //sizeof(str) == 4(x86) or 8(x64)��str1λ��ַ��ռ�Ŀռ��С
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
/*       ͬʱ�������βκͺ����еľֲ�����, 
		 �����βο�������ʽ���壡                                  */
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
/* char *str ��char str[]������                                      */
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
	char *p=(char *)malloc(sizeof(char)*10);//��������¿ɶ�ָ��p������������Ĳ�����
	//char *p = "abcd";���������Ϊ ָ��ָ�� ������ ��̬�洢�� �� �ַ�������������������������±������
	char str[10];
	//p[0]="hello";
	p[0]='h';
	str[0]='h';
	printf_s("%c\n",p[0]);
	printf_s("%c\n",str[0]);
	printf_s("sizeof(p)=%d \n",sizeof(p));
	printf_s("sizeof(str)=%d \n",sizeof(str));
	free(p);	//�ͷŶ�̬������ڴ�
	p=NULL;		//��ָ��ԭ������Ķ�̬�ռ�� ָ�� ָ���ָ�룬�������׳���Ұָ�룡

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
/* malloc��������ռ��ָ��p��С��sizeof��   */
/************************************************************************/

#if 0
#include <stdio.h>
#include <malloc.h>
//�����д�ŵĲ��ǻ����������ͣ���Ҫ�ýṹ��ʵ���Զ��壺
typedef struct Link{
	char elem;//����������
	struct Link * next;//����ָ����ָ��ֱ�Ӻ��Ԫ��
}link;


void main()
{
	link * p=(link*)malloc(sizeof(link));//����һ��ͷ��㣬pΪָ��ͷ����ָ��(���԰� link�ṹ�� �������)
	printf_s("sizeof(p)=%d\n",sizeof(p)); //sizeof(p)=4
	printf_s("sizeof(link)=%d\n",sizeof(link));//sizeof(link)=8����������������������������������������
	//printf_s("sizeof(struct)=%d\n",sizeof(struct));//����
	//printf_s("sizeof(Link)=%d\n",sizeof(Link));	//ͬ��
}
#endif


#include <stdio.h>

int main()
{
	char *a="Hello";
	int (*b)[10]={0};
	printf_s("Arra A Is��%s\n",a);
	printf_s("Arra B Is:%d\n",b[0]);
	printf_s("%d %d\n",sizeof (a),sizeof(b));

	return 0;
}