#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int> &nums, int target)
{
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {

            int result = mid;
            right = mid - 1;

            while (left <= right)
            {
                int newMid = left + (right - left) / 2;

                if (nums[newMid] == target)
                {
                    result = newMid;
                    right = newMid - 1;
                }
                else if (nums[newMid] < target)
                {
                    left = newMid + 1;
                }
                else
                {
                    right = newMid - 1;
                }
            }
            return result;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, target;

    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size" << endl;
        return 0;
    }

    vector<int> nums(n);

    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    int result = binarySearch(nums, target);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}