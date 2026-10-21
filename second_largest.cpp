#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size" << endl;
        return 0;
    }

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int largest = arr[0];
    int secondLargest = arr[0];
    bool found = false;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
            found = true;
        }
        else if (arr[i] < largest && (!found || arr[i] > secondLargest))
        {
            secondLargest = arr[i];
            found = true;
        }
    }

    if (found)
    {
        cout << "Second largest: " << secondLargest << endl;
    }
    else
    {
        cout << "No distinct second-largest element" << endl;
    }

    return 0;
}