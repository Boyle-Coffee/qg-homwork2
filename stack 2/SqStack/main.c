#include <stdio.h>
#include "../head/SqStack.h"
#include <stdlib.h>
#include "SqStack.c"
#define STACKSIZE 100
void printdone();
char get_first();
int get_int();
void printStack(SqStack *s);
int main()
{
	SqStack stack;
	char choice;
	int e;
	
	atexit(printdone);  //ע���ӡ�����������������
	while(!(initStack(&stack,STACKSIZE))){
		puts("fail to Create the stack,continue?(c to continue):");
		if(get_first()!='c')
			return 0;
	}
	puts("the stack has been created");
	while(1){
        printf("please choose how to deal with the stack:\n"
            	 "A.is it empty?    B.get the top\n"
		         "C.clear the stack D.length\n"
		         "E.push the stack  F.pop the stack \n"
		         "G.destroy the stack(quit)\n"
				 "H.print\n"
		         "request:_____\b\b\b\b\b");
        choice=get_first();  //��õ�һ��������ַ�
		switch(choice){  //ͨ��switch��������Ӧ��ѡ��
			case'A':if(isEmptyStack(&stack))  //����Ƿ��ջ
						puts("\nthe stack is empty");
					else  //ջ�����ڣ�����
						puts("\nthe stack is not empty");
					break;
			case'B':if(getTopStack(&stack,&e))  //���ջ��Ԫ��
						printf("\nThe data of the stack top is %d\n",e);
				    else  //ջ�ջ򲻴��ڣ����� 
						printf("\nError!I can not get the data\n");
					break;
			case'C':if(clearStack(&stack)) //���ջ
						puts("\nthe stack is cleared");
				    else  //ջ�����ڣ�����
						puts("\nError!The stack can not be cleared");
					break;
			case'D':if(stackLength(&stack,&e))  //���ջ�Ĵ�С
						printf("\nthe length of stack is %d\n",e);
					else
						puts("\nError!I can't get the length of stack");
					break;
			case'E':printf("please tell me the data: ");
					e=get_int();  //��ջʱ�������
					if(pushStack(&stack,e))  //��ջ
						printf("the %d has been pushed into the stack",e);
					else  //ջ�����ڣ�����
						puts("Error!I can not push the stack");
					break;
			case'F':if(popStack(&stack,&e))  //��ջ
						printf("the data you want is %d",e);
					else  //ջ�ջ򲻴��ڣ�����
						puts("Error!I can not push the stack");
					break;
			case'G':if(destroyStack(&stack)){
						printf("the stack has been destroyed\n");  //�ݻ�ջ����������
						getchar();
						return 0;
					}
					else{
						printf("Error!");  //�ݻ�ʧ�ܣ�ջ������
                        getchar();   
						return 0;
					}
					break;
			case'H':printStack(&stack);  //��ӡջ
					break;
			default:printf("The choice you entered is wrong!please try again!\n");  //������������
		}
		puts("\nAny key continue\n");
		getchar();
		while(getchar()!='\n')  //���������ַ�������Ӱ�쵽���������
			continue;
	}

	return 0;
}

void printdone(){
	printf("Done!\n");
}

int get_int(){  //��������Լ������������
	int input;
	char ch;

	while(scanf("%d",&input)!=1){
		while((ch=getchar())!='\n')
			putchar(ch);
		printf(" is not an integer. please enter an integer:");
	}

	return input;
}

char get_first(){  //��õ�һ��������ַ������������ַ�
	char ch;
	
	ch=getchar();
	while(getchar()!='\n')
		continue;

	return ch;
}

void printStack(SqStack *s){  //ͨ��ѭ����������ӡջ
	SqStack *p;
	int i;
	
	if(!(s))
		printf("the is not exit!");
	else if(s->top==-1)
		printf("top->  \n  count=%d\n",(s->top)+1);
	else{
		printf("top->  ");
		for(i=0;i<=s->top;i++)
			printf("%d ",s->elem[i]);
		printf("\n  count=%d\n",(s->top)+1);
	}
}