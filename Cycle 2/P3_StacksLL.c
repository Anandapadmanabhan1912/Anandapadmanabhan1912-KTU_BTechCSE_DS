/*Name : Anandapadmanabhan B 
Batch: S3 CS-2 , Roll No. 15 
Date: 23/10/2023 
Stacks using Linked lists*/ 

#include <stdio.h>
#include <stdlib.h>

struct node{
 int data;
 struct node* link;
}head={0,NULL};

void Push();
void Pop();
void Display();

void main(){
	printf("\nMENU for STACK using Linked Lists:: ");
	printf("\n1. Push ");
	printf("\n2. Pop");
	printf("\n3. Display");
	printf("\n4. Exit");
	int ch = 0;
	while(ch != 4){
		printf("\nEnter Choice : ");
		scanf("%d" , &ch);
		switch(ch){
			case 1:
			Push();
			break;

			case 2:
			Pop();
			break;

			case 3:
			Display();
			break;

			case 4:
			exit(0);
			break;

		}
	}
}

void Push(){
	int data;
	printf("Enter the data to inserted: ");
	scanf("%d", &data);
 	struct node* new = (struct node*)malloc(sizeof(struct node));
 	struct node* ptr;
 	new->data = data;
 	new->link = NULL;
 	ptr = head.link;
 	if(ptr == NULL){
 		head.link = new;
 		return;
 	}
 	else{
 	while(ptr->link != NULL){
 	ptr = ptr->link;
 	}
	 ptr->link = new;}
}

void Pop(){
 	struct node* temp;
 	struct node* ptr = head.link;
 	if(ptr == NULL){
 		printf("\nUNDERFLOW error... Stack is Empty..");
 		return;
 	}
 	if(ptr->link ==NULL){
 		temp = head.link;
 		head.link = NULL;
 	}
 	else{
 	while((ptr->link)->link != NULL){
 		ptr  = ptr->link;
		}
 	temp = ptr->link;
 	ptr->link = NULL;}
 	if(temp != NULL){
 		free(temp);
	}
}

void Display(){
	struct node* ptr = head.link;
	if(ptr == NULL){
 		printf("\nUNDERFLOW error... Stack is Empty..");
 		return;
 	}
 	
 	while(ptr->link != NULL){
 		printf("%d -> ", ptr->data); 
 		ptr = ptr->link;
	}
 	printf("%d -> ", ptr->data);
 	printf("TOP \n");
}
