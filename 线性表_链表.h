#pragma once

#if 0

#ifndef _���Ա�_����_H
#define _���Ա�_����_H

#include <stdio.h>
#include <malloc.h>
//�����д�ŵĲ��ǻ����������ͣ���Ҫ�ýṹ��ʵ���Զ��壺
typedef struct Link{
	char elem;//����������
	struct Link * next;//����ָ����ָ��ֱ�Ӻ��Ԫ��
}link;

//����Ĳ�����
link * initLink();
//�������ĺ�����p������elem�ǲ���Ľ���������add�ǲ����λ��
link * insertElem(link * p,int elem,int add);
//ɾ�����ĺ�����p�����������add����ɾ���ڵ��λ��
link * delElem(link * p,int add);
//���ҽ��ĺ�����elemΪĿ������������ֵ
int selectElem(link * p,int elem);
//���½��ĺ�����newElemΪ�µ��������ֵ
link *amendElem(link * p,int add,int newElem);
void display(link *p);


#endif

#endif
