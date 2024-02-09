#include <stdio.h>
#include <stdlib.h>

// Structure representing a memory block
typedef struct MemoryBlock {
    size_t size;
    struct MemoryBlock* prev;
    struct MemoryBlock* next;
} MemoryBlock;

// Global variable representing the start of the memory list
MemoryBlock* memoryList = NULL;

// Function to allocate memory
void* my_malloc(size_t size) {
    // Create a new memory block
    MemoryBlock* block = (MemoryBlock*)malloc(sizeof(MemoryBlock) + size);

    if (block == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Set the size of the block
    block->size = size;

    // Add the block to the beginning of the memory list
    block->next = memoryList;
    block->prev = NULL;

    if (memoryList != NULL) {
        memoryList->prev = block;
    }

    memoryList = block;

    // Return a pointer to the user-accessible memory
    return (void*)(block + 1);
}

// Function to deallocate memory
void my_free(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    // Get the pointer to the memory block
    MemoryBlock* block = ((MemoryBlock*)ptr) - 1;

    // Remove the block from the memory list
    if (block->prev != NULL) {
        block->prev->next = block->next;
    } else {
        memoryList = block->next;
    }

    if (block->next != NULL) {
        block->next->prev = block->prev;
    }

    // Free the memory block
    free(block);
}

// Function to print the memory blocks
void print_memory() {
    MemoryBlock* current = memoryList;

    printf("Memory Blocks:\n");

    while (current != NULL) {
        printf("Address: %p, Size: %zu\n", current + 1, current->size);
        current = current->next;
    }

    printf("\n");
}

int main() {
    // Example usage of the memory allocator and garbage collector

    // Allocate memory blocks
    int* a = (int*)my_malloc(sizeof(int));
    int* b = (int*)my_malloc(sizeof(int));
    char* c = (char*)my_malloc(10 * sizeof(char));

    // Print memory blocks
    print_memory();

    // Free one block
    my_free(b);

    // Print memory blocks after freeing
    print_memory();

    // Free the remaining blocks
    my_free(a);
    my_free(c);

    // Print memory blocks after freeing all
    print_memory();

    return 0;
}