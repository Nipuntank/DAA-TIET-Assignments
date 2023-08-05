#include<iostream>
using namespace std;
void printValues(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void generateSubsetHelper(int set[],int t[],int set_size,int t_size,int sum,int ite,int const target)
{
    if(target==sum)
    {
        printValues(t,t_size);
        generateSubsetHelper(set,t,set_size,t_size-1,sum-set[ite],ite+1,target);
        return;
    }
    else{
        for(int i=ite;i<set_size;i++)
        {
            t[t_size]=set[i];
            generateSubsetHelper(set,t,set_size,t_size+1,sum+set[i],i+1,target);
        }
    }
}
void generateSubset(int set[],int n,int target)
{
    int *t=new int[n];
    generateSubsetHelper(set,t,n,0,0,0,target);
}
int main()
{
    int set[] = { 5, 6, 12 , 54, 2 , 20 , 15 };
    int n = sizeof(set) / sizeof(set[0]);
    cout<<"Initial set is:";
    printValues(set,n);
    generateSubset(set,n,25);

    return 0;
}