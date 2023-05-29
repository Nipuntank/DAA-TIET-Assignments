#include <iostream>
using namespace std;
// Recursive Approach
int binarySearch(int *arr, int si, int ei, int num)
{
    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (arr[mid] == num)
        {
            return mid;
        }

        if (arr[mid] < num)
        {
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }
        return binarySearch(arr, si, ei, num);
    }
    return -1;
}
// Iterative Approach
/*void binarySearch(int *arr, int n, int num)
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
}*/
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
    int index = binarySearch(arr, 0, n, num);
    if (index != -1)
    {
        cout << index << endl;
    }
    else
    {
        cout << num << " Not found in the array" << endl;
    }

    return 0;
}