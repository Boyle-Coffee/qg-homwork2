#include <stdio.h>
#include "../head/LinkStack.h"
#include <stdlib.h>
#include "LinkStack.c"
void printdone();
char get_first();
int get_int();
void printLStack(LinkStack *s);
int main()
{
	LinkStack stack;
	char choice;
	int e;
	
	atexit(printdone);  //ע���ӡ�����������������
	while(!(initLStack(&stack))){
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
			case'A':if(isEmptyLStack(&stack))  //����Ƿ��ջ
						puts("\nthe stack is empty");
					else  //ջ�����ڣ�����
						puts("\nthe stack is not empty");
					break;
			case'B':if(getTopLStack(&stack,&e))  //���ջ��Ԫ��
						printf("\nThe data of the stack top is %d\n",e);
				    else  //ջ�ջ򲻴��ڣ�����  
						printf("\nError!I can not get the data\n");
					break;
			case'C':if(clearLStack(&stack))  //���ջ
						puts("\nthe stack is cleared");
				    else  //ջ�����ڣ�����
						puts("\nError!The stack can not be cleared");
					break;
			case'D':if(LStackLength(&stack,&e))  //���ջ�Ĵ�С
						printf("\nthe length of stack is %d\n",e);
					else
						puts("\nError!I can't get the length of stack");
					break;
			case'E':printf("please tell me the data: ");
					e=get_int();  //��ջʱ�������
					if(pushLStack(&stack,e))  //��ջ
						printf("the %d has been pushed into the stack",e);
					else  //ջ�����ڣ�����
						puts("Error!I can not push the stack");
					break;
			case'F':if(popLStack(&stack,&e))  //��ջ
						printf("the data you want is %d",e);
					else  //ջ�ջ򲻴��ڣ�����
						puts("Error!I can not push the stack");
					break;
			case'G':if(destroyLStack(&stack)){
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
			case'H':printLStack(&stack);  //��ӡջ
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

void printLStack(LinkStack *s){  //ͨ��ָ�������ӡջ
	LinkStackPtr p;
	
	if(!(s))
		printf("the is not exit!");
	else if((s->top)->next==NULL)
		printf("top->  \n  count=%d\n",s->count+1);
	else{
		printf("top->  ");
		p=s->top->next;
		while(p){
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n  count=%d\n",s->count+1);
	}
}
