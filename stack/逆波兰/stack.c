#include <stdlib.h>

//���complex double��˳��ջ
Status initStack(SqStack *s,int sizes){  //��ʼ��ջ
	s->elem=(ElemType*)malloc(sizes*sizeof(ElemType));
	if(!(s->elem))
		return ERROR;
	s->top=-1;
	s->size=sizes;

	return SUCCESS;
}

Status isEmptyStack(SqStack *s){   //�ж�ջ�Ƿ�Ϊ��
	if(s->top==-1)  //���ջ�н�������-1Ϊ���
		return SUCCESS;

	return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e){   //�õ�ջ��Ԫ��
	char ch;

	if(!s||s->top==-1)		//���ջ�Ƿ�����Լ��Ƿ�Ϊ��ջ
		return ERROR;

	*e=s->elem[s->top];

	return SUCCESS;
}

Status clearStack(SqStack *s){   //���ջ
	if(!s)  //���ջ�Ƿ����
		return ERROR;
	s->top=-1;  //��ջ����Ϊ-1������ջ��Ԫ��Ϊ��

	return SUCCESS;
}

Status destroyStack(SqStack *s){  //����ջ
	if(!s)  //���ջ�Ƿ����
		return ERROR;
	free(s->elem);
	free(s);  //�ͷ�ջ�Ŀռ�

	return SUCCESS;
}
Status stackLength(SqStack *s,int *length){   //���ջ����
	if(!s)  //���ջ�Ƿ����
		return ERROR;
	*length=s->top+1;

	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data){  //��ջ
	char ch;

	if(!s)		//���ջ�Ƿ����
		return ERROR;
	if(s->top>=s->size-1){  //����Ƿ�ջ��
		printf("the stack is full!\ndo you want to increase the size of the stack?\n"
			"the operation may lead to danger!(y or Y to increase)");
		ch=getchar();
		while(getchar()!='\n')
			continue;
		if(ch=='y'||ch=='Y'){  //�����Ƿ�����ջ�Ĵ�С
			s->size+=INCREMENTSIZE;
			s->elem=realloc(s->elem,s->size*sizeof(ElemType));  //����ջ�Ĵ�С

			return ERROR;
		}
	}
	s->top++;  //�ı�ջ����λ��
	s->elem[s->top]=data;

	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data){   //��ջ
	if(!s||s->top==-1)		//���ջ�Ƿ�����Լ��Ƿ�Ϊ��ջ
		return ERROR;

	*data=s->elem[s->top];
	s->top--; // �ı�ջ����λ��

	return SUCCESS;
}


//����ַ���˳��ջ
Status initChStack(chStack *s,int sizes){  //��ʼ��ջ
	s->elem=(ElemType2*)malloc(sizes*sizeof(ElemType2));
	if(!(s->elem))
		return ERROR;
	s->top=-1;
	s->size=sizes;

	return SUCCESS;
}

Status isEmptyChStack(chStack *s){   //�ж�ջ�Ƿ�Ϊ��
	if(s->top==-1)  //���ջ�н�������-1Ϊ���
		return SUCCESS;

	return ERROR;
}

Status getTopChStack(chStack *s,ElemType2 *e){   //�õ�ջ��Ԫ��
	char ch;

	if(!s||s->top==-1)		//���ջ�Ƿ�����Լ��Ƿ�Ϊ��ջ
		return ERROR;

	*e=s->elem[s->top];

	return SUCCESS;
}

Status clearChStack(chStack *s){   //���ջ
	if(!s)  //���ջ�Ƿ����
		return ERROR;
	s->top=-1;  //��ջ����Ϊ-1������ջ��Ԫ��Ϊ��

	return SUCCESS;
}

Status destroyChStack(chStack *s){  //����ջ
	if(!s)  //���ջ�Ƿ����
		return ERROR;
	free(s->elem);
	free(s);  //�ͷ�ջ�Ŀռ�

	return SUCCESS;
}
Status chStackLength(chStack *s,int *length){   //���ջ����
	if(!s)  //���ջ�Ƿ����
		return ERROR;
	*length=s->top+1;

	return SUCCESS;
}

Status pushChStack(chStack *s,ElemType2 data){  //��ջ
	char ch;

	if(!s)		//���ջ�Ƿ����
		return ERROR;
	if(s->top>=s->size-1){  //����Ƿ�ջ��
		printf("the stack is full!\ndo you want to increase the size of the stack?\n"
			"the operation may lead to danger!(y or Y to increase)");
		ch=getchar();
		while(getchar()!='\n')
			continue;
		if(ch=='y'||ch=='Y'){  //�����Ƿ�����ջ�Ĵ�С
			s->size+=INCREMENTSIZE;
			s->elem=realloc(s->elem,s->size*sizeof(ElemType2));  //����ջ�Ĵ�С

			return ERROR;
		}
	}
	s->top++;  //�ı�ջ����λ��
	(s->elem)[s->top]=data;

	return SUCCESS;
}

Status popChStack(chStack *s,ElemType2 *data){   //��ջ
	if(!s||s->top==-1)		//���ջ�Ƿ�����Լ��Ƿ�Ϊ��ջ
		return ERROR;

	*data=s->elem[s->top];
	s->top--; // �ı�ջ����λ��

	return SUCCESS;
}
