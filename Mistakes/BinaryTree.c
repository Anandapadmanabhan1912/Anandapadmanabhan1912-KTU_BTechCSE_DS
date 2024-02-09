#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* lc;
    struct Node* rc;
}Node;

Node* head = NULL;
Node* search_node(Node* ptr,int item);
Node* search_parent(Node* prev, Node* ptr, int item);
void insert_node(int item, Node* parent);
void delete_node(Node* parent , int item);
void inorder(Node* ptr);
void postorder(Node* ptr);
void preorder(Node* ptr);
void freeTree(Node* root);

int main(){
    printf("\nMENU :: \n");
    printf("1. Insert Node\n");
    printf("2. Inroder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Delete a Node and Subtree");
    printf("6. Exit\n");
    int item1;
    int ch = 0;
    int par;
    Node* par_res;
    while(ch != 6){
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the parent element: ");
            scanf("%d", &par);
            printf("Enter the item to be inserted: ");
            scanf("%d", &item1);
            par_res = search_node(head,par);
            insert_node(item1 , par_res);
            break;

            case 2:
            inorder(head);
            break;
            
            case 3:
            preorder(head);
            break;

            case 4:
            postorder(head);
            break;

            case 5:
            printf("Enter the Key to be deleted: ");
            scanf(" %d" , &item1);
            par_res = search_parent(NULL , head, item1);
            delete_node(par_res , item1);
            break;
        }
    }
    freeTree(head);
}

Node* search_parent(Node* prev, Node* ptr, int item){
    if (ptr == NULL) {
        return NULL;  // Return NULL instead of head
    }
    if (ptr->data == item) {
        return prev;
    } else {
        Node* res;

        if (ptr->lc != NULL) {
            res = search_parent(ptr, ptr->lc,item);
            if (res != NULL) {
                return res;
            }
        }

        if (ptr->rc != NULL) {
            res = search_parent(ptr,ptr->rc,item);
            if (res != NULL) {
                return res;
            }
        }

        // The else condition is not necessary, as both lc and rc are checked independently
        return NULL;
    }
}

void delete_node(Node* parent , int item){
    if(parent==NULL){
        printf("\nNode %d doesn't exist" , item);
        return;
    }
    Node* node_n;
    if(head->data == item){
        freeTree(head);
    }
    if(head->lc->data == item){
        node_n = head->lc;
        head->lc = NULL;
        freeTree(node_n);
        return;
    }
    else if (head->rc->data == item)
    {
        node_n = head->rc;
        head->rc = NULL;
        freeTree(node_n);
        return;
    }
    if(parent->lc->data == item){
        node_n =parent->lc;
        parent->lc = NULL;
        freeTree(node_n);
    }
    else if(parent->rc->data == item){
        node_n =parent->rc;
        parent->rc = NULL;
        freeTree(node_n);
    }
}

Node* search_node(Node* ptr, int item) {
    if (ptr == NULL) {
        return NULL;  // Return NULL instead of head
    }
    if (ptr->data == item) {
        return ptr;
    } else {
        Node* res;
        if (ptr->lc != NULL) {
            res = search_node(ptr->lc, item);
            if (res != NULL) {
                return res;
            }
        }
        if (ptr->rc != NULL) {
            res = search_node(ptr->rc, item);
            if (res != NULL) {
                return res;
            }
        }
        // The else condition is not necessary, as both lc and rc are checked independently
        return NULL;
    }
}

void insert_node(int item, Node* parent){
    if(parent==NULL && head!=NULL){
        printf("Parent node doesn't exist....\n");
        return;
    }
    if(head==NULL){
        head = (Node*)malloc(sizeof(Node));
        head->data = item;
        head->rc = NULL;
        head->lc = NULL;
        return;
    }
    char c;
    printf("Enter item as Right(r) or Left(l) child: ");
    scanf(" %c", &c);
    Node* new;
    switch (c)
    {
    case 'r':
        if(parent->rc == NULL){
            new = (Node*)malloc(sizeof(Node));
            new->data = item;
            new->lc = NULL;
            new->rc = NULL;
            parent->rc = new;
        }
        else{
            printf("INSERTION not possible\n");
        }
        break;
    case 'l':
        if(parent->lc == NULL){
            new = (Node*)malloc(sizeof(Node));
            new->data = item;
            new->lc = NULL;
            new->rc = NULL;
            parent->lc = new;
        }
        else{
            printf("INSERTION not possible\n");
        }
        break;
    default:
        break;
    }
}
void inorder(Node* ptr){
    if(ptr == NULL){
        return;
    }
    inorder(ptr->lc);
    printf("%d  ", ptr->data);
    inorder(ptr->rc);
}

void postorder(Node* ptr){
    if(ptr == NULL){
        return;
    }
    postorder(ptr->lc);
    postorder(ptr->rc);
    printf("%d  ", ptr->data);
}

void preorder(Node* ptr){
    if(ptr == NULL){
        return;
    }
    printf("%d  ", ptr->data);
    preorder(ptr->lc);
    preorder(ptr->rc);
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->lc);
    freeTree(root->rc);

    // Free the current node
    free(root);
}