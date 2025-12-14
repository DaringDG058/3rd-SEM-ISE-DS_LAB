#include<stdio.h>
#include<ctype.h>
#define SIZE 50
char stack[SIZE];
int top=-1;

void push(char ch){
	if (top == SIZE -1){
		printf("Stack Overflow\n");
	}else{
		stack[++top] = ch;
	}
}

char pop(){
	if (top == -1){
		return -1;
	}else{return stack[top--];
	}
}

int precedence(char symbol){
	switch(symbol){
		case'^': return 3;
		case'*': 
		case'/': return 2;
		case'+': 
		case'-': return 1;
		default: return 0;
		}
}

void infixtopostfix(char infix[]){
	char postfix[SIZE];
	int i,j = 0;
	char ch, temp;
	printf("The Infix Expression is : %s\n", infix);

	for(i=0; infix[i]!= '\0'; i++){
		ch = infix[i];
		if (isalnum(ch)){
			postfix[j++] = ch;
		}

		else if (ch == '('){
			push(ch);
		}

		else if (ch == ')'){
			while((temp=pop())!='(')
				postfix[j++]=temp;
		}

		else {
			while(precedence(stack[top])>=precedence(ch)){
				postfix[j++]=pop();
			}
			
			push(ch);
		}
	}

	while (top!=-1){
		postfix[j++]=pop();
	}

	postfix[j]='\0';

	printf("The postfix expression is %s\n", postfix);

}

int main(){
	char infix[SIZE];
	printf("Enter an Infix Expression: ");
	scanf("%s", infix);
	infixtopostfix(infix);
	return 0;
}
