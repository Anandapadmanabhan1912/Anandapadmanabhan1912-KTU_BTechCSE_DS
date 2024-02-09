#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

int** createAdjMatrix(int n);
Node* createAdjList(int n);
void printAdjMat(int n, int** mat);
void printAdjList(int n, Node* adj);
void addEdge(int src , int dest, Node* adjl,int** mat);
void clearAdjacencyLists(Node* adjList, int numVertices);
void DFS(int n , int** adjmat);
void push(int* stk, int item, int* top);
int pop(int* stk, int* top);
int checkinlist(int* list , int n , int item);



int main(){
    int n;
    printf("Graphs :: \n");
    printf("\nEnter the number of node: ");
    scanf("%d", &n);
    int** mat = createAdjMatrix(n);
    Node* adj = createAdjList(n);
    
    printf("\n:: Menu :: \n");
    printf("1. Add Edge \n");
    printf("2. Print adjacency matrix\n");
    printf("3. Print Adjacency List\n");
    printf("4. Perform DFS\n");
    printf("5. Perform BFS\n");
    printf("6. Exit\n");

    int ch;
    int src, dest;
    while(ch != 6){
        printf("\nEnter your choice:: ");
        scanf("%d" , &ch);
        switch(ch){
            case 1:
            printf("Enter Source and destination:: ");
            scanf("%d %d", &src, &dest);
            addEdge(src , dest, adj, mat);
            break;

            case 2:
            printAdjMat(n , mat);
            break;

            case 3:
            printAdjList(n , adj);
            break;
             
            case 4:
            DFS(n , mat);
            break;

            default:
            break;
        }
    }
}

void push(int* stk, int item, int* top) {
    stk[++(*top)] = item;
}

int pop(int* stk, int* top) {
    if (*top == -1) {
        printf("Stack underflow\n");
        return -1; // Return a sentinel value or handle underflow in your way
    }
    return stk[(*top)--];
}

int checkinlist(int* list , int n , int item){
    int i = 0;
    for(int i = 0; i< n; i++){
        if(item == list[i]){
            return 0;
        }
    }
    return 1;
}
void DFS(int n , int** adjmat){
    int* stack = (int*)malloc(n*sizeof(int));
    int* listx = (int*)malloc(n*sizeof(int));
    int top = -1;
    int topx = -1;
    int str = 0;
    int i , j;
    printf("Choose a starting node: ");
    scanf("%d", &str);
    push(stack , str, &top);
    while(top != -1){
        str = pop(stack , &top);
        if(checkinlist(listx , n , str)){
            push(listx , str , &topx);
            for(i = 0; i<n; i++){
                if(adjmat[str][i] == 1){
                    push(stack , i , &top);
                }
            }
        }
    }
    printf("Print DFS starting at %d: ", listx[0]);
    for(i = 0 ; i<topx; i++){
        printf("%d ", listx[i]);
    }
    free(listx);
    free(stack);
}

int** createAdjMatrix(int n) {
    int** mat = (int**)calloc(n, sizeof(int*));
    if (mat == NULL) {
        printf("\nMemory Allocation failed to create Adjacency matrix.....");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        mat[i] = (int*)calloc(n, sizeof(int));
        if (mat[i] == NULL) {
            printf("\nMemory Allocation failed to create Adjacency matrix.....");
            
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(mat[j]);
            }
            free(mat);

            return NULL;
        }

        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }

    return mat;
}

Node* createAdjList(int n){
    Node* list = (Node*)calloc(n , sizeof(Node));
    if(list != NULL){
        int i = 0;
        for(i ; i<n; i++){
            list[i].data = i;
            list[i].next = NULL;
        }
        return list;
    }
    else{
        exit(0);
    }
}
void printAdjMat(int n, int** mat){
    int i = 0;
    int j = 0;
    printf("\n");
    for(i ; i<n; i++){
        j=0;
        for(j; j<n; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void printAdjList(int n, Node* adj){
    printf("\n");
    int i = 0;
    Node* ptr;
    for(i; i<n; i++){
        ptr = adj[i].next;
        printf("\n%d: ",adj[i].data);
        while(ptr != NULL){
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("END");
    }
}
void addEdge(int src , int dest, Node* adjl,int** mat){
    if(src == dest){
        return;
    }
    mat[src][dest] = 1;
    Node* ptr = adjl[src].next;
    Node* prev;
     if (ptr == NULL) {
        Node* new = (Node*)malloc(sizeof(Node));
        new->data = dest;
        new->next = NULL;
        adjl[src].next = new;
        return;
    }
    while(ptr != NULL){
        if(ptr->data == dest){
            printf("\nAn edge already exists between%d and %d\n", src, dest);
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = dest;
    new->next = NULL;
    prev->next = new;
    return;
}
void clearAdjacencyLists(Node* adjList, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        Node* current = adjList[i].next;
        Node* next;

        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }

        // Reset the adjacency list to an empty list
        adjList[i].next = NULL;
    }
}