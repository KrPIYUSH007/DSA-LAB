#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char c){
if(top==MAX-1){
    printf("Stack Overflow\n");
    
}
top++;
stack[top]=c;
}

char pop(){
    if (top==-1){
        printf("Stack Underflow\n");

    }
    else{
        char c=stack[top];
        top--;
        return c;
    }
}

char peek(){
    if (top==-1){
        printf("Stack underflow\n");
    }
    return stack[top];
}

int precedence(char op){
    switch(op){
    case'+':
    case'-':
        return 1;
    case'*':
    case'/':
        return 2;
    case'^':
        return 3;
    default:
        return 0;
    }
}

int associativity(char op){
    if (op=='^'){
        return 1;
    }
    else 
        return 0;
}

void infixTopostfix(char infix[], char postfix[]){
    int k=0;
    char c;
    for (int i=0; infix[i]!='\0'; i++){
        c=infix[i];
        if (isalnum(c)){
            postfix[k]=c;
            k++;
        }
        else if (c=='('){
            push(c);
        }
        else if(c==')'){
            while (peek()!='('){
                postfix[k]=pop();
                k++;
            }
            if (peek()=='(')
                pop();
        }
        else{
            while (top!=-1 && ((precedence(peek())>precedence(c)) ||
            (precedence(peek())==precedence(c) && associativity(c)==0)) && peek()!='('){
                postfix[k++]=pop();
            }
            push(c);
        }
    }
    while (top!=-1){
        postfix[k++]=pop();
    }
    postfix[k]='\0';
}

int main(){
    char infix[MAX];
    char postfix[MAX];
    printf("Enter a Valid Parenthesized Infix Expression\n");
    scanf("%s",infix);
    infixTopostfix(infix,postfix);
    printf("Your Postfix Expression is : %s\n", postfix);
}
