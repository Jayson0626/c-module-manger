#ifndef _���Ա�_˳���_H
#define _���Ա�_˳���_H

#include <stdio.h>
#include <stdlib.h>
#define Size 4


typedef struct Table
{
	int * head;//������һ����Ϊhead�ĳ��Ȳ�ȷ�������飬Ҳ�С���̬���顱
	int length;//��¼��ǰ˳���ĳ���
	int size;//��¼˳������Ĵ洢����
}table;

/************************************************************************/
/* ���ⲿģ����õĺ���Ϊ�ⲿ��������Ҫ��ǰ��ӹؼ��� extern�������־����ڲ����õĺ���  */
/************************************************************************/
extern table initTable();
extern table addTable(table t,int elem,int add);
extern table delTable(table t,int add);
extern int   selectTable(table t,int elem);
extern table amendTable(table t,int elem,int newElem);
extern void  displayTable(table t);


#endif
