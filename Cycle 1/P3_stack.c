#include <stdio.h>

//Stacks as array named stk
//of size 10

int max =  10;
int stk[10];
int top = -1;

void pop(int stack[]);
void push(int stack[],int elem);
void display(int stack[]);

int main(){

	printf("Stack implementation using stacks:: \n ");
	printf("1. Push element into stack\n");
	printf("2.Pop elements from stack\n");
	printf("3.Display elements of stack\n");
	printf("4.Exit \n");
	int ch = 0;
	while(ch != 4){
	if(ch == 1){
	int elem;
	printf("Enter the element to be pushed : ");
	scanf("%d", &elem);
	push(stk , elem);
	}
	else if(ch == 2){
	pop(stk);
	}
	else if(ch == 3){
	display(stk);
	}
	printf("\nEnter choice again :; ");
	scanf("%d", &ch);
}
return 0;}

void push(int stack[], int elem){
	if(top == max-1)
	{
	printf("STACK OVERFLOW...\n");
	return ;}
	top = top +1;
	stack[top] = elem;
	return;
}

void pop(int stack[]){
	if(top == -1)
	{
	printf("STACK UNDERFLOW....\n");
	return ;}
	printf("%d", stack[top]);
	top = top -1;
}

void display(int stack[]){
	int i;
	for(i = 0; i<=top; i++)
	{
	printf("%d ", stack[i]);}
	return;
}
