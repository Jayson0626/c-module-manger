#ifndef _线性表_顺序表_H
#define _线性表_顺序表_H

#include <stdio.h>
#include <stdlib.h>
#define Size 4


typedef struct Table
{
	int * head;//声明了一个名为head的长度不确定的数组，也叫“动态数组”
	int length;//记录当前顺序表的长度
	int size;//记录顺序表分配的存储容量
}table;

/************************************************************************/
/* 被外部模块调用的函数为外部函数，需要在前面加关键字 extern，以区分尽在内部调用的函数  */
/************************************************************************/
extern table initTable();
extern table addTable(table t,int elem,int add);
extern table delTable(table t,int add);
extern int   selectTable(table t,int elem);
extern table amendTable(table t,int elem,int newElem);
extern void  displayTable(table t);


#endif
