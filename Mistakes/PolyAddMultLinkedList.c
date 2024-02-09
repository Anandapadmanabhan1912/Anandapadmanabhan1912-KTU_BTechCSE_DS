#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coeff;
    int exp;
    struct Node* next;
}Node;


Node* addPoly(Node* polyA, Node* polyB);
Node* readPoly();

Node* readPoly(){
    int n;
    int i;
    int coeff, exp;
    printf("\nEnter the number of terms: ");
    scanf(" %d", &n);
    printf("Reading the terms of Polynomial: \n");
    Node* poly = NULL;
    Node *ptr , *prev;
    Node* new;
    for(i=0 ; i<n; i++){
        printf("\nEnter the exponent : ");
        scanf(" %d" , &exp);
        printf("Enter the coefficient : ");
        scanf(" %d" , &coeff);
        if(i == 0){
            poly = (Node*)malloc(sizeof(Node));
            poly->exp = exp;
            poly->coeff = coeff;
            poly->next = NULL;
        }
        else{
            ptr = poly;
            prev  = NULL;
            while(ptr!= NULL && ptr->exp > exp){
                prev = ptr;
                ptr = ptr->next;
            }
            if(ptr == NULL){
                new = (Node*)malloc(sizeof(Node));
                new->coeff = coeff;
                new->exp = exp;
                new->next = ptr;
                prev->next = new;//went wrong here
                //remember to link prev to new
            }
            else if(ptr->exp == exp){
                ptr->coeff += coeff;
            }
            else if(ptr->exp < exp){
                new = (Node*)malloc(sizeof(Node));
                new->coeff = coeff;
                new->exp = exp;
                new->next = ptr;
                if(prev == NULL){
                    poly = new;//went wrong here
                    //remember append at head if the coefficiebnt is biggr then fisrst exponent
                }
                else{
                prev->next = new;}
            }
            else{
                printf("Not expected...");
                break;
            }
        }
    }
    return poly;
}

void printPoly(Node* poly){
    printf("\nPolynomial: ");
    while(poly != NULL){
        printf("(%d)x^%d" , poly->coeff , poly->exp);
        if(poly->next != NULL){
            printf(" + ");
        }
        poly = poly->next;
    }
}
void freeAll(Node* poly){
    freeAll(poly -> next);
    free(poly);
}
Node* addPoly(Node* polyA, Node* polyB){
    Node* res = NULL;
    Node* resptr = NULL;
    Node* new; 
    while(polyA != NULL && polyB != NULL){
        if(polyA->exp == polyB->exp){
            if(res == NULL){
                res = (Node*)malloc(sizeof(Node));
                res->coeff = polyA->coeff + polyB->coeff;
                res->exp = polyA->exp;
                res->next = NULL; 
                resptr = res;
            }
            else{
                new = (Node*)malloc(sizeof(Node));
                new->coeff = polyA->coeff + polyB->coeff;
                new->exp = polyA->exp;
                resptr-> next = new;
                resptr = new;
            }
            polyA = polyA->next;
            polyB = polyB->next;
        }
        else if(polyA->exp > polyB->exp){
            if(res == NULL){
                res = (Node*)malloc(sizeof(Node));
                res->coeff = polyA->coeff;
                res->exp = polyA->exp;
                res->next = NULL;
                resptr = res;
            }
            else{
                new = (Node*)malloc(sizeof(Node));
                new->coeff = polyA->coeff;
                new->exp = polyA->exp;
                new->next = NULL;
                resptr-> next = new;
                resptr = new;
            }
            polyA = polyA->next;
        }
        else{
            if(res == NULL){
                res = (Node*)malloc(sizeof(Node));
                res->coeff = polyB->coeff;
                res->exp = polyB->exp;
                res->next = NULL;
                resptr = res;
            }
            else{
                new = (Node*)malloc(sizeof(Node));
                new->coeff = polyB->coeff;
                new->exp = polyB->exp;
                new->next = NULL;
                resptr-> next = new;
                resptr = new;
            }
            polyB = polyB->next;
        }
    }
    while(polyA != NULL){
        new = (Node*)malloc(sizeof(Node));
        new->coeff = polyA->coeff;
        new->exp = polyA->exp;
        new->next = NULL;
        resptr->next = new;
        resptr = new;
        polyA = polyA->next;
    }
    while(polyB != NULL){
        new = (Node*)malloc(sizeof(Node));
        new->coeff = polyB->coeff;
        new->exp = polyB->exp;
        new->next = NULL;
        resptr->next = new;
        resptr = new;
        polyB = polyB->next;
    }
    
    return res;
}

Node* multPoly(Node* polyA, Node* polyB){
    if(polyA == NULL || polyB==NULL){
        printf("\nPolynomials are invalid....\n");
        return NULL;
    }
    int coeff , exp;
    Node* new;
    Node* res = NULL;
    Node* ptrC = NULL;
    Node* ptrB = polyB;
    Node* ptrA = polyA;
    Node* prevC = NULL;

    while(ptrA != NULL){
        ptrB = polyB;
        while(ptrB != NULL){
            coeff = (ptrA->coeff) * (ptrB->coeff);
            exp = (ptrA->exp)+(ptrB->exp);
            ptrC = res;
            prevC = NULL;
            if(res == NULL){
                    res = (Node*)malloc(sizeof(Node));
                    res->exp = exp;
                    res->coeff = coeff;
                    res->next = NULL;
                    ptrB = ptrB->next;
                    continue;      
                }
            while(ptrC != NULL && ptrC->exp > exp){
                prevC = ptrC;
                ptrC = ptrC->next;
            }
            if(ptrC == NULL){
                new = (Node*)malloc(sizeof(Node));
                new->coeff = coeff;
                new->exp = exp;
                new->next = NULL;
                prevC->next = new;
            }
            else if(ptrC->exp == exp){
                ptrC->coeff += coeff;
            }
            ptrB = ptrB->next;
        } 
        ptrA = ptrA->next;
    }
    return res;
}

int main(){
    Node* polyA = readPoly();
    Node* polyB = readPoly();

    printPoly(polyA);
    printPoly(polyB);
    printf("\nPolyA + PolyB\n");
    Node* res = addPoly(polyA , polyB);
    printPoly(res);
    Node* resa = multPoly(polyA , polyB);
    printPoly(resa);
    freeAll(polyA);
    freeAll(polyB);
    freeAll(res);
    freeAll(resa);

    return 0;
}