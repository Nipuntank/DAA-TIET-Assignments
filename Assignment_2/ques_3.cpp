#include<iostream>
#include<algorithm>
using namespace std;
class Item
{
    public:
    int value;
    int weight;
};
bool Ratio(Item a,Item b)
{
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    return r1>r2;
}
int fractionalKnapsack(Item arr[],int n,int W)
{
    sort(arr,arr+n,Ratio);
    double finalValue=0.00;
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight<=W)
        {
            W-=arr[i].weight;
            finalValue+=arr[i].value;
        }
        else{
            finalValue+=arr[i].value*((double)W/(double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}
int main()
{
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << fractionalKnapsack(arr,n,W)<<endl;
    return 0;
}