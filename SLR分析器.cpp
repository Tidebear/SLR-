#include<stdio.h>    
#include<stdlib.h>
char str[50]; //������ַ��������ʷ��������ַ���
int i=0;//����ָ���ַ�����������ַ�
int o=1;//��־λ�������ж��Ƿ����ѭ��
typedef struct SqStack{
	char data[100];
	int top;
}SqStack;
SqStack s;//���״̬��ջ
SqStack t;//����ķ����ŵ�ջ
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
	printf("������Ҫ�жϵı��ʽ����;������"); 
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
	push(&s,'0'); //��״̬0��ջ�� 
	push(&t,'$');//�ѷ���$��ջ��
	while(o){
		if(judge()){
			
		}
		else{
			printf("����ı��ʽ");
			return 0;
		}
	}
	printf("��ȷ�ı��ʽ");
	
	return 0;
}
void InitStack(SqStack *s)//��ʼ��ջ 
{
	s->top=-1;
}

void push(SqStack *s,char e)//��ջ
{
	if(s->top==100-1)
	{	
		printf("ջ��\n");
	}
	s->data[++s->top]=e;		
}

void pop(SqStack *s)//��ջ
{
	if(s->top==-1)
	{
		printf("ջ��\n");
	}
	s->top--;
} 
bool judge()//�ѷ���$��tջ�� ��״̬0��sջ�� 
{
	if(s.top==t.top){
		if(s.data[s.top]=='0'||s.data[s.top]=='4'||s.data[s.top]=='7'||s.data[s.top]=='8'||s.data[s.top]=='9'||s.data[s.top]=='A'){
			if(str[i]=='i'){
				push(&s,'5');
				push(&t,'i'); //������һλΪ�ַ�ʱs5 
				i++;
			}
			else if(str[i]=='n'){//������һλΪ����ʱs6
				push(&s,'6');
				push(&t,'n'); 
				i++;
			}
			else if(str[i]=='('){//������һλΪ(ʱs4
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
				push(&t,'E');//��E��ջ����ԼΪE 
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




