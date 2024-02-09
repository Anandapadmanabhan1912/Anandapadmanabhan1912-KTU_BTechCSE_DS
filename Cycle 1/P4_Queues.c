#include<stdio.h>
// Let array que of size MAX = 10
//

int max = 10;
int que[10];

void enqueue(int q[],int elem);
void dequeue(int q[]);
void display(int q[]);

int rear = -1;
int front = -1;

int main(){
	printf("\nQueue implementation using arrays....");
	printf("\n1.Insert elemetnts to queue");
	printf("\n2.Remove elemnts formm queue");
	printf("\n3.Display elemets of queue");
	printf("\n4.Exit");
	int ch = 0, elem;
	while(ch != 4){
		printf("\nEnter choice :: ");
		scanf("%d", &ch);
		switch(ch){
		case 1:
		printf("Enter element : ");
		scanf("%d", &elem);
		enqueue(que, elem);
		break;

		case 2:
		dequeue(que);
		break;

		case 3:
		display(que);
		break;
	}
	}
}

void enqueue(int q[], int elem){
	if(front == -1 && rear==-1){
		front = 0;
		rear = 0;
	}
	else if(rear == max-1){
		printf("\nQUEUE OVERFLOW..");
		return;
	}
	else{
		rear = rear + 1; 
	}
	q[rear] = elem;
}

void dequeue(int q[]){
	if(front == -1 && rear ==-1){
		printf("\nUNDERFLOW QUEUE....");
		return;
	}
	else if(front == rear){
		printf("\n%d", q[front]);
		front = -1;
		rear = -1;
		return;
	}
	else{
		printf("\n%d" , q[front]);
		front = front + 1;
		return;
	}
}

void display(int q[])
{	
	if(front == -1 && rear ==-1){
		printf("\nUNDERFLOW QUEUE....");
		return;
	}
	int i = front;
	for(i; i<=rear; i++){
		printf("%d ", q[i]);
	}
	printf("\n");
}
