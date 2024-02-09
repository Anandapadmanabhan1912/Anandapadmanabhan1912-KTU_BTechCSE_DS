/*Name : Anandapadmanabhan B 
Batch: S3 CS-2 , Roll No. 15 
Date: 23/10/2023 
Queues using Linked lists*/ 


#include <stdio.h>
#include <stdlib.h>

struct node{
 int data;
 struct node* link;
}head={0,NULL};

void Enqueue(int data){
 struct node* new = (struct node*)malloc(sizeof(struct node));
 struct node* ptr;
 new->data = data;
 new->link = NULL;
 ptr = head.link;
 if(ptr == NULL){
 	head.link = new;
 	return;
 }
 while(ptr->link != NULL){
 ptr = ptr->link;
 }
 ptr->link = new;
}
void Dequeue(){
 struct node* temp; 
 temp = head.link;
 if(temp==NULL){
 	printf("The queue is empty...");
 	return;
 }
 head.link = temp->link;
 if(temp != NULL){
 free(temp);}
}

void Display(){
 struct node* ptr = head.link;
 if(ptr==NULL){
 	printf("empty...");
 	return;
 }
 while(ptr->link != NULL){
 printf("%d -> ", ptr->data); 
 ptr = ptr->link;
}
 printf("%d -> ", ptr->data);
 printf("END\n");
}

int main(){
	printf("Queues using Linked List\n");
	printf("MENU\n");
	printf("1.Insert into Queue[Enqueue]\n");
	printf("2.Delete from Queue[Dequeue]\n");
	printf("3.Display\n");
	printf("4.Exit" );
	int ch = 0;
	int elem;
	while(ch != 4){
		printf("\nEnter the choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
			printf("Enter the element to be inserted: ");
			scanf("%d", &elem);
			Enqueue(elem);
			printf("%d is inserted...", elem);
			break;

			case 2:
			Dequeue();
			break;

			case 3:
			printf("Queue is\n");
			Display();
			break;
		}
	}
	printf("Exiting...");
}
