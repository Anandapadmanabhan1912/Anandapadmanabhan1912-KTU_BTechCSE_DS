/*Name: Anandapadmanabhan.B
Batch: S3 CS-2, Roll No. 15,
Date: 19/12/2023,
Binary Search Tree operations*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}
struct Node *findMin(struct Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
struct Node *searchNode(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}
void displayMenu()
{
    printf("\nBinary Search Tree Operations Menu:\n");
    printf("1. Create a new tree\n");
    printf("2. Insert a new node\n");
    printf("3. Delete a node\n");
    printf("4. Search for a node\n");
    printf("5. Exit\n");
}
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int main()
{
    struct Node *root = NULL;
    int choice, data;
    displayMenu();
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            root = NULL;
            printf("Binary search tree created.\n");
            break;
        case 2:

            printf("Enter the element: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            printf("Node with data %d inserted.\n", data);
            break;
        case 3:

            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            printf("Node with data %d deleted.\n", data);
            break;
        case 4:

            printf("Enter data to search: ");
            scanf("%d", &data);
            struct Node *result = searchNode(root, data);
            if (result != NULL)
            {
                printf("Node with data %d found in the tree.\n", data);
            }
            else
            {
                printf("Node with data %d not found in the tree.\n", data);
            }
            break;
        case 5:
            printf("Exiting program. Bye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

        if (root != NULL)
        {
            printf("Current tree (inorder traversal): ");
            inorderTraversal(root);
            printf("\n");
        }

    } while (choice != 5);

    return 0;
}