#include<stdio.h>
#include<ctype.h>
#define SIZE 50
int stack[SIZE];
int top=-1;

void push(int item){
	if (top == SIZE -1){
		printf("Stack Ovrflow\n");
		return;
	}else{ stack [++top]=item;
	}
}

int pop(){
	if(top==-1){
		printf("Stack Underflow\n");
		return -1;
	}
	else { return stack[top--];
	}
}

int evalpost(char exp[]){
	int i;
	char ch;
	int op1, op2, result;

	for (i=0; exp[i]!= '\0'; i++){
		ch = exp[i];
		if(isdigit(ch)){
			push(ch-'0');
		}
		else{
			op1 = pop();
			op2 = pop();
			switch(ch){
				case'+' : result = op2 + op1; break;
				case'-' : result = op2 - op1; break;
				case'*' : result = op2 * op1; break;
				case'/' : result = op2 / op1; break;
				case'^' : result = op2 ^ op1; break;

				default :
					  printf("Invalid Operator \n");

				return -1;

			}
			push (result);
		}
	}
	return pop();
}

int main(){
	char exp[SIZE];
	int final_result;
	printf("Enter a Postfix Expression(single digit only) : ");
	scanf("%s", exp);
	final_result = evalpost(exp);
	printf("The result of the Expression is : %d\n", final_result);
	return 0;
}
