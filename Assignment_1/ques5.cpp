#include<iostream>
using namespace std;
bool BinarySearch(int *arr,int n ,int num)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==num)
        {
            return true;
        }
        else if(arr[mid]>num)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int num;
    cin>>num;
    if(BinarySearch(arr,n,num))
    {
        cout<<"Yes";
    }
    else{
        cout<<"NO";
    }
    
    return 0;
}