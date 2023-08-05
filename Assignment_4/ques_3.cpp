#include<iostream>
#define V 4
using namespace std;
void printSolution(int color[V])
{
    for(int i=0;i<V;i++)
    {
        cout<<color[i]<<" ";
    }
    cout<<endl;
}
// time complexity of the navie approach is O(m^v)
bool isSafe(bool matrix[V][V],int color[V])
{
    for(int i=0;i<V;i++)
    {
        for(int j=i+1;j<V;j++)
        {
            if(matrix[i][j] && color[j]==color[i])
            {
                return false;
            }
        }
    }
    return true;
}
bool graphColoring(bool matrix[V][V],int m,int i,int color[V])
{
    if(i==V)
    {
        if(isSafe(matrix,color))
        {
            printSolution(color);
            return true;
        }
        return false;
    }
    for(int j=1;j<=m;j++)
    {
        color[i]=j;
        if(graphColoring(matrix,m,i+1,color))
        {
            return true;
        }
        color[i]=0;
    }
    return false;
}
int main()
{
    bool matrix[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m=3;
    int color[V];
    for(int i=0;i<m;i++)
    {
        color[i]=0;
    }
    if(!graphColoring(matrix,m,0,color))
    {
        cout<<"Solution does not exist";
    }
    return 0;
}