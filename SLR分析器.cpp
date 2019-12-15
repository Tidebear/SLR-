#include<stdio.h>    
#include<stdlib.h>
char str[50]; //输入的字符串经过词法翻译后的字符串
int i=0;//用来指向字符串数组里的字符
int o=1;//标志位，用来判断是否结束循环
typedef struct SqStack{
	char data[100];
	int top;
}SqStack;
SqStack s;//存放状态的栈
SqStack t;//存放文法符号的栈
void InitStack(SqStack *s);
void push(SqStack *s,char e);
void pop(SqStack *s,char *e);
bool judge();
int main()              
{
	int j=0,k=0;
	char ch,chucun[50];
	InitStack(&s);
	InitStack(&t);
	printf("输入你要判断的表达式并以;结束："); 
	gets(chucun);
	while(chucun[k]!=';'){
		if(chucun[k]>='0'&&chucun[k]<='9'){
			str[j]='n';
			j++;
			k++;
			while(chucun[k]>='0'&&chucun[k]<='9'){
				k++;
			}
		}
		else if(chucun[k]>='a'&&chucun[k]<='z'){
			str[j]='i';
			j++;
			k++;
			while(chucun[k]>='a'&&chucun[k]<='z'){
				k++;
			}
		}
		else{
			str[j]=chucun[k];
			j++;
			k++; 
		}
	}
	str[j]='$';
	push(&s,'0'); //把状态0入栈底 
	push(&t,'$');//把符号$入栈底
	while(o){
		if(judge()){
			
		}
		else{
			printf("错误的表达式");
			return 0;
		}
	}
	printf("正确的表达式");
	
	return 0;
}
void InitStack(SqStack *s)//初始化栈 
{
	s->top=-1;
}

void push(SqStack *s,char e)//进栈
{
	if(s->top==100-1)
	{	
		printf("栈满\n");
	}
	s->data[++s->top]=e;		
}

void pop(SqStack *s)//出栈
{
	if(s->top==-1)
	{
		printf("栈空\n");
	}
	s->top--;
} 
bool judge()//把符号$入t栈底 把状态0入s栈底 
{
	if(s.top==t.top){
		if(s.data[s.top]=='0'||s.data[s.top]=='4'||s.data[s.top]=='7'||s.data[s.top]=='8'||s.data[s.top]=='9'||s.data[s.top]=='A'){
			if(str[i]=='i'){
				push(&s,'5');
				push(&t,'i'); //若后移一位为字符时s5 
				i++;
			}
			else if(str[i]=='n'){//若后移一位为数字时s6
				push(&s,'6');
				push(&t,'n'); 
				i++;
			}
			else if(str[i]=='('){//若后移一位为(时s4
				push(&s,'4');
				push(&t,'('); 
				i++;
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='1'){
			if(str[i]=='+'){
				push(&s,'7');
				push(&t,'+'); 
				i++;
			}
			else if(str[i]=='-'){
				push(&s,'8');
				push(&t,'-'); 
				i++;
			}
			else if(str[i]=='$'){
				o=0;
				return true;
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='2'){
			if(str[i]=='*'){
				push(&s,'9');
				push(&t,'*'); 
				i++;
			}
			else if(str[i]=='/'){
				push(&s,'A');
				push(&t,'/'); 
				i++;
			}
			else if(str[i]=='+'||str[i]=='-'||str[i]==')'||str[i]=='$'){
				pop(&t);
				pop(&s);
				push(&t,'E');//将E入栈，归约为E 
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='3'){
			if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]==')'||str[i]=='$'){
				pop(&t);
				pop(&s);
				push(&t,'T');
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='5'){
			if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]==')'||str[i]=='$'){
				pop(&t);
				pop(&s);
				push(&t,'F');
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='6'){
			if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]==')'||str[i]=='$'){
				pop(&t);
				pop(&s);
				push(&t,'F');
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='B'){  //B=11
			if(str[i]=='+'){
				push(&s,'7');
				push(&t,'+'); 
				i++;
			}
			else if(str[i]=='-'){
				push(&s,'8');
				push(&t,'-'); 
				i++;
			}
			else if(str[i]==')'){
				push(&s,'G');   //G=16
				push(&t,')'); 
				i++;
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='C'){  //C=12
			if(str[i]=='*'){
				push(&s,'9');
				push(&t,'*'); 
				i++;
			}
			else if(str[i]=='/'){
				push(&s,'A');   //A=10
				push(&t,'/'); 
				i++;
			}
			else if(str[i]=='+'||str[i]=='-'||str[i]==')'||str[i]=='$'){
				pop(&t);
				pop(&s);
				pop(&t);
				pop(&s);
				pop(&t);
				pop(&s);
				push(&t,'E');
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='D'){  //D=13
			if(str[i]=='*'){
				push(&s,'9');
				push(&t,'*'); 
				i++;
			}
			else if(str[i]=='/'){
				push(&s,'A');
				push(&t,'/'); 
				i++;
			}
			else if(str[i]=='+'||str[i]=='-'||str[i]==')'||str[i]=='$'){
				pop(&t);
				pop(&s);
				pop(&t);
				pop(&s);
				pop(&t);
				pop(&s);
				push(&t,'E');
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='E'){   //E=14
			if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]==')'||str[i]=='$'){
				pop(&t);
				pop(&s);
				pop(&t);
				pop(&s);
				pop(&t);
				pop(&s);
				push(&t,'T');
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='F'){    //F=15
			if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]==')'||str[i]=='$'){
				pop(&t);
				pop(&s);
				pop(&t);
				pop(&s);
				pop(&t);
				pop(&s);
				push(&t,'T');
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='G'){   //G=16
			if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]==')'||str[i]=='$'){
				pop(&t);
				pop(&s);
				pop(&t);
				pop(&s);
				pop(&t);
				pop(&s);
				push(&t,'F');
			}
			else{
				return false;
			}
		}
				
	}
	else if(s.top==(t.top-1)){
		if(s.data[s.top]=='0'){
			if(t.data[t.top]=='E'){
				push(&s,'1');
			}
			else if(t.data[t.top]=='T'){
				push(&s,'2');
			}
			else if(t.data[t.top]=='F'){
				push(&s,'3');
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='4'){
			if(t.data[t.top]=='E'){
				push(&s,'B');
			}
			else if(t.data[t.top]=='T'){
				push(&s,'2');
			}
			else if(t.data[t.top]=='F'){
				push(&s,'3');
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='7'){
			if(t.data[t.top]=='T'){
				push(&s,'C');
			}
			else if(t.data[t.top]=='F'){
				push(&s,'3');
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='8'){
			if(t.data[t.top]=='T'){
				push(&s,'D');
			}
			else if(t.data[t.top]=='F'){
				push(&s,'3');
			}
		}
		else if(s.data[s.top]=='9'){
			if(t.data[t.top]=='F'){   
				push(&s,'E');  
			}
			else{
				return false;
			}
		}
		else if(s.data[s.top]=='A'){   //A=10
			if(t.data[t.top]=='F'){
				push(&s,'F');  //F=15
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}




