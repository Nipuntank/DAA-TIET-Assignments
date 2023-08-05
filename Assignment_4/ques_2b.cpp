#include<iostream>
#include<algorithm>
using namespace std;
void printSubset(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int comparator(const void *plhs,const void *prhs)
{
    int *lhs=(int *)plhs;
    int *rhs=(int *)rhs;
    return *lhs>*rhs;
}
void subset_sum(int set[],int t[],int set_size,int t_size,int sum,int ite,int target)
{
    if(target==sum)
    {
        printSubset(t,t_size);
        if (ite + 1 < set_size && sum - set[ite] + set[ite + 1] <= target)
        {

            // Exclude previous added item and consider next candidate
            subset_sum(set, t, set_size, t_size - 1, sum - set[ite], ite + 1, target);
        }
        return;
    }
    else{
        if(ite<set_size && sum+set[ite]<=target)
        {
            for(int i=ite;i<set_size;i++)
            {
                t[t_size]=set[i];
                if(sum+set[i]<=target)
                {
                    subset_sum(set,t,set_size,t_size+1,sum+set[i],i+1,target);
                }
            }
        }
        
    }
}
void generateSubsets(int set[],int n,int target)
{
    int *t=new int[n];
    sort(set,set+n);
    int total=0;
    for(int i=0;i<n;i++)
    {
        total+=set[i];
    }
    if(set[0]<=target && total>=target)
    {
        subset_sum(set,t,n,0,0,0,target);
    }

}
int main()
{
    int weights[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int target = 53;
    int n = sizeof(weights)/sizeof(weights[0]);
    generateSubsets(weights,n,target);
    return 0;
}