#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
/*Name: Anandapadmanabhan.B 
Batch: S3 CS-2, Roll No. 15,
Infix-Postfix Conversion and Postfix Evaluation*/

#define MAX 10
char stack[10];
int stack_int[10];

int top = -1;
int top_int = -1;

int priority(char x);
void pop_char();
void push_int(int x);
int pop_int();
void push_char(char x);
void infix_to_postfix(char str[]);
int postfix_evaluation(char str[]);

int main(){
    char str[20];
    int ch = 0;
    printf("MENU\n");
    printf("1. Infix to Postfix\n");
    printf("2. Postfix Evaluation\n");
    printf("3. Exit");
    while(ch != 3){
        printf("\nEnter Choice : ");
        scanf("%d" , &ch);
        if(ch == 1){
            getchar();
            printf("Enter the Infix expression: ");
            scanf("%[^\n]", str);
            printf("Postfix expression: ");
            infix_to_postfix(str);
        }
        else if(ch == 2){
            getchar();
            printf("Enter the Postfix expression: ");
            scanf("%[^\n]", str);
            printf("Evaluated value: ");
            postfix_evaluation(str);
        }
    }
}

int priority(char x){
    switch (x)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

void pop_char(){
    if(top != -1){
        if(stack[top] != '('){
        printf("%c",stack[top]);}
        top = top -1;
    }
    else{
        printf("UNDERFLOW error...");
    }
}
void push_char(char x){
    if(top != MAX-1){
        top = top + 1;
        stack[top] = x;
    }
}
void push_int(int x){
    if(top_int != MAX-1){
        top_int = top_int + 1;
        stack_int[top_int] = x;
    }
}
int pop_int(){
    if(top_int != -1){
        int a = stack_int[top_int];
        top_int = top_int -1;
        return a;
    }
    else{
        printf("UNDERFLOW error...");
    }
}

void infix_to_postfix(char str[]) {
    int l = strlen(str);
    int i = 0;
    int x;
    for (i = 0; i < l; i++) {
        if (str[i] == '(') {
            push_char('(');
            continue;
        } else if (str[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                pop_char();
            }
            if (top != -1) {
                pop_char(); // Pop '(' from the stack
            }
            continue;
        }
        x = priority(str[i]);
        if (x == -1) {
            printf("%c", str[i]);
        } else {
            while (top != -1 && priority(stack[top]) >= x) {
                pop_char();
            }
            push_char(str[i]);
        }
    }
    while (top != -1) {
        pop_char();
    }
}

int postfix_evaluation(char str[]){
    int l = strlen(str);
    char ch;
    int i;
    for(i = 0; i<l; i++){
        if(isdigit(str[i])){
            push_int(str[i]-'0');
        }
        else if(priority(str[i])>0){
            int a = pop_int();
            int b = pop_int();
            switch (str[i])
            {
            case '+':
                push_int(a+b);
                break;
            case '-':
                push_int(b-a);
                break;
            case '*':
                push_int(a*b);
                break;
            case '/':
                push_int(b/a);
                break;
            case '^':
                push_int(pow(a,b));
                break;
            default:
                break;
            }
        }
    }
    printf("%d" , pop_int());
    return 1;
}