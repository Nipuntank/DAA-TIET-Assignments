#include<iostream>
using namespace std;
// Brute Force approach with Time Complexity of O(n^2)
/*int maxSubArray(int *arr,int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=1;j<n;j++)
        {
            if(i+j>n)
            {
                break;
            }
            sum +=arr[i+j];
            if(sum>max)
            {
                max = sum;
            }
        }
    }
    return max;
}*/
// Divide and Conquer Approach With Time Complexity of O(nlogn)
int maxCross(int *arr,int si,int mid,int ei)
{
    int leftSum=INT_MIN;
    int sum=0;
    for(int i=mid;i>=si;i--)
    {
        sum = sum+arr[i];
        if(sum>leftSum)
        {
            leftSum=sum;
        }
    }
    int rightSum=INT_MIN;
    sum=0;
    for(int i=mid+1;i<=ei;i++)
    {
        sum = sum+arr[i];
        if(sum>rightSum)
        {
            rightSum=sum;
        }
    }
    return (leftSum+rightSum);
}
int maxSubArray(int *arr,int si,int ei)
{
    if(si==ei)
    {
        return arr[si];
    }
    int mid = (si+ei)/2;
    int leftSum= maxSubArray(arr,si,mid);
    int rightSum=maxSubArray(arr,mid+1,ei);
    int crossSum = maxCross(arr,si,mid,ei);
    return max(leftSum,max(rightSum,crossSum));
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // int ans = maxSubArray(arr,n);
    int ans = maxSubArray(arr,0,n-1);
    cout<<ans;
    return 0;
}