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
	printf("the answer is %.3f%+.3fi",creal(result),cimag(result));
	getchar();

	return 0;
}

void translate(char str[],char exp[]){  //exp�������ڴ����ջ�ĺ�׺���ʽ��ÿ�����֣����������֣�������������һ���ո�
	chStack s;
	int i=0,j=0,oper=0;//modification ��Ϊ����ֵ��ʾ��һ���ַ��Ƿ�������������ڼ������
	char e,k;
	char ch;

    initChStack(&s,SIZE);
	ch=str[i++];
	while(ch!='\0'){
		switch(ch){
			case'(':pushChStack(&s,ch);  //��鵽�����ţ���ջ
					break;
			case')':while(getTopChStack(&s,&k)&&k!='('){  //��鵽�����ţ���ջ��ֱ������������
						popChStack(&s,&e);
						if(e!='(')
                        if(e!='(')
                            exp[j++]=e;  //����ջԪ�ؼ�������
                            exp[j++]=' ';
					}
					popChStack(&s,&k);
					break;
			case'+':
			case'-':if(oper==1){  //modification ���������Ƿ��ظ�����
                        printf("Enter Error!");
                        exit(-1);
					}
                    while(getTopChStack(&s,&k)&&k!='('){  //�Ӻźͼ���ֻ�����������Ų���ջ
						popChStack(&s,&e);
                        exp[j++]=e;  //����ջԪ�ؼ�������
						exp[j++]=' ';
					}
					pushChStack(&s,ch);
					oper=1;  //modification
					break;
			case'*':
			case'/':if(oper==1){  //modification ���������Ƿ��ظ�����
                        printf("Enter Error!");
                        exit(-1);
					}
                    while(getTopChStack(&s,&e)&&(e=='*'||e=='/')){  //�˺������ֻ������ջ���ǳ˺źͳ���ʱ�Ŵ�ӡ�����ʽ
						popChStack(&s,&e);
						exp[j++]=e;  //����ջԪ�ؼ�������
						exp[j++]=' ';
					}
					pushChStack(&s,ch);
					oper=1;  //modification
					break;
			case' ':break;
			default:while((ch>='0'&&ch<='9')||ch=='i'||ch=='.'){  //����������ֵĲ���
						exp[j++]=ch;
						ch=str[i++];
						oper=0;
					}
					if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!=' '&&ch!='\0'&&ch!='('&&ch!=')'){  //modification �������������������ַ����򱨴�
                        printf("Enter Error!");
                        exit(-1);
					}
					i--;
					exp[j++]=' ';
            }
		ch=str[i++];
	}
	if(str[i-2]!=' '&&!(str[i-2]>=0&&str[i-2]<=9)&&str[i-1]!=')'){  //modification ���ĩβ�ַ������������������ŵĻ��򱨴�
        printf("Enter Error!");
        exit(-1);
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
	complex double x1,x2,result,value,e,scale;

    initStack(&s,SIZE);
	while(a[i]!='\0'){
        if(a[i]=='i')  //modification ��鵽���ֿ�ͷ��i������Ϊ����i
        {
            if(a[i+1]!=' '&&a[i+1]!='\0'){  //modification ������Ӧ���ǿո����ַ�
				printf("Error!");
				exit(-1);
			}
			value=_Complex_I;  //modification û�д�����ȷ��Ϊ����i
			pushStack(&s,value);
        }
		if(a[i]!=' '&&(a[i]>='0'&&a[i]<='9')){  //���ַ���ת��Ϊ����
			value=0.0;
			while(a[i]!=' '&&a[i]!='i'&&a[i]!='.'){
				value=10*value+(complex double)(a[i]-'0');
                i++;
			}
        if(a[i]=='.'){  //����ǲ���С���㣬���ǣ��������С������
            i++;
            scale=0.1;
            while(a[i]!=' '&&a[i]!='i'&&a[i]!='.'&&a[i]!='\0'){
				value+=((complex double)(a[i]-'0'))*scale;
				scale*=0.1;
                i++;
			}
            if(a[i]=='.'){  //����Ƿ�һ�����ֳ���������С���㣬���򱨴�
                printf("Enter Error!\n");
                exit(-1);
            }
        }
		if(a[i]=='i'){  //i��ʾ������β��i��Ӧ���ǿո�
			if(a[i+1]!=' '&&a[i+1]!='\0'){
				printf("Error!");
				exit(-1);
			}
			value=value*_Complex_I;
		}
		pushStack(&s,value);
		}
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
				if(x1==0){
                    printf("Error!the divisor can not be zero");//���������򱨴�
                    exit(-1);
;				}
				result=x2/x1;
				pushStack(&s,result);
				break;
			default:break;
		}
		i++;
	}
        if(isEmptyStack(&s))
            exit(-1);
        else{
            popStack(&s,&result);
            if(isEmptyStack(&s))
                return result;
            else{
                printf("enter Error!");
                exit(-1);
            }
		}
}



