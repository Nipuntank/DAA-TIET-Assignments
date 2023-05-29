#include <iostream>
using namespace std;
void binarySearch(int *arr, int n, int num)
{
    int low = 0, high = n - 1;
    int mid;
    while (high - low > 1)
    {
        int mid = (high + low) / 2;
        if (arr[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if(arr[low]==num)
    {
        cout<<"Found At index "<<low<<endl;
    }
    else if(arr[high]==num)
    {
        cout<<"Found At index "<<high<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
}
int main()
{
    int n, num;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the number to be search:";
    cin >> num;
    binarySearch(arr, n, num);
    return 0;
}