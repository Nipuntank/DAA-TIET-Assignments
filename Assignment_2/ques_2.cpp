#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
class Job
{
    public:
    char id;
    int dead;
    int profit;
};
/*bool comparison(Job a,Job b)
{
    return (a.profit>b.profit);
}
// Greedy Approach with time Complexity of O(n^2)
void JobSequencing(Job emp[],int n)
{
    sort(emp,emp+n,comparison);
    int result[n];
    bool slot[n];
    for(int i=0;i<n;i++)
    {
        slot[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,emp[i].dead)-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(slot[i])
        {
            cout<<emp[result[i]].id<<" ";
        }
    }
}*/

// Time Complexity O(nlogn)
class JobProfit
{
    public:
    bool operator()(Job const& a,Job const& b)
    {
        return a.profit<b.profit;
    }
};
bool deadline(Job a,Job b)
{
    return a.dead<b.dead;
}
void JobSequencing2(Job emp[],int n)
{
    vector<Job>result;
    sort(emp,emp+n,deadline);
    priority_queue<Job,vector<Job>,JobProfit>pq;
    for(int i=n-1;i>=0;i--)
    {
        int slotAvail;
        if(i==0)
        {
            slotAvail=emp[i].dead;
        }
        else{
            slotAvail=emp[i].dead-emp[i-1].dead;
        }
        pq.push(emp[i]);
        while(slotAvail>0 && pq.size()>0)
        {
            Job job = pq.top();
            pq.pop();
            slotAvail--;
            result.push_back(job);
        }
    }
    sort(result.begin(),result.end(),deadline);
    for(int i=0;i<n;i++)
    {
        cout<<result[i].id<<" ";
    }

}
int main()
{
    Job emp[]={{ 'a', 2, 100 },{ 'b', 1, 19 },{ 'c', 2, 27 },{ 'd', 1, 25 },{ 'e', 3, 15 }};
    int n = sizeof(emp)/sizeof(emp[0]);
    JobSequencing2(emp,n);
    return 0;
}