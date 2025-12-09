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
 struct Node* insertEnd( struct Node* head, int value){
     struct Node* newnode=createNode(value);
if (head == NULL) {
        head = newnode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("Inserted %d at the end\n", value);
    return head;
}
 void display(struct Node* head) {
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
void BubbleSort(struct Node* head){
if (head==NULL) return ;
int swapped;
struct Node*curr;
struct Node* last=NULL;
do{
    swapped=0;
    curr=head;
    while(curr->next!=last){
        if (curr->data > curr->next->data){
            int temp=curr->data;
            curr->data=curr->next->data;
            curr->next->data=temp;
            swapped=1;
        }
        curr=curr->next;
    }
    last=curr;
}while(swapped);
}
struct Node* reverse(struct Node* head){
struct Node* prev=NULL;
struct Node* curr=head;
struct Node* next;
while ( curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
return prev;
    }
struct Node* concatenate( struct Node* head1, struct Node* head2){
if (head1==NULL) return head2;
if (head2==NULL) return head1;
struct Node* temp =head1;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=head2;
return head1;
}
void main(){
    struct Node* list1=NULL, *list2=NULL;
int choice,value;
while(1){
    printf("Enter 1 for insert in list1,2 for insert in list2 ,3 for bubblesort,4 for reverse, 5 for concatenate list1 and list 2,6 for print list1,7 for print list2,8 for exit\n");
    scanf("%d", &choice);
    switch(choice){
    case 1:printf("enter the value to be inserted\n");
            scanf("%d",&value);
            list1=insertEnd(list1,value);
            break;
    case 2:printf("enter the value to be inserted\n");
            scanf("%d",&value);
            list2=insertEnd(list2,value);
            break;
    case 3:BubbleSort(list1);
    printf("List Sorted\n");
            break;
    case 4:
         list1=reverse(list1);
         printf("list reverse\n");
            break;
    case 5:
        list1=concatenate(list1,list2);
    printf("Lists concatenated\n");
    break;
    case 6:display(list1);
        break;
    case 7:
       display(list2);
        break;
    case 8:exit(0);
    break;
    default:printf("Enter valid choice\n");
}
}
}
