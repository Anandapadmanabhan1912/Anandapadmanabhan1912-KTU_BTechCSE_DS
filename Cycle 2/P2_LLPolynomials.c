/*Name: Anandapadmanabhan.B 
Batch: S3 CS-2, Roll No. 15, 
Date: 16/11/2023,
Polynomials Addition 
and Multiplication using Linked lists*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int coeff;
    int exp;
    struct Node* link;
}Node;

void ReadPoly(Node* P);
void Display(Node* P);
Node* AddPoly(Node* P, Node* Q);
void FreeLL(Node* P);
Node* MultiPoly(Node* P, Node* Q);

int main() {
    Node *p = (Node*)malloc(sizeof(Node));
    Node *q = (Node*)malloc(sizeof(Node));
    Node *r;
    p->coeff = p->exp = q->coeff = q->exp = 0;
    p->link = q->link = NULL;
    printf("\nPolynomial 1: ");
    ReadPoly(p);
    printf("\n\tPolynomial 1: ");
    Display(p);

    printf("\nPolynomial 2: ");
    ReadPoly(q);
    printf("\n\tPolynomial 2: ");
    Display(q);
    r = AddPoly(p , q);
    printf("\nResultant : ");
    Display(r);
    FreeLL(r);
    r = MultiPoly(p , q);
    printf("\nProduct : ");
    Display(r);
    FreeLL(r);
    FreeLL(p);  // Free memory allocated for p
    FreeLL(q);
}

void ReadPoly(Node* P) {
    int exp = 0;
    Node* ptr = P;
    while (exp >= 0) {
        Node* new = (Node*)malloc(sizeof(Node));
        printf("\nEnter the exponent(-1 to exit): ");
        scanf("%d", &(new->exp));
        if (new->exp < 0) {
            free(new);  // Free memory and exit loop if exp is negative
            break;
        }
        printf("Enter Coefficient: ");
        scanf("%d", &(new->coeff));
        new->link = NULL;
        ptr->link = new;
        ptr = new;  // Update ptr to point to the newly created node
    }
}

void Display(Node* P) {
    P = P->link;
    while (P != NULL) {
        printf("(%d)x^%d", P->coeff, P->exp);
        P = P->link;
        if (P != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

Node* MultiPoly(Node* P, Node* Q) {
    Node* r = malloc(sizeof(Node));
    r->coeff = r->exp = 0;
    r->link = NULL;
    int c, e;
    Node* pptr = P->link;
    Node* qptr, *new, *rptr, *rptr1;

    while (pptr != NULL) {
        qptr = Q->link;
        while (qptr != NULL) {
            c = pptr->coeff * qptr->coeff;
            e = pptr->exp + qptr->exp;
            rptr = r->link;

            if (rptr == NULL) {
                new = (Node*)malloc(sizeof(Node));
                new->coeff = c;
                new->exp = e;
                new->link = NULL;
                r->link = new;
                rptr = new;
            } else {
                rptr1 = r;
                while (rptr != NULL) {
                    if (rptr->exp == e) {
                        rptr->coeff += c;
                        break;
                    } else if (e > rptr->exp) {
                        new = (Node*)malloc(sizeof(Node));
                        new->coeff = c;
                        new->exp = e;
                        rptr1->link = new;
                        new->link = rptr;
                        break;
                    }
                    rptr1 = rptr;
                    rptr = rptr->link;
                }
                if (rptr == NULL) {
                    new = (Node*)malloc(sizeof(Node));
                    new->coeff = c;
                    new->exp = e;
                    rptr1->link = new;
                    new->link = NULL;
                }
            }
            qptr = qptr->link;
        }
        pptr = pptr->link;
    }
    return r;
}

Node* AddPoly(Node* P, Node* Q){
    Node* r = (Node*)malloc(sizeof(Node));
    r->coeff = r->exp = 0;
    r->link = NULL;
    Node* rptr = r;
    Node* pptr = P->link;
    Node* qptr = Q->link; 
    while(pptr!= NULL && qptr!= NULL){
        Node *new = (Node*)malloc(sizeof(Node)); 
        new->link = NULL;
        if(pptr->exp == qptr->exp){
            new->exp = pptr->exp;
            new->coeff = pptr->coeff + qptr->coeff;
            rptr->link = new;
            rptr = new;
            qptr = qptr->link;
            pptr = pptr->link;
        }
        else if(pptr->exp>qptr->exp){
            new->exp = pptr->exp;
            new->coeff = pptr->coeff;
            rptr->link = new;
            rptr = new;
            pptr = pptr->link;
        }
        else if(pptr->exp<qptr->exp){
            new->exp = qptr->exp;
            new->coeff = qptr->coeff;
            rptr->link = new;
            rptr = new;
            qptr = qptr->link;
        }
    }
    while(pptr != NULL){
        Node *new = (Node*)malloc(sizeof(Node)); 
        new->link = NULL;
        new->exp = pptr->exp;
        new->coeff = pptr->coeff;
        rptr->link = new;
        rptr = new;
        pptr = pptr->link;
    }
    while(qptr != NULL){
        Node *new = (Node*)malloc(sizeof(Node)); 
        new->link = NULL;
        new->exp = qptr->exp;
        new->coeff = qptr->coeff;
        rptr->link = new;
        rptr = new;
        qptr = qptr->link;       
    }
    return r;
}
void FreeLL(Node* P){
    P = P->link;
    Node* ptr = P;
    while (P != NULL) {
        ptr = P;
        P = P->link;
        free(ptr);
    }
}