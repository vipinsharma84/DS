#include <iostream>
#include <vector>
using namespace std;

bool binarysearch(int arr[], int low, int high, int n)
{
    if (low >= high)
    {
        return false;
    }
    int mid = (low + high) /2;
    cout << "Arr Mid is " << arr[mid];
    if(arr[mid] == n)
    {
        return true;
    }
    else
    {
        if(arr[mid] > n)
        {
            binarysearch(arr, low, mid, n);
        }
        else
        {
            binarysearch(arr, mid, high, n);
        }
    }
}

int main()
{
    int array [10] = { 6,12,23,33,34,59,63,74,89,91};
    cout << binarysearch(array,0,10,89);
    return 0;

}
