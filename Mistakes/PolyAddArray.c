#include <stdio.h>
#include <stdlib.h>

typedef struct Term{
    int coeff;
    int exp;
}Term;

Term* readPoly(int n);
void printPoly(int n , Term* arr);

int main(){
    int n1, n2, n3;
    int i , j, k;
    printf("\nPolynomial Addition: \n");
    printf("Enter no of terms in polyA: ");
    scanf(" %d", &n1);
    printf("Enter no of terms in polyB: ");
    scanf(" %d", &n2);
    printf("\nFor Poly A....");
    Term* polyA = readPoly(n1);
    printPoly(n1 , polyA);
    printf("\nFor Poly B....");
    Term* polyB = readPoly(n2);
    printPoly(n2 , polyB);
    i = 0;
    j = 0;
    k = 0;
    Term* res = (Term*)malloc((n1+n2)*sizeof(Term));
    while(i<n1 && j<n2){
        if(polyA[i].exp == polyB[j].exp){
            res[k].exp = polyA[i].exp;
            res[k].coeff = polyA[i].coeff + polyB[j].coeff;
            i++;
            j++;
            k++;
        }
        else if(polyA[i].exp > polyB[j].exp){
            res[k].coeff = polyA[i].coeff;
            res[k].exp = polyA[i].exp;
            i++;
            k++;
        }
        else{
            res[k].coeff = polyB[j].coeff;
            res[k].exp = polyB[j].exp;
            j++;
            k++;
        }
    }
    while(i<n1){
        res[k].coeff = polyA[i].coeff;
        res[k].exp = polyA[i].exp;
        i++;
        k++;
    }
    while(j<n2){
        res[k].coeff = polyB[j].coeff;
        res[k].exp = polyB[j].exp;
        j++;
        k++;
    }
    n3 = k;
    printf("\nPolyA: ");
    printPoly(n1 , polyA);
    printf("\nPolyB: ");
    printPoly(n2 , polyB);
    printf("\nPolyA + PolyB: ");
    printPoly(n3 , res);
    free(polyA);
    free(polyB);
    free(res);
    return 0;
}

Term* readPoly(int n) {
    int exp, coeff;
    int i;
    Term* poly = (Term*)malloc(n * sizeof(Term));
    printf("\nEnter the terms in descending order of exponents:\n");
    for (i = 0; i < n; i++) {
        printf("Enter exponent: ");
        scanf("%d", &exp);
        printf("Enter coefficient: ");
        scanf("%d", &coeff);
        poly[i].exp = exp;
        poly[i].coeff = coeff;
    }
    return poly;
}

void printPoly(int n , Term* arr){
    printf("\nPolynomial: ");
    int i = 0;
    for(i = 0; i<n; i++){
        printf("(%d)x^%d " , arr[i].coeff , arr[i].exp);
        if(i != n-1){
            printf("+ ");
        }
    }
}