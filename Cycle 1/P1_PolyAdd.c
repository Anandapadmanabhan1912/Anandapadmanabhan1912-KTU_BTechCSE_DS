#include <stdio.h>
#include <stdlib.h>

struct terms
{
    /* data */
    int exp;
    int coeff;
}A[21], B[21], D[21];

int main(){
    int i = 0, j= 0, k= 0;
    int DegA, DegB;
    int exp=0, coeff=0;
    printf("Polynomials A and B \n\n");
    printf("Enter the Degree of Polynomial A : ");
    scanf("%d", &DegA);
    printf("Enter the Degree of Polynomial B : ");
    scanf("%d", &DegB);
    printf("To stop entry of polynomials enter -1 for exponent.....\n");
    
    printf("\n\nPolynomial A......\n");
    while(1){
        printf("\nExponent: ");
        scanf("%d", &A[i].exp);
        if(A[i].exp == -1)
            break;
        printf("Coefficient: ");
        scanf("%d" , &A[i].coeff);
        i ++;
    }

    printf("\n\nPolynomial B......\n");
    while(1){
        printf("\nExponent: ");
        scanf("%d", &B[j].exp);
        if(B[j].exp == -1)
            break;
        printf("Coefficient: ");
        scanf("%d" , &B[j].coeff);
        j ++;
    }

    i = 0, j = 0;
    while(A[i].exp != -1 || B[j].exp != -1){
        if(A[i].exp == B[j].exp){
            D[k].exp = A[i].exp;
            D[k].coeff = A[i].coeff + B[j].coeff;
            ++i;
            ++j;
            ++k;
        }
        else if(A[i].exp > B[j].exp){
            D[k].exp = A[i].exp;
            D[k].coeff = A[i].coeff;
            ++i;
            ++k;
        }
        else if(A[i].exp < B[j].exp){
            D[k].exp = B[j].exp;
            D[k].coeff = B[j].coeff;
            ++j;
            ++k;
        }
    }

    printf("\n\nThe Resultant matrix is......\n");
    for(i = 0; i<k; i++){
        printf("Exponent: %d, Coefficient: %d\n" , D[i].exp , D[i].coeff);
    }

}