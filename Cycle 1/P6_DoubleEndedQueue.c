#include <stdio.h>

int max = 5;
int q[5];

void insertfront(int elem);
void insertback(int elem);
void deletefront();
void deleteback();
void Display();

int front = -1, rear = -1;

int main(){
	printf("\nDouble Ended Queue...");
	printf("\n1.InsertAtFront");
	printf("\n2.InsertAtBack");
	printf("\n3.DeleteAtback");
	printf("\n4.DeleteAtFront");
	printf("\n5.Display");
	printf("\n6.Exit\n");
	int ch = 0;
	int elem;
	while(ch != 6){
		printf("\nEnter Choice : ");
		scanf("%d" , &ch);

		if(ch == 1){
			printf("Enter Element : ");
			scanf("%d" , &elem);
			insertfront(elem);
		}
		else if(ch == 2){
			printf("Enter Element : ");
			scanf("%d" , &elem);
			insertback(elem);
		}
		else if(ch == 3){
			deleteback();
			printf("Element deleted at back..");
		}
		else if(ch == 4){
			deletefront();
			printf("Element deleted at front..");
		}
		else if(ch == 5){
			Display();
		}
	}
}

void insertfront(int elem){
	if(front == -1 && rear==-1){
		front = 0;
		rear = 0;
		q[front] = elem;
	}
	else if((front-1)%max== rear){
		printf("Queue is Full....");
	}
	else{
		front = (front-1)%max;
		q[front] = elem;
	}
}
void insertback(int elem){
	if(front == -1 && rear==-1){
		front = 0;
		rear = 0;
		q[front] = elem;
	}
	else if((rear+1)%max == front){
		printf("\nQueue is Full....");
	}
	else{
		rear = (rear+1)%max;
		q[rear]= elem;
	}
}

void deletefront(){
	if(front == -1 && rear ==-1){
		printf("\nQueue is Empty....");
	}
	else if(front == rear){
		rear = -1;
		front = -1;
	}
	else{
		front = (front+1)%max;
	}
}

void deleteback(){
	if(front == -1 && rear ==-1){
		printf("\nQueue is Empty....");
	}
	else if(front == rear){
		rear = -1;
		front = -1;
	}
	else{
		rear = (rear-1)%max;
	}
}

void Display(){
	if(front == -1 && rear ==-1){
	printf("\nQueue is Empty...");}
	else{
	printf("\nElements are ....\n");
	int i = front;
	for(i = front; i != rear; i= (i+1)%max){
	printf("%d " , q[i]);}}
	printf("%d" , q[rear]);
}