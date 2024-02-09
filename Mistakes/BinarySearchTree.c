#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* lc;
    struct Node* rc;
}Node;

Node* head = NULL;
int insertNode(int item);
int deleteNode(int item, Node* root);
Node* inorderSucc(Node* item);

void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);

void freeAll(Node* root);


int insertNode(int item) {
    if (head == NULL) {
        head = (Node*)malloc(sizeof(Node));
        if (head == NULL) {
            printf("Memory allocation failed.\n");
            return 0;
        }
        head->data = item;
        head->lc = NULL;
        head->rc = NULL;
        return 1;
    }

    Node* ptr = head;
    Node* par = NULL;
    while (ptr != NULL) {
        par = ptr;
        if (ptr->data > item) {
            ptr = ptr->lc;
        } else if (ptr->data < item) {
            ptr = ptr->rc;
        } else {
            printf("\nItem already exists in BST.\n");
            return 0;
        }
    }

    ptr = (Node*)malloc(sizeof(Node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }
    ptr->data = item;
    ptr->rc = NULL;
    ptr->lc = NULL;
    if (par->data > item) {
        par->lc = ptr;
    } else {
        par->rc = ptr;
    }
    return 1;
}


int deleteNode(int item, Node* root){
    Node* ptr;
    Node* par;
    char ch;
    ptr = root;
    if(root->data == item){
        head = NULL;
        free(ptr);
    }
    while(ptr != NULL){
        par = ptr;
        if(item > ptr->data){
            ch = 'r';  
            ptr = ptr->rc;
        }
        else if(item < ptr->data){
            ptr = ptr->lc;
            ch = 'l';
        }
        else{
            break;
        }
    }
    if(ptr == NULL){
        printf("\nItem doesn't exist in BST...\n");
        return 0;
    }
    if(ptr->lc==NULL && ptr->rc==NULL){
        if(ch == 'r')
            par->rc = NULL;
        else
            par->lc = NULL;
        free(ptr);
        return 1;
    }
    else if(ptr->rc != NULL){
        if(ch== 'r')
            par->rc = ptr->rc;
        if(ch == 'l')
            par->lc = ptr->rc;
        free(ptr);
    }
    else if(ptr->lc != NULL){
        if(ch== 'r')
            par->rc = ptr->lc;
        if(ch == 'l')
            par->lc = ptr->lc;
        free(ptr);
    }
    else{
        Node* succ = inorderSucc(ptr);
        ptr -> data = succ->data;
        return deleteNode(succ->data, root);
    }
    return 1;
}

Node* inorderSucc(Node* item){
    Node* ptr = item->rc;
    Node* prev;
    while(ptr != NULL){
        prev = ptr;
        ptr = ptr->lc;
    }
    return prev;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->lc);
    printf("%d " , root->data);
    inorder(root->rc);
    return;
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    printf("%d " , root->data);
    preorder(root->lc);
    preorder(root->rc);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->lc);
    postorder(root->rc);
    printf("%d " , root->data);
}

void freeAll(Node* root){
    if(root == NULL)
        return;
    freeAll(root->lc);
    freeAll(root->rc);
    free(root);
}

int main(){
    printf("\n :: MENU ::\n");
    printf("\n1. Insert a Node");
    printf("\n2. Delete a Node");
    printf("\n3. Inorder traversal");
    int ch =0;
    int item;
    while(ch != 6){
        printf("\nEnter the choice : ");
        scanf(" %d" , &ch);
        switch(ch){
            case 1:
            printf("Enter the item inserted: ");
            scanf(" %d" , &item);
            item = insertNode(item);
            if(item){
                printf("\nItem  has been inserted  into BST successfully....");
            }
            else{
                printf("\nItem  NOT inserted  into BST....");
            }      
            break;

            case 2:
            printf("Enter the item : ");
            scanf(" %d" , &item);
            item = deleteNode(item , head);
            if(item){
                printf("\nItem  has been deleted from BST successfully....");
            }
            else{
                printf("\nItem  NOT deleted from BST....");
            }
            break;

            case 3:
            inorder(head);
            break;

            case 4:
            postorder(head);
            break;

            case 5:
            preorder(head);
            break;

            case 6:
            printf("\nExiting.....");
            break;

            default:
            printf("\nNot apt choice....");
            break;
        }
    }
    freeAll(head);
}