#include <stdio.h>

struct terms{
    int row;
    int col;
    int elem;
}A[20],B[20],C[20];

void readSparse(struct terms A[20]);
void printSparse(struct terms A[20]);
void transpose(struct terms A[20] , struct terms B[20]);
int add(struct terms A[20], struct terms B[20], struct terms C[20]);

int main(){
    int ch = 0;
    printf("\nMenu ......");
    printf("\n1. Conversion of matrix to tuple form.");
    printf("\n2. Display the matrix in tuple form.");
    printf("\n3. Find the transpose of a matrix represented in tuple form.");
    printf("\n4. Find the sum of the two matrices in tuple form.");

    while(ch != 5){
        printf("\nEnter choice :: ");
        scanf("%d" , &ch);
        if(ch == 1){
            readSparse(A);
        }
        else if(ch == 2){
            printSparse(A);
        }
        else if(ch == 3){
            transpose(A,C);
            printf("\nTranspose of matrix.....");
            printSparse(C);
        }
        else if(ch == 4){
            printf("\nMatrix A...");
            readSparse(A);
            printf("\nMatrix B...");
            readSparse(B);
            if(add(A,B,C)){
                printf("\nMatrix A + B...");
                //add(A,B,C);
                printSparse(C);
            }
        }
    }
}

void readSparse( struct terms A[20]){
    int row, col;
    printf("\nEnter no. of rows : ");
    scanf("%d", &row);
    printf("Enter no. of cols : ");
    scanf("%d", &col);
    printf("Enter the matrx elements.....\n");
    int temp;
    int i = 0,j=0, k=1;
    A[0].row = row;
    A[0].col = col;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%d", &temp);
            if(temp){
                A[k].row = i;
                A[k].col = j;
                A[k].elem = temp;
                k++;
            }
        }
    }
    A[0].elem = k-1;
}

void printSparse(struct terms A[20]){
    printf("\nRow Col Elems\n");
    int k = A[0].elem;
    int i = 0;
    for(i = 0; i<=k; i++){
        printf("\n  %d   %d   %d" , A[i].row, A[i].col, A[i].elem);
    }
}

void transpose(struct terms A[20] , struct terms B[20]){
    int i = 0, j = 0;
    int curr = 1;
    int k = A[0].elem;
    B[0].row = A[0].col;
    B[0].col = A[0].row;
    B[0].elem = A[0].elem;
    for(i = 0; i<A[0].col; i++){
        for(j = 1; j<=k; j++){
            if(i == A[j].col){
                B[curr].row = i;
                B[curr].col = A[j].row;
                B[curr].elem = A[j].elem;
                curr ++;}
        }
    }
    
    if(curr-1 == B[0].elem){
        printf("\nTranspose successful......");
    }
}

int add(struct terms A[20], struct terms B[20], struct terms C[20]){
    if(A[0].row != B[0].row || A[0].col != A[0].row){
        printf("\nInvalid Matrices.....\n");
        return 0;
    }
    int a, b, c;
    a = b = c = 1;
    C[0].row = A[0].row;
    C[0].col = A[0].col;
    while(a<=A[0].elem && b<=B[0].elem){
        if(A[a].row == B[b].row){
            if(A[a].col == B[b].col){
                if(A[a].elem + B[b].elem){
                C[c].row = A[a].row;
                C[c].col = A[a].col;
                C[c].elem = A[a].elem + B[b].elem;
                a++;
                b++;
                c++;}
            }
            else if(A[a].col<B[b].col){
                C[c].row = A[a].row;
                C[c].col = A[a].col;
                C[c].elem = A[a].elem;
                c++;
                a++;
            }
            else{
                C[c].row = B[b].row;
                C[c].col = B[b].col;
                C[c].elem = B[b].elem;
                c++;
                b++;
        }}
        else if(A[a].row<B[b].row){
            C[c].row = A[a].row;
            C[c].col = A[a].col;
            C[c].elem = A[a].elem;
            c++;
            a++;
        }
        else{
            C[c].row = B[b].row;
            C[c].col = B[b].col;
            C[c].elem = B[b].elem;
            c++;
            b++;
        }
    }
    while(a<=A[0].elem){
        C[c].row = A[a].row;
        C[c].col = A[a].col;
        C[c].elem = A[a].elem;
        c++;
        a++;
    }
    while(b<=B[0].elem){
        C[c].row = B[b].row;
        C[c].col = B[b].col;
        C[c].elem = B[b].elem;
        c++;
        b++;
    }
    C[0].elem = --c;
    printf("Addition Successful....\n");
    return 1;
}

// void DisplayMat(struct terms A[20]){
//     int i = A[0].row;
//     int j = A[0].col;
//     int a = 0, b = 0;
//     int c = 0;
//     for(a; a<i; a++){
//         for(b; b<j; b++){
//             if(a == A[c].row && b == A[c].col){
//                 printf("%d ", A[c].elem);
//                 c++;
//             }
//             else{
//                 printf("0  ");
//             }
//         }
//         printf("\n");
//     }
// }