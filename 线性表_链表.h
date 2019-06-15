#pragma once

#if 0

#ifndef _线性表_链表_H
#define _线性表_链表_H

#include <stdio.h>
#include <malloc.h>
//链表中存放的不是基本数据类型，需要用结构体实现自定义：
typedef struct Link{
	char elem;//代表数据域
	struct Link * next;//代表指针域，指向直接后继元素
}link;

//链表的操作：
link * initLink();
//链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
link * insertElem(link * p,int elem,int add);
//删除结点的函数，p代表操作链表，add代表删除节点的位置
link * delElem(link * p,int add);
//查找结点的函数，elem为目标结点的数据域的值
int selectElem(link * p,int elem);
//更新结点的函数，newElem为新的数据域的值
link *amendElem(link * p,int add,int newElem);
void display(link *p);


#endif

#endif
