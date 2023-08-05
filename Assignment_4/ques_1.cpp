#include<iostream>
using namespace std;
int board[100][100];
void printSol(int n)
{
    cout<<"Solution"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==1)
            {
                cout<<"Q"<<" ";
            }
            else{
                cout<<"."<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
bool isPossible(int n,int row,int col)
{
    for(int i=row;i>=0;i--)
    {
        if(board[i][col]==1)
        {
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    return true;
}
void NQueenHelper(int n,int row)
{
    if(row==n)
    {
        printSol(n);
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(isPossible(n,row,j))
        {
            board[row][j]=1;
            NQueenHelper(n,row+1);
            board[row][j]=0;
        }
    }
}
void NQueen(int n)
{
    memset(board,0,sizeof board);
    NQueenHelper(n,0);
}
int main()
{
    int n;
    cin>>n;
    NQueen(n);
    return 0;
}