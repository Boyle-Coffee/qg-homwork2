#include <complex.h>
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define INCREMENTSIZE 10  //ջÿ�����Ӵ�С

typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

//���double�͵�ջ
typedef complex double ElemType;

typedef struct SqStack {
	ElemType *elem;
	int top;
	int size;
} SqStack;


//˳��ջ(���������)
Status initStack(SqStack *s,int sizes);//��ʼ��ջ
Status isEmptyStack(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopStack(SqStack *s,ElemType *e); //�õ�ջ��Ԫ��
Status clearStack(SqStack *s);//���ջ
Status destroyStack(SqStack *s);//����ջ
Status stackLength(SqStack *s,int *length);//���ջ����
Status pushStack(SqStack *s,ElemType data);//��ջ
Status popStack(SqStack *s,ElemType *data);//��ջ

//����ַ��͵�ջ
typedef char ElemType2;

typedef struct chStack {
	ElemType2 *elem;
	int top;
	int size;
} chStack;


//˳��ջ(���������)
Status initChStack(chStack *s,int sizes);//��ʼ��ջ
Status isEmptyChStack(chStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopChStack(chStack *s,ElemType2 *e); //�õ�ջ��Ԫ��
Status clearChStack(chStack *s);//���ջ
Status destroyChStack(chStack *s);//����ջ
Status chStackLength(chStack *s,int *length);//���ջ����
Status pushChStack(chStack *s,ElemType2 data);//��ջ
Status popChStack(chStack *s,ElemType2 *data);//��ջ


#endif // STACK_H_INCLUDED
