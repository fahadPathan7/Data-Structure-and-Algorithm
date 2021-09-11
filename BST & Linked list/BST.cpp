#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;

void insert (int value)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;

    if (root==NULL)
    {
        root=newnode;
    }
    else
    {
        struct node *temp=root;
        while(1)
        {
            if (newnode->data <= temp->data)
            {
                if (temp->left==NULL)
                {
                    temp->left=newnode;
                    break;
                }
                else
                {
                    temp=temp->left;
                }
            }
            else
            {
                if (temp->right==NULL)
                {
                    temp->right=newnode;
                    break;
                }
                else
                {
                    temp=temp->right;
                }
            }
        }
    }
}
void preorder (struct node *r)
{
    if (r==NULL) return;
    cout<<r->data<<' ';
    preorder(r->left);
    preorder(r->right);
}
int main()
{
    root=NULL;
    insert(55);
    insert(40);
    insert(80);
    insert(34);
    insert(28);
    insert(38);
    insert(60);
    insert(90);

    preorder(root);
}
