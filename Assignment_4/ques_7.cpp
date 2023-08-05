#include<iostream>
using namespace std;
bool isPartition(int *arr,int *subsetSum,bool *visited,int subset,int k,int n,int curIdx,int lastIdx)
{
    if(subsetSum[curIdx]==subset)
    {
        if(curIdx==k-2)
        {
            return true;
        }
        return isPartition(arr,subsetSum,visited,subset,k,n,curIdx+1,n-1);
    }
    for(int i=lastIdx;i>=0;i--)
    {
        if(visited[i])
        {
            continue;
        }
        int temp=subsetSum[curIdx]+arr[i];
        if(temp<=subset)
        {
            visited[i]=true;
            subsetSum[curIdx]+=arr[i];
            bool nxt=isPartition(arr,subsetSum,visited,subset,k,n,curIdx,i-1);
            if(nxt)
            {
                return true;
            }
            visited[i]=false;
            subsetSum[curIdx]-=arr[i];
        }
    }
    return false;
}
bool isPartitionPossible(int *arr,int n,int k)
{
    if(k==1)
    {
        return true;
    }
    if(n<k)
    {
        return false;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum%k!=0)
    {
        return false;
    }
    int subset=sum/k;
    int subsetSum[k];
    bool visited[n];
    for(int i=0;i<k;i++)
    {
        subsetSum[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    subsetSum[0]=arr[n-1];
    visited[n-1]=true;
    return isPartition(arr,subsetSum,visited,subset,k,n,0,n-1);
}
int main()
{
    int arr[]={2,1,4,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;
    if(isPartitionPossible(arr,n,k))
    {
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}