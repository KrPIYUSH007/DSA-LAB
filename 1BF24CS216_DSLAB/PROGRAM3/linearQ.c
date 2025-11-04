#include<stdio.h>
#define N 5
int queue [N];
int front =-1;
int rear= -1;
void enque(int x){
    if (rear==N-1){
        printf("Queue is Full\n");
    }
    else {
             if ( front==-1){
        front=0;
    }
        rear++;
        queue[rear]=x;
    }
}
void deque(){
    if (front==-1 && rear==-1){
        printf("Queue is Empty\n");
    }
    else if(front==rear){
        printf("the element removed is: %d\n",queue[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("the element removed is: %d\n", queue[front]);
        front++;
    }
}
void display(){
    if (front==-1 && rear==-1){
        printf("Queue is Empty\n");
    }
    else {
        for (int i=0;i<=rear;i++){
            printf("the elements of the queue is: %d\n",queue[i]);
        }
    }
}
 int main(){
    int x;
    int choice;
    while(1){
        printf("Enter your operation: 1 for insert, 2 for delete , 3 for display, 4 for exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element to be inserted\n");
                    scanf("%d",&x);
                    enque(x);
                    break;
            case 2: deque();
                    break;
            case 3: display();
                    break;
            case 4:exit(0);
                    break;
            default:
            printf("Enter valid operation\n");
        }
    }
 }
