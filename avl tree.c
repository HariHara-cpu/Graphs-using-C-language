#include<stdio.h>
#include<stdlib.h>
struct avlnode
{
    int data;
    struct avlnode* left;
    struct avlnode* right;
    int height;
};
int height(struct avlnode * node)
{
    if(node==NULL)
    return 0;
    return node->height;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
struct avlnode* create(int value)
{
    struct avlnode* newnode=NULL;
    newnode=(struct avlnode*)malloc(sizeof(struct avlnode));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;
    return newnode;
}
struct avlnode* rightrotate(struct avlnode* y)
{
    struct avlnode* x=y->left;
    struct avlnode* t2=x->right;
    x->right=y;
    y->left=t2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->right),height(x->left))+1;
    return x;
}
struct avlnode* leftrotate(struct avlnode* x)
{
    struct avlnode* y=x->right;
    struct avlnode* t2=y->left;
    y->left=x;
    x->right=t2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->right),height(x->left))+1;
    return y;
}
int getbalance(struct avlnode* node)
{
    if(node==NULL)
    return 0;
    return height(node->left)-height(node->right);
}
struct avlnode* insert(struct avlnode* node,int value)
{
    if(node==NULL)
    return create(value);
    else if(value<node->data)
    node->left=insert(node->left,value);
    else if(value>node->data)
    node->right=insert(node->right,value);
    else
    return node;
    node->height=1+max(height(node->left),height(node->right));
    int balance=getbalance(node);
    if(balance>1&&value<node->left->data)
    return rightrotate(node);
    if(balance<-1&&value>(node->right->data))
    return leftrotate(node);
    if(balance>1&&value>node->left->data)
    {
        node->left=leftrotate(node->left);
        return rightrotate(node);
    }
    if(balance<-1&&value<node->right->data)
    {
        node->right=rightrotate(node->right);
        return leftrotate(node);
    }
}
void inorder(struct avlnode* root)
{
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
int main()
{
    int num;
    struct avlnode* root=NULL;
    printf("enter:");
    scanf("%d",&num);
    while(num!=-1)
    {
        root=insert(root,num);
        printf("enter:");
        scanf("%d",&num);
    }
    inorder(root);
    return 0;
}