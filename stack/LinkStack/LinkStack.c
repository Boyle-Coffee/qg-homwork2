#include <stdio.h>
#include <stdlib.h>

//��ջ(���������)
Status initLStack(LinkStack *s){   //��ʼ��
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));  //����һ�����
	if(!(s->top))  //������Ƿ񱻴���
		return ERROR;
	s->top->next=NULL;  //ջ����ջ�ף�����һ�����Ϊ�գ���ջ��
    s->count=-1;
<<<<<<< HEAD

=======
	
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s){  //�ж���ջ�Ƿ�Ϊ��
    if(s->count==-1)  //���ջ��Ԫ�صĸ�����-1�������
		return SUCCESS;
<<<<<<< HEAD

=======
	
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
	return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e){  //�õ�ջ��Ԫ��
    LinkStackPtr pd;
<<<<<<< HEAD

	if(s->count==-1||s)  //����Ƿ�Ϊ��ջ�Լ�ջ�Ƿ����
	return ERROR;

=======
	
	if(s->count=-1||s)  //����Ƿ�Ϊ��ջ�Լ�ջ�Ƿ����
	return ERROR;
	
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
	pd=s->top;  //pdָ��ջ��
	*e=pd->data;  //e���ܳ�ջ������

	return SUCCESS;
}

Status clearLStack(LinkStack *s){   //���ջ
    LinkStackPtr pc;

<<<<<<< HEAD
	if(s->count==-1||!s)  //����Ƿ�Ϊ��ջ�Լ�ջ�Ƿ����
	return ERROR;

=======
	if(s->count=-1||!s)  //����Ƿ�Ϊ��ջ�Լ�ջ�Ƿ����
	return ERROR;
    
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
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
<<<<<<< HEAD

=======
    
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
	while((s->top)->next){
    	pc=(s->top)->next;  //�ҵ�Ҫ�ͷŵĽ��
		(s->top)->next=pc->next;  //ջ��ָ��Ҫ��ջ������һ�����
	    free(pc);  //�ͷŽ��
	}
<<<<<<< HEAD
    free(s->top);  //�ͷ�ջ��
    free(s);  // ���ٿ�ջ

	return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length){    //���ջ����
	if(!s)  //����Ƿ�Ϊ��ջ�Լ�ջ�Ƿ����
	return ERROR;

	*length=s->count+1; //ͨ��countԪ�ػ��ջ�Ĵ�С 
=======
    free(s->top);  //�ͷ�ջ�������ٿ�ջ

	return SUCCESS;
}    
Status LStackLength(LinkStack *s,int *length){    //���ջ����
    LinkStackPtr pt;
	*length=0;  //��ʼ������Ϊ��

	if(!s)  //����Ƿ�Ϊ��ջ�Լ�ջ�Ƿ����
	return ERROR;

	pt=s->top;
	while(pt->next){  //��鵽һ������nextָ��Ϊ�գ���ת����һ�����
		(*length)++;  
		pt=pt->next;
	}
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8

	return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data){   //��ջ
    LinkStackPtr p;

	if(!s)  //���ջ�Ƿ����
<<<<<<< HEAD
		return ERROR;

	if((p=(LinkStackPtr)malloc(sizeof(StackNode)))==NULL)  //����½���Ƿ�ɹ�����
		return ERROR;

	p->data=data;  //�����½���������
	p->next=s->top->next;  //�����½��
=======
		return ERROR; 
	
	if((p=(LinkStackPtr)malloc(sizeof(StackNode)))==NULL)  //����½���Ƿ�ɹ�����
		return ERROR;
    
	p->data=data;  //�����½���������
	p->next=s->top->next;  //�����½�� 
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
    s->top->next=p;  //�ı�ջ��λ��
	s->count++;

	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data){   //��ջ
	LinkStackPtr p;

	if(!s)  //���ջ�Ƿ����
<<<<<<< HEAD
		return ERROR;
	p=s->top->next;
	if(p==NULL)  //����Ƿ�Ϊ��ջ
		return ERROR;

=======
		return ERROR; 
	p=s->top->next;
	if(p==NULL)  //����Ƿ�Ϊ��ջ
		return ERROR;
    
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
    s->top->next=p->next;  //ջ������һλ
	*data=p->data;  //�õ���ջ����
	free(p);  //�ͷŽ��
	s->count--;

	return SUCCESS;
<<<<<<< HEAD
}
=======
}
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
