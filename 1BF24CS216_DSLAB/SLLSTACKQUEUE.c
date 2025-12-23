#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};
 struct Node* createNode(int value){
 struct Node* n=( struct Node*)malloc(sizeof(struct Node));
 n->data=value;
 n->next=NULL;
 return n;
 }
 struct Node* push(struct Node* top, int value){
 struct Node* n=createNode(value);
 n->next=top;
 return n;
 }
 struct Node* pop(struct Node* top){
 if (top==NULL){
    printf("Stack Empty\n");
    return NULL;
 }
 struct Node* temp=top;
 printf("Popped:%d\n", temp->data);
 top=top->next;
 free(temp);
 return top;
 }
 void peek(struct Node* top){
 if (top==NULL){
    printf("stack emnpty\n");
 }
 else{
    printf("top is %d\n", top->data);
 }
 }
 void enqueue( struct Node** front , struct Node** rear, int value){
 struct Node*n = createNode(value);
 if (*rear==NULL){
    *front=*rear=n;
    return;
 }
(*rear)->next=n;
*rear=n;
 }
 void dequeue( struct Node** front, struct Node** rear){
 if( *front==NULL){
    printf("Stack empty\n");
    return;
 }
 struct Node* temp= *front;
 printf("dequeued: %d\n", temp->data);
 *front=(*front)->next;
 if (*front==NULL){
    *rear=NULL;
 }
 free(temp);
 }
 void frontvalue( struct Node* front){
 if (front==NULL){
    printf("StackEmpty\n");
 }else{
 printf(" front: %d\n",front->data);
 }
 }
 int main(){
    struct Node* stacktop=NULL;
    struct Node* qfront=NULL, *qrear=NULL;
int choice,value;
while(1){
    printf("Enter 1 for push satck ,2 for pop stack ,3 for peek stack,4 for enqueue queue, 5 for dequeue queue 2,6 for front peek queue,7 for exit\n");
    scanf("%d", &choice);
    switch(choice){
    case 1:printf("enter the value to be inserted\n");
            scanf("%d",&value);
            stacktop=push(stacktop,value);
            break;
    case 2:stacktop=pop(stacktop);
            break;
    case 3:peek(stacktop);
            break;
    case 4:
         printf("ENter value\n");
         scanf("%d", &value);
         enqueue(&qfront,&qrear,value);
            break;
    case 5:dequeue(&qfront,&qrear);
            break;
    case 6:
       frontvalue(qfront);
    break;
    case 7: exit(0);
    break;
    default:printf("Enter valid choice\n");
}
}
return 0;
}
