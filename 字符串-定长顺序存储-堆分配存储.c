/*串的三种存储结构

	存储串的结构有三种：1 定长顺序存储；2 堆分配存储； 3 块链存储。
	定长顺序存储

	采用固定长度的数组（即静态数组）存储串。

	例如：char a[7] = "abcdfg";

此方式存储串时，需要预估串的长度提前申请足够的存储空间。目标串如果超过了数组申请的长度，超出部分会被自动舍弃（称为“截断”）。

	例如：char a[3] = "abcdfg";//实际上数组中只存储了 “abc” ，后边的被截断。
堆分配存储

	采用动态数组存储串。
	在C语言中，存在着一个被称之为“堆”的自由存储区，用 malloc 函数和 free 函数管理，malloc 函数负责申请空间，free 函数负责释放空间。
	例如：char * a = (char*)malloc(5*sizeof(char));//创建 a 数组，动态申请5个 char 类型数据的存储空间

使用堆分配存储的优势在于：当发现申请的空间不够用时，可以通过 realloc() 函数重新申请更大的存储空间。

	例如：a = (char*)realloc(a, 10*sizeof(char));//前一个参数指申请空间的对象；第二个参数，重新申请空间的大小

使用 malloc 函数申请的存储空间，不会自动释放，需要程序员调用 free() 函数手动释放。如果不手动释放，当程序执行彻底结束，由操作系统进行回收。

	例如：free(a);//释放动态数组a申请的空间

举一个完整的例子，连接串 “abc” 和 “defg” 变为 “abcdefg” ；
*/
#include "字符串-定长顺序存储-堆分配存储.h"

	void strConfig(void)
	{
		char * a1=NULL;
		char * a2=NULL;
		int i;

		a1=(char*)malloc(3*sizeof(char));
		strcpy_s(a1, 3,"abc");//将字符串“abc”复制给a1
		a2=(char*)malloc(4*sizeof(char));
		strcpy_s(a2, 4,"defg");

		int lengthA1;
		lengthA1=strlen(a1);
		int lengthA2;
		lengthA2=strlen(a2);

		if (lengthA1<lengthA1+lengthA2) 
		{
			a1=(char*)realloc(a1, (lengthA1+lengthA2)*sizeof(char));
		}
		for (i=lengthA1; i<lengthA1+lengthA2; i++)
		{
			a1[i]=a2[i-lengthA1];
		}
		printf("%s",a1);
		free(a1);
		free(a2);
		//return 0;
	}
/*输出结果：
	abcdefg

	注：在程序中，我们给 a1 和 a2 赋值的时候，使用了 strcpy 复制函数。在这里不能直接用：a1 = ”abc”这种方式，
		如果你这样做，程序编译会出错，告诉你，没有 malloc 的空间不能 free 。

	原因是： strcpy 函数是将字符串复制到申请的存储空间中，而直接赋值是字符串存储在别的内存空间（本身是一个常量，
			放在常量区）中，更改了指针 a1 和 a2 的指向，也就是说，之前动态申请的存储空间虽然申请了，结果还没用呢就丢了。
	*/