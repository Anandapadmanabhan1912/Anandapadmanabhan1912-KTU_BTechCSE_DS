/*Name : Anandapadmanabhan B 
Batch: S3 CS-2 , Roll No. 15 
Date: 23/10/2023 
Linked list operations*/ 

#include <stdio.h>
#include <stdlib.h>

struct node{
 int data;
 struct node* link;
}head={0,NULL};


void insert_head(int data);
void insert_end(int data);
void insert_after(int key, int data);
void delete_head();
void delete_end();
void delete_key(int key);
void display();

int main(){

// 	struct node head;
// 	head.data = 0;
// head.link = NULL;
	printf("MENU \n");
	printf("1.Insert a head....\n");
	printf("2.Insert at end...\n");
	printf("3.Insert after key...\n");
	printf("4.Delete at head...\n");
	printf("5.Delete at end...\n");
	printf("6.Delete after key...\n");
	printf("7.Display .. \n");
	printf("8.Exit...\n");
	int ch = 0;
	int dt , key;
	while(ch != 8){
		printf("\nEnter choice: ");
		scanf("%d" , &ch);
		switch(ch){
			case 1:
			printf("Enter the number : ");
			scanf("%d", &dt);
			insert_head(dt);
			break;

			case 2:
			printf("Enter the number : ");
			scanf("%d", &dt);
			insert_end(dt);
			break;
			
			case 3:
			printf("Insert number after: ");
			scanf("%d", &key);
			printf("Enter the number : ");
			scanf("%d", &dt);
			insert_after(key,dt);
			printf("Element %d inserted after %d...", dt, key);
			break;

			case 4:
			delete_head();
			printf("Deleted element at the head...");
			break;

			case 5:
			delete_end();
			printf("Deleted element at the end...");
			break;

			case 6:
			printf("Enter element to be deleted: ");
			scanf("%d", &dt);
			delete_key(dt);
			printf("Deleted element  %d .....", dt);
			break;

			case 7:
			display();
			break;

			case 8:
			exit(0);
			break;

		}
	}
}

void insert_head(int data){
 struct node* new = (struct node*)malloc(sizeof(struct node));
 struct node* temp = head.link;
 new->data = data;
 new->link = temp;
 head.link = new;
 printf("%d is inserted at HEAD.." ,data );
}

void insert_end(int data){
 struct node* new = (struct node*)malloc(sizeof(struct node));
 struct node* ptr;
 new->data = data;
 new->link = NULL;
 ptr = head.link;
 while(ptr->link != NULL){
 ptr = ptr->link;
 }
 ptr->link = new;
}
void insert_after(int key, int data){
	struct node* new = (struct node*)malloc(sizeof(struct node));
 	struct node* ptr;
 	struct node* temp;
 	new->data = data;
 	ptr = head.link;
 	while(ptr->link != NULL && ptr->data!=key){
 	ptr = ptr->link;
 	}
 	if(ptr->data==key){
 		temp = ptr->link;
 		ptr->link = new;
 		new->link = temp;
 	}
 	else{
 		printf("%d is NOT FOUND hence can't insert data....", key);
 	}
}

void delete_head(){
 struct node* temp; 
 temp = head.link;
 head.link = temp->link;
 if(temp != NULL){
 free(temp);}
}


void delete_end(){
 struct node* temp;
 struct node* ptr = head.link;
 while((ptr->link)->link != NULL){
 ptr  = ptr->link;
}
 temp = ptr->link;
 ptr->link = NULL;
 if(temp != NULL){
 free(temp);
}
}
void delete_key(int key){
	// struct node* new = (struct node*)malloc(sizeof(struct node));
	struct node* ptr ;
	struct node* temp;
 // 	new->data = data;
 	ptr = head.link;
 	while(ptr->link != NULL && (ptr->link)->data != key){
 	ptr = ptr->link;
 	}
 	if(ptr->link == NULL){
 		return;
 	}
 	if((ptr->link)->data == key){
 		temp = ptr->link;
 		ptr->link = (ptr->link)->link;
 		free(temp);
 	}
 	else{
 		printf("%d is NOT FOUND hence can't delete data....", key);
 	}
}

void display(){
 struct node* ptr = head.link;
 while(ptr->link != NULL){
 printf("%d -> ", ptr->data); 
 ptr = ptr->link;
}
 printf("%d -> ", ptr->data);
 printf("END\n");
}