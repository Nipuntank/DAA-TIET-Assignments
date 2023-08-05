#include<iostream>
using namespace std;
int subsetSum(int *arr,int n,int k,int i,int count)
{
    if(i==n)
    {
        if(k==0)
        {
            count++;
            return count;
        }
        return count;
    }
    count=subsetSum(arr,n,k-arr[i],i+1,count);
    count=subsetSum(arr,n,k,i+1,count);
    return count;
}
int main()
{
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the value of k:";
    cin>>k;
    cout<<subsetSum(arr,n,k,0,0);
    return 0;
}