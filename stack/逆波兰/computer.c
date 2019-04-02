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
	translate(a,b);  //转换表达式
<<<<<<< HEAD
    printf("the postfix expression is %s\nany key to continue",b);
	getchar();
	result=compute(b);  //计算表达式
	printf("the answer is %.3f%+.3fi",creal(result),cimag(result));
	getchar();
=======
	printf("the postfix expression is %s\nany key to continue",b);
	getchar();
	result=compute(b);  //计算表达式
	printf("the answer is %.3f+%.3fi",creal(result),cimag(result));
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8

	return 0;
}

void translate(char str[],char exp[]){  //exp数组用于储存出栈的后缀表达式，每个数字（完整的数字）或运算符后均有一个空格
	chStack s;
<<<<<<< HEAD
	int i=0,j=0,oper=0;//modification 作为布尔值表示上一个字符是否是运算符，用于检查输入
	char e,k;
	char ch;

    initChStack(&s,SIZE);
=======
	int i=0,j=0,e,k;
	char ch;

    initChStack(&s,SIZE);
    printf("H");
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
	ch=str[i++];
	while(ch!='\0'){
		switch(ch){
			case'(':pushChStack(&s,ch);  //检查到左括号，入栈
					break;
<<<<<<< HEAD
			case')':while(getTopChStack(&s,&k)&&k!='('){  //检查到右括号，出栈，直到遇到左括号
						popChStack(&s,&e);
						if(e!='(')
=======
			case')':while(getTopChStack(&s,&k)&&k=='('){  //检查到右括号，出栈，直到遇到左括号
                            printf("%c9",k);  //check
						popChStack(&s,&e);
						if(e!='(')
                            printf("%c1",e);  //check
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
                        if(e!='(')
                            exp[j++]=e;  //将出栈元素加入数组
                            exp[j++]=' ';
					}
					popChStack(&s,&k);
					break;
			case'+':
<<<<<<< HEAD
			case'-':if(oper==1){  //modification 检查运算符是否重复输入
                        printf("Enter Error!");
                        exit(-1);
					}
                    while(getTopChStack(&s,&k)&&k!='('){  //加号和减号只有遇到左括号才入栈
						popChStack(&s,&e);
=======
			case'-':while(getTopChStack(&s,&k)&&k!='('){  //加号和减号只有遇到左括号才入栈
						popChStack(&s,&e);  
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
                        exp[j++]=e;  //将出栈元素加入数组
						exp[j++]=' ';
					}
					pushChStack(&s,ch);
<<<<<<< HEAD
					oper=1;  //modification
					break;
			case'*':
			case'/':if(oper==1){  //modification 检查运算符是否重复输入
                        printf("Enter Error!");
                        exit(-1);
					}
                    while(getTopChStack(&s,&e)&&(e=='*'||e=='/')){  //乘号与除号只有遇到栈顶是乘号和除号时才打印进表达式
						popChStack(&s,&e);
=======
					break;
			case'*':
			case'/':while(getTopChStack(&s,&e)&&(e=='*'||e=='/')){  //乘号与除号只有遇到栈顶是乘号和除号时才打印进表达式
						popChStack(&s,&e);
						printf("%c3",e);  //check
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
						exp[j++]=e;  //将出栈元素加入数组
						exp[j++]=' ';
					}
					pushChStack(&s,ch);
<<<<<<< HEAD
					oper=1;  //modification
					break;
			case' ':break;
			default:while((ch>='0'&&ch<='9')||ch=='i'||ch=='.'){  //检查属于数字的部分
						exp[j++]=ch;
						ch=str[i++];
						oper=0;
					}
					if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!=' '&&ch!='\0'&&ch!='('&&ch!=')'){  //modification 检查如果是运算符以外的字符，则报错
                        printf("Enter Error!");
                        exit(-1);
=======
					break;
			case' ':break;
			default:while((ch>='0'&&ch<='9')||ch=='i'||ch=='.'){  //检查属于数字的部分
			    printf("%c4",ch);  //check
						exp[j++]=ch;
						ch=str[i++];
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
					}
					i--;
					exp[j++]=' ';
            }
		ch=str[i++];
	}
<<<<<<< HEAD
	if(str[i-2]!=' '&&!(str[i-2]>=0&&str[i-2]<=9)&&str[i-1]!=')'){  //modification 检查末尾字符如果是运算符或左括号的或则报错
        printf("Enter Error!");
        exit(-1);
    }
=======
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
	while(popChStack(&s,&e)){
		exp[j++]=e;
		exp[j++]=' ';
	}
	exp[j]='\0';
}

complex double compute(char a[]){
	SqStack s;
	int i=0;
<<<<<<< HEAD
	complex double x1,x2,result,value,e,scale;

    initStack(&s,SIZE);
	while(a[i]!='\0'){
        if(a[i]=='i')  //modification 检查到数字开头是i，假设为虚数i
        {
            if(a[i+1]!=' '&&a[i+1]!='\0'){  //modification 虚数后应该是空格或空字符
				printf("Error!");
				exit(-1);
			}
			value=_Complex_I;  //modification 没有错误，则确定为虚数i
			pushStack(&s,value);
        }
		if(a[i]!=' '&&(a[i]>='0'&&a[i]<='9')){  //将字符串转换为数字
			value=0.0;
			while(a[i]!=' '&&a[i]!='i'&&a[i]!='.'){
				value=10*value+(complex double)(a[i]-'0');
                i++;
			}
        if(a[i]=='.'){  //检查是不是小数点，若是，后面就是小数部分
            i++;
            scale=0.1;
            while(a[i]!=' '&&a[i]!='i'&&a[i]!='.'&&a[i]!='\0'){
				value+=((complex double)(a[i]-'0'))*scale;
				scale*=0.1;
                i++;
			}
            if(a[i]=='.'){  //检查是否一个数字出现了两个小数点，是则报错
                printf("Enter Error!\n");
                exit(-1);
            }
        }
		if(a[i]=='i'){  //i表示虚数结尾，i后应该是空格
			if(a[i+1]!=' '&&a[i+1]!='\0'){
				printf("Error!");
				exit(-1);
=======
	complex double x1,x2,result,value;

	while(a[i]!='\0'){
		if(a[i]!=' '||(a[i]>='0'&&a[i]>='9')||a[i]=='.'||a[i]=='i'){  //将字符串转换为数字
			value=0.0;
			while(a[i]!=' '||a[i]!='i'){
				value+=10*value+(double)a[i]-'0';
				i++;
			}
		}
		if(a[i]=='i'){  //i表示虚数结尾，i后应该是空格
			if(a[++i]!=' '){
				printf("Error!");
				return 0;
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
			}
			value=value*_Complex_I;
		}
		pushStack(&s,value);
<<<<<<< HEAD
		}
=======
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
		switch(a[i]){  //检查到是运算符，判断并运算
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
<<<<<<< HEAD
				if(x1==0){
                    printf("Error!the divisor can not be zero");//除数是零则报错
                    exit(-1);
;				}
=======
>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
				result=x2/x1;
				pushStack(&s,result);
				break;
			default:break;
		}
		i++;
	}
<<<<<<< HEAD
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



=======
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


>>>>>>> 050e9010ebeaaf3e4f98440201e107e76887d6d8
