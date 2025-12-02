#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *prev;
struct Node *next;
};
struct Node *head=NULL;
struct Node *createNode(int value){
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=value;
newNode->prev=NULL;
newNode->next=NULL;
return newNode;
}
void insertLeft(int value){
struct Node *newNode = createNode(value);
if (head==NULL) {
    head=newNode;
    }else{
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
}
void insertRight(int value){
struct Node *newNode=createNode(value);
if (head==NULL){
head=newNode;
return;
}
struct Node *temp=head;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=newNode;
newNode->prev=temp;
}
void deletebyValue(int value){
if (head==NULL){
    printf("Empty List\n");
    return;
}
struct Node*temp=head;
while(temp!=NULL && temp->data!=value){
    temp=temp->next;
}
if (temp==NULL){
    printf("ValueNotFOund\n");
    return;
}
if (temp==head){
    head=head->next;
    if (head!=NULL)
        head->prev=NULL;
}
else if (temp->next==NULL){
    temp->prev->next=NULL;
}
else{
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
}
free(temp);
printf("Deleted %d\n",value);
}
void deletebyPos(int pos){
if (head==NULL || pos<=0){
    printf("Invalid Position\n");
    return;
}
struct Node*temp=head;
int i=1;
while(temp!=NULL && i<pos){
    temp=temp->next;
    i++;
}
if (temp==NULL){
    printf("Position out of range\n");
    return;
}
if (temp==head){
    head=head->next;
    if (head!=NULL)
        head->prev=NULL;
}
else if (temp->next==NULL){
    temp->prev->next=NULL;
}
else{
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
}
free(temp);
printf("Node at %d deleted\n",pos);
}
 void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nDoubly Linked List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}
void main(){
int choice,value,pos;
while(1){
    printf("Enter 1 for insertatleft, 2 for insertatright, 3 for deletebyvalue,4 for deletebypos,5 for display, 6 to exit \n");
    scanf("%d", &choice);
    switch(choice){
    case 1:printf("enter the value to insert\n");
            scanf("%d",&value);
            insertLeft(value);
            break;
    case 2:printf("enter the value to insert \n");
            scanf("%d",&value);
            insertRight(value);
            break;
    case 3:printf("enter the value to delete\n");
            scanf("%d",&value);
            deletebyValue(value);
            break;
    case 4:
         printf("enter the position to delete\n");
            scanf("%d",&pos);
            deletebyPos(pos);
            break;
    case 5:display();
        break;
    case 6:exit(0);
    break;
    default:printf("Enter valid choice\n");
}
}
}


