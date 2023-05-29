#include<iostream>
using namespace std;
void Merge(int *arr,int si,int mid,int ei)
{
    int a= si,b=mid,c=mid+1,d=ei,k=0,ans[d-a+1];
    while(a<=b && c<=d)
    {
        if(arr[a]<=arr[c])
        {
            ans[k++]=arr[a++];
        }
        else{
            ans[k++]=arr[c++];
        }
    }
    while(a<=b)
    {
        ans[k++]=arr[a++];
    }
    while(c<=d)
    {
        ans[k++]=arr[c++];
    }
    int j=0;
    for(int i=si;i<=ei;i++)
    {
        arr[i]=ans[j++];
    }
}
void MergeSort(int *arr,int si,int ei)
{
    if(si>=ei)
    {
        return ;
    }
    int mid = (si+ei)/2;
    MergeSort(arr,si,mid);
    MergeSort(arr,mid+1,ei);
    Merge(arr,si,mid,ei);
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
    MergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}