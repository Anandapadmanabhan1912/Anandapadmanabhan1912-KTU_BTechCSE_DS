#include <stdio.h>
#include <stdlib.h>

struct Node
{
    size_t size;
    struct Node *next;
    struct Node *prev;
    int isFree;
};

struct MemoryAllocator
{
    struct Node *head;
};
void initializeMemoryAllocator(struct MemoryAllocator *allocator, size_t totalSize)
{
    allocator->head = (struct Node *)malloc(sizeof(struct Node));
    allocator->head->size = 0;
    allocator->head->next = (struct Node *)malloc(totalSize - sizeof(struct Node));
    allocator->head->next->prev = allocator->head;
    allocator->head->next->next = NULL;
    allocator->head->next->size = totalSize - sizeof(struct Node);
    allocator->head->next->isFree = 1;
}

void *allocateMemory(struct MemoryAllocator *allocator, size_t requestedSize)
{
    struct Node *current = allocator->head;

    while (current != NULL)
    {
        if (current->isFree && current->size >= requestedSize)
        {

            size_t remainingSize = current->size - requestedSize;

            if (remainingSize >= sizeof(struct Node))
            {

                struct Node *newBlock = (struct Node *)((char *)current + requestedSize + sizeof(struct Node));
                newBlock->size = remainingSize - sizeof(struct Node);
                newBlock->next = current->next;
                newBlock->prev = current;
                newBlock->isFree = 1;

                current->size = requestedSize;
                current->next = newBlock;
                if (newBlock->next != NULL)
                {
                    newBlock->next->prev = newBlock;
                }
            }

            current->isFree = 0;
            return (char *)current + sizeof(struct Node);
        }

        current = current->next;
    }

    return NULL;
}

void deallocateMemory(struct MemoryAllocator *allocator, void *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    struct Node *block = (struct Node *)((char *)ptr - sizeof(struct Node));
    block->isFree = 1;

    if (block->prev != NULL && block->prev->isFree)
    {
        block->prev->next = block->next;
        if (block->next != NULL)
        {
            block->next->prev = block->prev;
        }
        block->prev->size += block->size + sizeof(struct Node);
        block = block->prev;
    }

    if (block->next != NULL && block->next->isFree)
    {
        block->size += block->next->size + sizeof(struct Node);
        block->next = block->next->next;
        if (block->next != NULL)
        {
            block->next->prev = block;
        }
    }
}

void displayMemoryBlocks(struct MemoryAllocator *allocator)
{
    printf("Memory Blocks:\n");
    struct Node *current = allocator->head;

    while (current != NULL)
    {
        printf("Block: %p, Size: %zu, Free: %s\n",
               (void *)current, current->size, current->isFree ? "Yes" : "No");
        current = current->next;
    }

    printf("\n");
}

void freeMemoryAllocator(struct MemoryAllocator *allocator)
{
    if (allocator->head != NULL)
    {
        free(allocator->head->next);
        free(allocator->head);
        allocator->head = NULL;
    }
}

int main()
{
    struct MemoryAllocator allocator;
    initializeMemoryAllocator(&allocator, 1024);

    void *ptr1 = allocateMemory(&allocator, 100);
    void *ptr2 = allocateMemory(&allocator, 200);
    void *ptr3 = allocateMemory(&allocator, 300);

    displayMemoryBlocks(&allocator);

    deallocateMemory(&allocator, ptr2);

    displayMemoryBlocks(&allocator);

    freeMemoryAllocator(&allocator);

    return 0;
}
