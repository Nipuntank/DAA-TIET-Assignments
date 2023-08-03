#include<iostream>
#include<cstring>
using namespace std;
int dp[100][100];
//  Time complexity of this approach is exponential
int MatrixMulti(int *p,int i,int j)
{
    if(i==j)
    {
        return 0;
    }
    int k,temp;
    int ans=INT_MAX;
    for(k=i;k<=j-1;k++)
    {
        temp = MatrixMulti(p,i,k)+MatrixMulti(p,k+1,j)+p[i-1]*p[k]*p[j];
        ans = min(ans,temp);
    }
    return ans;
}
//  Time complexity of this approach is O(n^3)
int MatrixMulti_dp(int *p,int i,int j)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int k,temp;
    dp[i][j]=INT_MAX;
    for(k=i;k<=j-1;k++)
    {
        dp[i][j] = min(dp[i][j],MatrixMulti(p,i,k)+MatrixMulti(p,k+1,j)+p[i-1]*p[k]*p[j]);
    }
    return dp[i][j];
}
//  Time complexity of this approach is O(n^3)
int MatrixMulti_memo(int *p,int n)
{
    int matrix[n][n];
    for(int i=0;i<n;i++)
    {
        matrix[i][i]=0;
    }
    int j,ans;
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            matrix[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    return matrix[1][n-1];
}
int main()
{
    int n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<MatrixMulti(p,1,n-1)<<endl;
    memset(dp,-1,100*100*sizeof(int));
    cout<<MatrixMulti_dp(p,1,n-1)<<endl;
    cout<<MatrixMulti_memo(p,n)<<endl;
    return 0;
}