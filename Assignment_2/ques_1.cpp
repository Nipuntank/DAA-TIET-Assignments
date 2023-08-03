#include<iostream>
#include<algorithm>
using namespace std;
class Act
{
    public:
    int start;
    int finish;
};
// Arrange in decreasing order of finish time
bool ActFinish(Act s1,Act s2)
{
    return (s1.finish<s2.finish);
}
void ActivitySelection(Act *arr,int n)
{
    sort(arr,arr+n,ActFinish);
    int i=0;
    cout<<"("<<arr[i].start<<","<<arr[i].finish<<")"<<endl;
    for(int j=1;j<n;j++)
    {
        if(arr[j].start>=arr[i].finish)
        {
            cout<<"("<<arr[j].start<<","<<arr[j].finish<<")"<<endl;
            i=j;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    Act arr[n];
    cout<<"Enter the start time:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].start;
    }
    cout<<"Enter the finish time:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].finish;
    }
    ActivitySelection(arr,n);
    return 0;
}