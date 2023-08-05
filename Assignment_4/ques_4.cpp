#include<iostream>
#define V 5
using namespace std;
void printSolution(int path[])
{
    for(int i=0;i<V;i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<path[0];
    cout<<endl;
}
bool isSafe(int v,int i,bool graph[V][V],int path[])
{
    if(graph[path[i-1]][v]==0)
    {
        return false;
    }
    for(int j=0;j<i;j++)
    {
        if(path[j]==v)
        {
            return false;
        }
    }
    return true;
}
bool hamCycle(int i,bool graph[V][V],int path[])
{
    if(i==V)
    {
        if(graph[path[i-1]][path[0]])
        {
            return true;
        }
        else{
            return false;
        }
    }
    for(int v=1;v<V;v++)
    {
        if(isSafe(v,i,graph,path))
        {
            path[i]=v;
            if(hamCycle(i+1,graph,path))
            {
                return true;
            }
            path[i]=-1;
        }
    }
    return false;
}
bool hamCycle(bool graph[V][V])
{
    int *path=new int[V];
    for(int i=0;i<V;i++)
    {
        path[i]=-1;
    }
    path[0]=0;
    if(!hamCycle(1,graph,path))
    {
        cout<<"Solution does not exist";
        return false;
    }
    printSolution(path);
    return true;
}
int main()
{
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
						{1, 0, 1, 1, 1},
						{0, 1, 0, 0, 1},
						{1, 1, 0, 0, 1},
						{0, 1, 1, 1, 0}};
    hamCycle(graph1);

    return 0;
}