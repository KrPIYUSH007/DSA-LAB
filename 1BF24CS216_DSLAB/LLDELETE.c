#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void InsertAtFirst(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("Inserted %d at front\n", value);
}
void InsertAtEnd(int value) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("Inserted %d at the end\n", value);
}
void InsertAtAnyPosition(int value, int index) {
    if (index < 0) {
        printf("Invalid index!\n");
        return;
    }
    if (index == 0) {
        InsertAtFirst(value);
        return;
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    struct Node *temp = head;
    int i = 0;
    while (i < index - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Index out of range!\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Inserted %d at position %d.\n", value, index);
}
void DeleteFirst(){
if (head==NULL){
    printf("Linked List is Empty\n");
}
struct Node* temp=head;
head=head->next;
free(temp);
}
void DeleteLast(){
if (head==NULL){
    printf("Linked List is Empty\n");
}
struct Node* temp=head;
while(temp->next->next!=NULL){
    temp=temp->next;
}
struct Node *Lastnode=temp->next;
temp->next=NULL;
free(Lastnode);
}
void DeleteAtPosition(int pos){
if (head==NULL){
    printf("Linked List is Empty");
}
else if (pos==1){
    DeleteFirst();
}
else {
    struct Node *temp=head;
    int i=1;
    while(i< pos-1 && temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    struct Node* nodetodelete=temp->next;
    temp->next=nodetodelete->next;
    free(nodetodelete);
    }
}
void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

void main(){
int choice,value,index,position;
while(1){
    printf("Enter 1 for insertatfront,2 for insertatend,3 for insertanywhere,4 for display, 5 for deleteatfront,6 for deleteatlast,7 for deleteanywhere,8 for exit\n");
    scanf("%d", &choice);
    switch(choice){
    case 1:printf("enter the value to be inserted\n");
            scanf("%d",&value);
            InsertAtFirst(value);
            break;
    case 2:printf("enter the value to be inserted\n");
            scanf("%d",&value);
            InsertAtEnd(value);
            break;
    case 3:printf("enter the value to be inserted\n");
            scanf("%d",&value);
            printf("enter the index at to be inserted\n");
            scanf("%d",&index);
            InsertAtAnyPosition(value,index);
            break;
    case 4:display();
            break;
    case 5:DeleteFirst();
    printf("Deletion Successfull\n");
    break;
    case 6:DeleteLast();
        printf("Deletion Successfull\n");
        break;
    case 7:
        printf("Enter the POSITION to delete\n");
        scanf("%d",&position);
        DeleteAtPosition(position);
        printf("Deletion Successfull\n");
        break;
    default:printf("Enter valid choice\n");
}
}
}
