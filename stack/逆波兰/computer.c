#include <stdio.h>
#include <complex.h>
#include "stack.h"
#include "stack.c"
#define SIZE 100
void translate(char *str,char *exp);
complex double compute(char *exp);
int main()
{
	char a[SIZE],b[SIZE];
	complex double result;

	printf("please enter an expression: ");
	gets(a);
	translate(a,b);  //ת�����ʽ
	printf("the postfix expression is %s\nany key to continue",b);
	getchar();
	result=compute(b);  //������ʽ
	printf("the answer is %.3f+%.3fi",creal(result),cimag(result));

	return 0;
}

void translate(char str[],char exp[]){  //exp�������ڴ����ջ�ĺ�׺���ʽ��ÿ�����֣����������֣�������������һ���ո�
	chStack s;
	int i=0,j=0,e,k;
	char ch;

    initChStack(&s,SIZE);
    printf("H");
	ch=str[i++];
	while(ch!='\0'){
		switch(ch){
			case'(':pushChStack(&s,ch);  //��鵽�����ţ���ջ
					break;
			case')':while(getTopChStack(&s,&k)&&k=='('){  //��鵽�����ţ���ջ��ֱ������������
                            printf("%c9",k);  //check
						popChStack(&s,&e);
						if(e!='(')
                            printf("%c1",e);  //check
                        if(e!='(')
                            exp[j++]=e;  //����ջԪ�ؼ�������
                            exp[j++]=' ';
					}
					popChStack(&s,&k);
					break;
			case'+':
			case'-':while(getTopChStack(&s,&k)&&k!='('){  //�Ӻźͼ���ֻ�����������Ų���ջ
						popChStack(&s,&e);  
                        exp[j++]=e;  //����ջԪ�ؼ�������
						exp[j++]=' ';
					}
					pushChStack(&s,ch);
					break;
			case'*':
			case'/':while(getTopChStack(&s,&e)&&(e=='*'||e=='/')){  //�˺������ֻ������ջ���ǳ˺źͳ���ʱ�Ŵ�ӡ�����ʽ
						popChStack(&s,&e);
						printf("%c3",e);  //check
						exp[j++]=e;  //����ջԪ�ؼ�������
						exp[j++]=' ';
					}
					pushChStack(&s,ch);
					break;
			case' ':break;
			default:while((ch>='0'&&ch<='9')||ch=='i'||ch=='.'){  //����������ֵĲ���
			    printf("%c4",ch);  //check
						exp[j++]=ch;
						ch=str[i++];
					}
					i--;
					exp[j++]=' ';
            }
		ch=str[i++];
	}
	while(popChStack(&s,&e)){
		exp[j++]=e;
		exp[j++]=' ';
	}
	exp[j]='\0';
}

complex double compute(char a[]){
	SqStack s;
	int i=0;
	complex double x1,x2,result,value;

	while(a[i]!='\0'){
		if(a[i]!=' '||(a[i]>='0'&&a[i]>='9')||a[i]=='.'||a[i]=='i'){  //���ַ���ת��Ϊ����
			value=0.0;
			while(a[i]!=' '||a[i]!='i'){
				value+=10*value+(double)a[i]-'0';
				i++;
			}
		}
		if(a[i]=='i'){  //i��ʾ������β��i��Ӧ���ǿո�
			if(a[++i]!=' '){
				printf("Error!");
				return 0;
			}
			value=value*_Complex_I;
		}
		pushStack(&s,value);
		switch(a[i]){  //��鵽����������жϲ�����
			case'+':
				popStack(&s,&x1);
				popStack(&s,&x2);
				result=x1+x2;
				pushStack(&s,result);
				break;
			case'-':
				popStack(&s,&x1);
				popStack(&s,&x2);
				result=x2-x1;
				pushStack(&s,result);
				break;
			case'*':
				popStack(&s,&x1);
				popStack(&s,&x2);
				result=x1*x2;
				pushStack(&s,result);
				break;
			case'/':
				popStack(&s,&x1);
				popStack(&s,&x2);
				result=x2/x1;
				pushStack(&s,result);
				break;
			default:break;
		}
		i++;
	}
	if(!(isEmptyStack(&s))){
		pushStack(&s,result);
		if(isEmptyStack(&s))
			return result;
		else{
			printf("enter Error!");
			exit(-1);
		}
	}
}


