#include <stdio.h>

int  max = 5;
int q[5];

int front = -1, rear = -1;
int isFull();
int isEmpty();
void Display();
void Enqueue();
void Dequeue();

int main(){
printf("\nCircular Queue Menu .....\n");
printf("\n1.Enqueue");
printf("\n2.Dequeue");
printf("\n3.Display");
printf("\n4.Exit\n");
int ch = 0;
int elem;
while(ch != 4){
	printf("\nEnter the choice : ");
	scanf("%d",&ch);
	if(ch == 1){
	printf("Enter element : ");
	scanf("%d", &elem);
	Enqueue(elem);}

	else if(ch==2){
	Dequeue();}
	else if(ch == 3){
	Display();}
}

}

int isFull(){
	if((rear+1)%max == front){
	printf("Queue is Full.....");
	return 1;}
	return 0;
}

int isEmpty(){
	if(front==-1 && rear ==-1){
	return 1;}
	return 0;
}

void Enqueue(int elem){
	if(isFull()){
	return;}
	else if(rear==-1 && front==-1){
	front = rear = 0;
	q[rear] = elem;
	}
	else{
	rear = (rear +1)%max;
	q[rear] = elem;}
}

void Dequeue(){
	if(isEmpty()){
	printf("Queue is empty ....");
	return;}
	else if(rear==front){
	front = rear = -1;
	}
	else{
	front = (front+1)%max;
	return;}
}

void Display(){
	if(isEmpty()){
	printf("\nQueue is Empty...");
    return;}
	else{
	printf("\nElements are ....\n");
	int i = front;
	for(i = front; i != rear; i= (i+1)%max){
	printf("%d " , q[i]);}}
	printf("%d" , q[rear]);
} 