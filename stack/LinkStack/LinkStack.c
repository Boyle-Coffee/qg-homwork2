#include <stdio.h>
#include <stdlib.h>

//��ջ(���������)
Status initLStack(LinkStack *s){   //��ʼ��
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));  //����һ�����
	if(!(s->top))  //������Ƿ񱻴���
		return ERROR;
	s->top->next=NULL;  //ջ����ջ�ף�����һ�����Ϊ�գ���ջ��
    s->count=-1;

	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s){  //�ж���ջ�Ƿ�Ϊ��
    if(s->count==-1)  //���ջ��Ԫ�صĸ�����-1�������
		return SUCCESS;

	return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e){  //�õ�ջ��Ԫ��
    LinkStackPtr pd;

	if(s->count==-1||s)  //����Ƿ�Ϊ��ջ�Լ�ջ�Ƿ����
	return ERROR;

	pd=s->top;  //pdָ��ջ��
	*e=pd->data;  //e���ܳ�ջ������

	return SUCCESS;
}

Status clearLStack(LinkStack *s){   //���ջ
    LinkStackPtr pc;

	if(s->count==-1||!s)  //����Ƿ�Ϊ��ջ�Լ�ջ�Ƿ����
	return ERROR;

	while((s->top)->next){
    	pc=(s->top)->next;  //�ҵ�Ҫ�ͷŵĽ��
		(s->top)->next=pc->next;  //ջ��ָ��Ҫ��ջ������һ�����
	    free(pc);  //�ͷŽ��
	}
	s->count=-1;

	return SUCCESS;
}

Status destroyLStack(LinkStack *s){   //����ջ
    LinkStackPtr pc;

	if(!(s))  //���ջ�Ƿ����
	return ERROR;

	while((s->top)->next){
    	pc=(s->top)->next;  //�ҵ�Ҫ�ͷŵĽ��
		(s->top)->next=pc->next;  //ջ��ָ��Ҫ��ջ������һ�����
	    free(pc);  //�ͷŽ��
	}
    free(s->top);  //�ͷ�ջ��
    free(s);  // ���ٿ�ջ

	return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length){    //���ջ����
	if(!s)  //����Ƿ�Ϊ��ջ�Լ�ջ�Ƿ����
	return ERROR;

	*length=s->count+1; //ͨ��countԪ�ػ��ջ�Ĵ�С 

	return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data){   //��ջ
    LinkStackPtr p;

	if(!s)  //���ջ�Ƿ����
		return ERROR;

	if((p=(LinkStackPtr)malloc(sizeof(StackNode)))==NULL)  //����½���Ƿ�ɹ�����
		return ERROR;

	p->data=data;  //�����½���������
	p->next=s->top->next;  //�����½��
    s->top->next=p;  //�ı�ջ��λ��
	s->count++;

	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data){   //��ջ
	LinkStackPtr p;

	if(!s)  //���ջ�Ƿ����
		return ERROR;
	p=s->top->next;
	if(p==NULL)  //����Ƿ�Ϊ��ջ
		return ERROR;

    s->top->next=p->next;  //ջ������һλ
	*data=p->data;  //�õ���ջ����
	free(p);  //�ͷŽ��
	s->count--;

	return SUCCESS;
}
