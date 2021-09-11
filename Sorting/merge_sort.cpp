// time complexity: O(nlogn)
#include <bits/stdc++.h>
using namespace std;

int n;
void merge (int a[] ,int left ,int mid , int right)
{
    int i=left,j=mid+1,k=left;
    int temp[n];
    while(i<=mid && j<=right)
    {
        if (a[i]<=a[j])
        {
            temp[k]=a[i];
            i++,k++;
        }
        else
        {
            temp[k]=a[j];
            k++,j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        k++,i++;
    }
    while(j<=right)
    {
        temp[k]=a[j];
        k++,j++;
    }
    for (int l=left; l<=right; l++)
    {
        a[l]=temp[l];
    }
}
void merge_sort(int a[], int left, int right)
{

    if (left<right)
    {
        int mid=(right+left)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
int main()
{
    int i,j;

    cin>>n;
    int a[n];

    for (i=0; i<n; i++)
    {
        cin>>a[i];
    }
    merge_sort(a,0,n-1);
    for (i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}
