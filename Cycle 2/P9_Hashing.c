#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct HashTableChaining
{
    struct Node *table[10];
};

struct HashTableLinearProbing
{
    int table[10];
};

void initializeHashTableChaining(struct HashTableChaining *ht)
{
    for (int i = 0; i < 10; ++i)
    {
        ht->table[i] = NULL;
    }
}

void insertChaining(struct HashTableChaining *ht, int key)
{
    int index = key % 10;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if (ht->table[index] == NULL)
    {
        ht->table[index] = newNode;
    }
    else
    {

        struct Node *current = ht->table[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayHashTableChaining(struct HashTableChaining *ht)
{
    for (int i = 0; i < 10; ++i)
    {
        printf("Index %d: ", i);

        struct Node *current = ht->table[i];
        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }

        printf("NULL\n");
    }
}

void initializeHashTableLinearProbing(struct HashTableLinearProbing *ht)
{
    for (int i = 0; i < 10; ++i)
    {
        ht->table[i] = -1;
    }
}

void insertLinearProbing(struct HashTableLinearProbing *ht, int key)
{
    int index = key % 10;

    while (ht->table[index] != -1)
    {
        index = (index + 1) % 10;
    }

    ht->table[index] = key;
}

void displayHashTableLinearProbing(struct HashTableLinearProbing *ht)
{
    for (int i = 0; i < 10; ++i)
    {
        printf("Index %d: ", i);
        if (ht->table[i] != -1)
        {
            printf("%d", ht->table[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct HashTableChaining htChaining;
    initializeHashTableChaining(&htChaining);

    struct HashTableLinearProbing htLinearProbing;
    initializeHashTableLinearProbing(&htLinearProbing);

    int choice, key;
    printf("\nMenu:\n");
    printf("1. Insert into Chaining Hash Table\n");
    printf("2. Display Chaining Hash Table\n");
    printf("3. Insert into Linear Probing Hash Table\n");
    printf("4. Display Linear Probing Hash Table\n");
    printf("5. Exit\n");

    do
    {   printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert into Chaining Hash Table: ");
            scanf("%d", &key);
            insertChaining(&htChaining, key);
            break;

        case 2:
            printf("Chaining Hash Table:\n");
            displayHashTableChaining(&htChaining);
            break;

        case 3:
            printf("Enter key to insert into Linear Probing Hash Table: ");
            scanf("%d", &key);
            insertLinearProbing(&htLinearProbing, key);
            break;

        case 4:
            printf("Linear Probing Hash Table:\n");
            displayHashTableLinearProbing(&htLinearProbing);
            break;

        case 5:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
