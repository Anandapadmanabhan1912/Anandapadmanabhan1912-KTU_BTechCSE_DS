#include <stdio.h>
#include <stdlib.h>

int array[] = {12, 5, 23, 8, 19, 11, 27, 3, 16,8};

void printArray(int arr[], int n);
void swap(int *a, int *b);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[] , int l, int r);
void quickSort(int arr[], int l, int r);
int partition(int arr[], int l, int r);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void selectionSort(int arr[], int n){
    int minInd;
    for(int i = 0; i<n-1; i++){
        minInd = i;
        for(int j = i+1; j<n; j++){
            if(arr[minInd]>arr[j]){
                minInd = j;
            }
        }
        swap(&arr[minInd], &arr[i]);
        printArray(arr, n);
    }
}

void insertionSort(int arr[], int n){
    int i = 1;
    int value , hole;
    for(i =1 ; i<n; i++){
        value = arr[i];
        hole = i;
        while(hole >0 && arr[hole-1]>value){
            swap(&arr[hole-1],&arr[hole]);
            hole--;
        }
        printArray(arr,n);
    }
}

void printArray(int arr[], int n){
    printf("\n");
    for(int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
}

void heapify(int arr[], int n, int i){
    int large = i;
    int l = 2*i;
    int r = 2*i+1;

    if(r<n && arr[r]>arr[large]){
        large = r;
    }

    if(l<n && arr[l]>arr[large]){
        large = l;
    }

    if(large != i){
        swap(&arr[i], &arr[large]);
        heapify(arr , n, large);
    }
    printArray(arr , n);
}

void heapSort(int arr[], int n){
    for(int i = n/2; i>-1; i--){
        heapify(arr,n, i);
    }
    for(int i = n-1;i>-1; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i ,0);
    }
}

void merge(int arr[], int l, int mid, int r) {
    int lsub = mid - l + 1;
    int rsub = r - mid;
    int *larr = (int*)malloc(lsub * sizeof(int));
    int *rarr = (int*)malloc(rsub * sizeof(int));
    for (int i = 0; i < lsub; i++) {
        larr[i] = arr[l + i];
    }
    for (int i = 0; i < rsub; i++) {
        rarr[i] = arr[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < lsub && j < rsub) {
        if (larr[i] < rarr[j]) {
            arr[k] = larr[i];
            i++;
        } else {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < lsub) {
        arr[k] = larr[i];
        i++;
        k++;
    }
    while (j < rsub) {
        arr[k] = rarr[j];
        j++;
        k++;
    }
    free(larr);
    free(rarr);
}

void mergeSort(int arr[] , int l, int r){
    if(l >= r){
        return;
    }
    int mid = (l+r)/2;
    mergeSort(arr, l , mid);
    mergeSort(arr, mid+1, r);
    merge(arr , l, mid, r);
}

void quickSort(int arr[], int l, int r){
    if(l>=r){
        return;
    }
    int part = partition(arr,l,r);
    quickSort(arr, l,part-1);
    quickSort(arr , part+1,r);
}

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int count = l-1;
    for(int i = l; i<r; i++){
        if(arr[i]<=pivot){
            count++;
            swap(&arr[count], &arr[i]);
        }
    }
    swap(&arr[count+1], &arr[r]);
    printArray(arr, 10);
    return (count+1);
}

int main(){
    quickSort(array ,0, 10);
    printArray(array , 10);
    return 0;
}