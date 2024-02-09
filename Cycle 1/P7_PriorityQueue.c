#include<stdio.h>
#include<stdlib.h>

struct priority
{
	int value;
	int priority;
	
};


#define max 8
int front=-1;
int rear=-1;

struct priority queue[8];

void enqueue(struct priority pq[]);
void display(struct priority pq[]);
void dequeue(struct priority pq[]);

void main()
{
	int ch;

    printf("Menu\n");
	printf("------------------------\n");
	printf("1:Add\n2:Delete\n3:Display\n4.Exit");
	display(queue);

    while(1)
	{
		printf("\nChoice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
			{
				enqueue(queue);
				break;
			}
			case 2:
			{
				dequeue(queue);
				break;
			}
			case 3:
			{
				display(queue);
				break;
			}
			case 4:
			{
				exit(0);
				break;
			}
			default:
			{
				printf("\nNo valid selection\n");
			}
		}
	}	
}
void enqueue(struct priority pq[])
{
		int item;
		int P , value;
		int i;
		int loc;
		if(front==0 && rear==max-1)
		{
			printf("\nQueue overflow!!!\n\n");

		}
		else if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
			printf("Enter new element: ");
			scanf("%d",&pq[rear].value);
			printf("Enter priority: ");
			scanf("%d",&pq[rear].priority);
		}
		else 
		{
			printf("Enter new element: ");
			scanf("%d",&item);
			printf("Enter priority: ");
			scanf("%d",&P);
			

			if(rear==max-1)
			{
				for(i=front;i<=rear;i++)
				{
				pq[i-1].value=pq[i].value;
				pq[i-1].priority=pq[i].priority;
				}
				front--;
				rear--;

			}
			
			for(i=rear;i>=front;i--)
			{
				if(pq[i].priority<P)
				{
					break;
				}
			}
			loc=i+1;
			for(i=rear;i>=loc;i--)
			{
				pq[i+1].value=pq[i].value;
				pq[i+1].priority=pq[i].priority;
				
			}
			pq[loc].value=item;
			pq[loc].priority=P;
			rear++;

		}
		display(pq);
}
	void display(struct priority pq[])
	{
		int i;
		if(front==-1&&rear==-1)
		{
			printf("\nNo element in queue\n");
		}
		else 
		{
			printf("\nQueue: ");
			for(i=front;i<=rear;i++)
			{
				printf("%d(%d)   ",pq[i].value,pq[i].priority);
			}
		
		}
	}
	void dequeue(struct priority pq[])
	{
		if(front==-1||rear==-1)
		{
			printf("Queue underflow!!!!\n\n");
		}
		else if(rear==front)
		{
			printf("Deleted item: %d with priority %d",pq[front].value,pq[front].priority);
			front=-1;
			rear=-1;
		}
		else
		{
			printf("Deleted item: %d with priority %d",pq[front].value,pq[front].priority);
			front++;
		}
		display(pq);
	}