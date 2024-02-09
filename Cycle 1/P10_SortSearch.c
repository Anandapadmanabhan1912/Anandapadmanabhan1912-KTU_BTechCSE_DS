#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Name: Anandapadmanabhan.B 
Batch: S3 CS-2, Roll No. 15, 
Date: 16/11/2023,
Sort and perform Binary Search*/

// Function to sort an array of strings using bubble sort
void bubbleSort(char **names, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            char *buffer = NULL;
            // Compare adjacent strings and swap if necessary
            if (strcmp(names[j], names[j + 1]) > 0) {
                buffer = names[j];
                names[j] = names[j + 1];
                names[j + 1] = buffer;
            }
        }
    }
}

// Function to perform binary search on a sorted array of strings
int binary_search(char **names, int low, int high, char *term) {
    if (low <= high) {
        int mid = (high + low) / 2;
        int num = strcmp(term, names[mid]);
        if (num == 0) {
            return mid; // Element found at mid index
        } else if (num < 0) {
            return binary_search(names, low, mid - 1, term); // Search in the left half
        } else {
            return binary_search(names, mid + 1, high, term); // Search in the right half
        }
    }
    return -1; // Element not found
}

// Function to display the array of strings
void display(char **names, int n) {
    printf("The names are:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", names[i]);
    printf("\n");
}

int main() {
    char name1[10];
    printf("Enter the filename (with extension): ");
    scanf("%s", name1);
    FILE *file = fopen(name1, "r");
    int count = 0;
    char buffer[100];
    char **names = NULL;
    
    if (file == NULL)
        return -1; // Exit if file opening fails
    
    // Read names from file and dynamically allocate memory
    while (fscanf(file, "%s", buffer) == 1) {
        names = (char **)realloc(names, (count + 1) * sizeof(char *));
        names[count++] = strdup(buffer);
    }
    
    fclose(file);
    
    printf("Before Sorting: ");
    display(names, count);
    
    // Sort the array of names
    bubbleSort(names, count);
    
    printf("After Sorting: ");
    display(names, count);
    
    printf("Enter the name to be searched: ");
    scanf("%s", name1);
    
    // Perform binary search and display the position of the name
    printf("The position of the Name is %d\n", binary_search(names, 0, count - 1, name1));
    
    // Free dynamically allocated memory
    for (int i = 0; i < count; i++) {
        free(names[i]);
    }
    free(names);

    return 0;
}
