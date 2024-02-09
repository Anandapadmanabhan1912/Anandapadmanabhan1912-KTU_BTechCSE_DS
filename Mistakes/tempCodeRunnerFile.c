void DFS(int n , int** adjmat){
    int* stack = (int*)malloc(n*sizeof(int));
    int* listx = (int*)malloc(n*sizeof(int));
    int top = -1;
    int topx = -1;
    int str;
    int i , j;
    printf("Choose a starting node: ");
    scanf(" %d", &str);
    push(stack , str, &top);
    while(top != -1){
        str = pop(stack , &top);
        if(!checkinlist(listx , n , str)){
            push(listx , str , &topx);
            for(i = 0; i<n; i++){
                if(adjmat[str][i] == 1){
                    push(stack , i , &top);
                }
            }
        }
    }
    printf("Print DFS staring at %d: ", listx[0]);
    for(i = 0 ; i<topx; i++){
        printf("%d ", listx[i]);
    }
    free(listx);
    free(stack);
}