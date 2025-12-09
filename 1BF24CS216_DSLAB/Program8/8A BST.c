#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *left;
struct Node *right;
};
struct Node* createNode( int value){
struct Node* temp=(struct Node*) malloc(sizeof(struct Node));
temp->data=value;
temp->left=NULL;
temp->right=NULL;
return temp;
}
struct Node* insert( struct Node* root,int value){
if (root==NULL){
    root=createNode(value);
}
else if (value<root->data){
    root->left=insert(root->left,value);
}
else {
    root->right=insert(root->right,value);
}
return root;
}
void preorder(struct Node* root){
    if (root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node* root){
    if (root!=NULL){
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
}
void postorder(struct Node* root){
    if (root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
    }
}
void displayinorder(struct Node *root){
inorder(root);
}
void displaypreorder(struct Node *root){
preorder(root);
}
void displaypostorder(struct Node *root){
postorder(root);
}
int main(){
struct Node* root=NULL;
int n,value;
printf("ENTER NUMBER OF NODES: \n");
scanf("%d", &n);
printf("ENTER NODE VALUES: \n");
for (int i=0; i<n;i++){
scanf("%d", &value);
root=insert(root,value);
}
printf("\nPreorder Traversal: ");
displaypreorder(root);
printf("\nPostORder Traversal: ");
displaypostorder(root);
printf("\ninorder traversal: ");
displayinorder(root);
}
