#include<stdio.h>
#define N 5
  int stack[N];
    int top=-1;
void push(int value){
    if(top==N-1)
    {
        printf("Stack Overflow");
    }
    top=top+1;
    stack[top]=value;
    }
void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
    }
    else{
    printf("Your popped element is : \n");
    printf("%d \n",stack[top--]);
}
}
void peek(){
    if(top==-1){
        printf("Stack Empty\n");
    }
else{
    printf("%d",stack[top]);
}
    }
void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else
    {
        printf("The elements of the Stack are: \n");
        for(int i=top;i>=0;i--){
        printf("%d \n",stack[i]);
        }

    }
    }
void main(){
   int choice=0;
   int value;
   while(choice!=5){
        printf(" Press 1 for push, 2 for pop, 3 for peek, 4 for display, 5 to exit \n" );
   scanf("%d",&choice);
   switch(choice){
    case 1:
    printf("Enter the value to be inserted: \n");
    scanf("%d",&value);
    push(value);
    break;
    case 2:
    pop();
    break;
    case 3:
    peek();
    break;
    case 4:
    display();
    break;
    case 5:
     break;
    default:
    printf("Enter the valid option");
   }
   }
}

