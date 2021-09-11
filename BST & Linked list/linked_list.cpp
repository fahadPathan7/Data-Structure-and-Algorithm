#include <bits/stdc++.h>
using namespace std;

struct node *head;

struct node
{
    int data;
    struct node *link;
};
void deletenode (int value)  // to delete any node
{
    struct node *temp;
    if (value==1)
    {
        temp=head;
        head=head->link;
        free(temp);
    }
    else
    {
        temp=head;
        for (int i=1; i<=value-2; i++)
        {
            temp=temp->link;
        }
        struct node *temp1;
        temp1=temp->link;
        temp->link=temp1->link;
        free(temp1);
    }
}
void print ()   // print all the elements
{
    struct node *temp;
    temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<'\t';
        temp=temp->link;
    }
}
void ainput (int value)  // input at the beginning
{
    struct node *temp;
    temp=(struct node*)(malloc(sizeof(struct node)));
    temp->data=value;
    temp->link=head;
    head=temp;
}
void inputa (int value)  // input at the end
{
    struct node *temp;
    temp = (struct node*) (malloc(sizeof(struct node)));
    temp->data = value;
    temp->link = NULL;
    if (head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node *temp1;
        temp1=head;
        while (temp1->link!=NULL)
        {
            temp1=temp1->link;
        }
        temp1->link=temp;
    }

}
void asortedinput (int value)  // input data in ascending order
{
    struct node *temp= (struct node*) malloc(sizeof(struct node));
    temp->data=value;
    if (head==NULL || head->data > temp->data)
    {
        temp->link=head;
        head=temp;
    }
    else
    {
        struct node *pred=head;
        struct node *p=pred->link;
        while (p!=NULL && temp->data > p->data)
        {
            pred=p;
            p=p->link;
        }
        pred->link=temp;
        temp->link=p;
    }
}
void dsortedinput (int value)  // input data in descending order
{
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data=value;
    if (head==NULL || temp->data > head->data)
    {
        temp->link=head;
        head=temp;
    }
    else
    {
        struct node *temp1=head;
        struct node *temp2=temp1->link;
        while (temp2!=NULL && temp2->data > temp->data)
        {
            temp1=temp2;
            temp2=temp2->link;
        }
        temp1->link=temp;
        temp->link=temp2;
    }
}
int main()
{
    int a,b;
    char ch,ch1;
    head = NULL;
    cout<<"If you want to sort your inputs please press 's'. else press 'n' : ";
    cin>>ch;
    if (ch=='s')
    {
        cout<<"For ascending order press 'a'. For descending order press 'd' : ";
        cin>>ch;
        if (ch=='a')
        {
            cout<<"NOTE : Input will be terminated by end of file.(Simply press 'Ctrl+Z')"<<endl;
            cout<<"Now please insert your data..."<<endl;
            while(scanf("%d",&a)!=EOF)
            {
                asortedinput(a);
            }
        }
        else
        {
            cout<<"NOTE : Input will be terminated by end of file.(Simply press 'Ctrl+Z')"<<endl;
            cout<<"Now please insert your data..."<<endl;
            while(scanf("%d",&a)!=EOF)
            {
                dsortedinput(a);
            }
        }
    }
    else
    {
        cout<<"NOTE : Input will be terminated by end of file.(Simply press 'Ctrl+Z')"<<endl;
        cout<<"NOTE : After your data,press 'b' to input your data at the beginning or press 'e' to input your data at the end"<<endl;
        cout<<"Now please insert your data..."<<endl;
        while(scanf("%d%c",&a,&ch)!=EOF)
        {
            if (ch=='b')
            {
                ainput(a);
            }
            else if (ch=='e')
            {
                inputa(a);
            }
            else
            {
                cout<<"Not a valid input. Please read the instructions and try again."<<endl;
            }
        }
    }
    cout<<"Do you want to delete some inputs? press '1' to delete some inputs or press '2' to skip : ";
    cin>>a;
    if (a==1)
    {
        cout<<"how many inputs you want to delete? : ";
        cin>>a;
        for (int i=1; i<=a; i++)
        {
            cout<<"Please input the index : ";
            cin>>b;
            deletenode(b);
        }
    }
    print();

    return 0;
}

