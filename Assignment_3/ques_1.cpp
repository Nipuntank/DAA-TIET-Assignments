#include<iostream>
#include<vector>
using namespace std;
// Time Complexity of this Approach is O(2^n)
int LCS(string s1,string s2,int m,int n)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    if(s1[m-1]==s2[n-1])
    {
        return 1+LCS(s1,s2,m-1,n-1);
    }
    else{
        return max(LCS(s1,s2,m-1,n),LCS(s1,s2,m,n-1));
    }
}
//  Time Complexity using DP approach is O(m*n)
int LCS_dp(string s1,string s2,int m,int n,vector<vector<int> >&dp)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    if(s1[m-1]==s2[n-1])
    {
        dp[m][n] = 1+LCS_dp(s1,s2,m-1,n-1,dp);
    }
    else{
        dp[m][n]=max(LCS_dp(s1,s2,m-1,n,dp),LCS_dp(s1,s2,m,n-1,dp));
    }
    return dp[m][n];
}
//  Time Complexity using Memoization/Tabulation approach is O(m*n)
int LCS_memo(string s1,string s2,int m,int n)
{
    int lc[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                lc[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                lc[i][j]=1+lc[i-1][j-1];
            }
            else{
                lc[i][j]=max(lc[i-1][j],lc[i][j-1]);
            }
        }
    }
    return lc[m][n];
}
int main()
{
    string str1,str2;
    cout<<"Enter the strings"<<endl;
    cout<<" 1 --> ";
    cin>>str1;
    cout<<" 2 --> ";
    cin>>str2;
    int m=str1.length();
    int n=str2.length();
    cout<<"Length of the LCS is :";
    cout<<LCS(str1,str2,m,n)<<endl;
    vector<vector<int> >dp(m+1,vector<int>(n+1,-1));
    cout<<"Length of the LCS is :";
    cout<<LCS_dp(str1,str2,m,n,dp)<<endl;
    cout<<"Length of the LCS is :";
    cout<<LCS_memo(str1,str2,m,n)<<endl;
    return 0;
}