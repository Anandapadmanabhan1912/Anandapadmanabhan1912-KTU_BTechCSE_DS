/*Name: Anandapadmanabhan.B
Batch: S3 CS-2, Roll No. 15,
Date: 30/11/2023,
Binary Tree operations*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* root = NULL;

Node* search(Node* root, int elem) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == elem) {
        return root;
    } else {
        Node* ptr;
        if (root->left != NULL) {
            ptr = search(root->left, elem);
            if (ptr != NULL) {
                return ptr;
            }
        }
        if (root->right != NULL) {
            ptr = search(root->right, elem);
            if (ptr != NULL) {
                return ptr;
            }
        }
    }
    return NULL;
}

void insert_elem(Node** root, int parentElem, int elem) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->data = elem;
        (*root)->right = (*root)->left = NULL;
        return;
    }
    Node* parent = search(*root, parentElem);
    if (parent == NULL) {
        printf("\nParent Node %d not found", parentElem);
        return;
    }

    if (parent->left == NULL) {
        Node* child = (Node*)malloc(sizeof(Node));
        child->data = elem;
        child->left = child->right = NULL;
        parent->left = child;
    } else if (parent->right == NULL) {
        Node* child = (Node*)malloc(sizeof(Node));
        child->data = elem;
        child->left = child->right = NULL;
        parent->right = child;
    } else {
        printf("\nNo space available under PARENT NODE %d", parentElem);
    }
}

Node* search_parent(Node* root, int elem) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return NULL;
    }

    if (root->left != NULL && (root->left)->data == elem) {
        return root;
    } else if (root->right != NULL && (root->right)->data == elem) {
        return root;
    }

    Node* parent = search_parent(root->left, elem);
    if (parent != NULL) {
        return parent;
    } else {
        return search_parent(root->right, elem);
    }
}

void delete(Node** root, int elem) {
    Node* parent = search_parent(*root , elem);
    if (parent != NULL) {
        if((parent->right)->data == elem) {
            Node* fr = parent->right;
            parent->right = NULL;
            free(fr);
        }
        else if((parent->left)->data == elem){
            Node* fr = parent->left;
            parent->left = NULL;
            free(fr);
        }
    }
    else{
        if((*root)->data == elem && (*root)->left== NULL && (*root)->right == NULL){
            *root = NULL;
        }
        else{
            printf("\nNo suitable Leaf found....");
        }
    }
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    } else {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    } else {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root == NULL) {
        return;
    } else {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    printf("MENU:: ");
    printf("\n1. Insert a Node");
    printf("\n2. Inorder Traversal");
    printf("\n3. Postorder Traversal");
    printf("\n4. Preorder Traversal");
    printf("\n5. Delete a Node");
    printf("\n6. Exit");
    int ch = 0;
    int elem;
    int parent;
    while (ch != 6) {
        printf("\nEnter the choice = ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                printf("Enter the parent element = ");
                scanf("%d", &parent);
                printf("Enter the element = ");
                scanf("%d", &elem);
                insert_elem(&root, parent, elem);
                break;
            }
            case 2: {
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            }
            case 3: {
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            }
            case 4: {
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            }
            case 5: {
                printf("Enter the element to delete = ");
                scanf("%d", &elem);
                delete(&root, elem);
                break;
            }
            case 6: {
                // Exit
                printf("\nExit....\n");
                break;
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}
