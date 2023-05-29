#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int partition(int *arr,int si,int ei)
{
    int pivot=arr[si];
    int i=ei;
    for(int j=ei;j>=si;j--)
    {
        if(arr[j]>pivot)
        {
            swap(arr[i],arr[j]);
            i--;
        }
    }
    swap(arr[i],arr[si]);
    return i;
}
// Recursive Approach
/*void QuickSort(int *arr,int si,int ei)
{
    if(si>=ei)
    {
        return ;
    }
    int pi=partition(arr,si,ei);
    QuickSort(arr,si,pi-1);
    QuickSort(arr,pi+1,ei);
}*/

// Iterative Approach
void QuickSort(int *arr,int si,int ei)
{
    int stack[ei-si+1];
    int top=-1;
    stack[++top]=si;
    stack[++top]=ei;
    while(top>=0)
    {
        ei=stack[top--];
        si=stack[top--];
        int p = partition(arr,si,ei);
        if(p-1>si)
        {
            stack[++top]=si;
            stack[++top]=p-1;
        }
        if(p+1<ei){
            stack[++top]=p+1;
            stack[++top]=ei;
        }
    }

}

int main()
{
    int n, num;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}