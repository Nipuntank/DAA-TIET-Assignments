#include<iostream>
using namespace std;
//  Time complexity of this approach is O(2^n)
int knapsack(int wt[],int p[],int w,int n)
{
    if(n==0 || w==0)
    {
        return 0;
    }
    if(wt[n-1]>w)
    {
        return knapsack(wt,p,w,n-1);
    }
    else{
        int q =p[n-1]+knapsack(wt,p,w-wt[n-1],n-1);
        int r = knapsack(wt,p,w,n-1);
        return max(q,r);
    }

}
//  Time complexity of this approach is O(n*w)
int knapsack_dp(int wt[],int p[],int w,int n,int **dp)
{
    if(w==0 ||n==0)
    {
        return 0;
    }
    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }
    if(wt[n]>w)
    {
        dp[n][w]=knapsack_dp(wt,p,w,n-1,dp);
        
    }
    else{
        dp[n][w]=max(p[n]+knapsack_dp(wt,p,w-wt[n],n-1,dp),knapsack_dp(wt,p,w,n-1,dp));
    }
    return dp[n][w];
}
int knapsack_dp(int wt[],int p[],int w,int n)
{
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[w+1];
        for(int j=0;j<=w;j++)
        {
            dp[i][j]=-1;
        }
    }
    return knapsack_dp(wt,p,w,n,dp);
}
int knapsack_memo(int wt[],int p[],int w,int n)
{
    int k[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            {
                k[i][j]=0;
            }
            else if(wt[i]<=w)
            {
                k[i][j]=max(k[i-1][j],p[i]+k[i-1][w-wt[i]]);
            }
            else{
                
                k[i][j]=k[i-1][j];
            }
        }
    }
    return k[n][w];
}
int main()
{
    int n,w;
    cin>>n;
    int wt[n],p[n];
    cout<<"Enter the weight"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    cout<<"Enter the profit"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<"Enter the maximum capacity of the knapsack:";
    cin>>w;
    cout<<knapsack(wt,p,w,n)<<endl;
   
    cout<<knapsack_dp(wt,p,w,n)<<endl;
    cout<<knapsack_memo(wt,p,w,n)<<endl;
    return 0;
}