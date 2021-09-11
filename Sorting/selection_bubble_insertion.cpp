#include <bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n)
{
    int i,j,mindx,temp;

    for (i=0; i<n-1; i++)
    {
        mindx=i;
        for (j=i+1; j<n; j++)
        {
            if (a[j]<a[mindx])
            {
                mindx=j;
            }
        }
        if (mindx!=i)
        {
            temp=a[i];
            a[i]=a[mindx];
            a[mindx]=temp;
        }
    }
    for (i=0; i<n; i++) cout<<a[i]<<" ";
}
void bubble_sort (int a[], int n)
{
    int i,j,temp;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for (i=0; i<n; i++) cout<<a[i]<<" ";
}
void insertion_sort (int a[], int n)
{
    int i,j,item;
    for (i=1; i<n; i++)
    {
        item=a[i];
        j=i-1;
        while (j>=0 && a[j]>item)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=item;
    }
    for (i=0; i<n; i++) cout<<a[i]<<" ";
}
int main()
{
    int a[100],n,i;
    cin>>n;
    for (i=0; i<n; i++) cin>>a[i];
    cout<<endl;
    selection_sort (a,n);
    cout <<endl;
    bubble_sort (a,n);
    cout<<endl;
    insertion_sort(a,n);
    cout<<endl;
}

