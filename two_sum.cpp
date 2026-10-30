#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> seen;

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];

        if (seen.find(complement) != seen.end())
        {
            return {seen[complement], i};
        }

        seen[nums[i]] = i;
    }

    return {};
}

int main()
{
    int n, target;

    cout << "Enter arraya size: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size" << endl;
        return 0;
    }

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    if (result.empty())
    {
        cout << "No solution found" << endl;
    }
    else
    {
        cout << "Indices: "
             << result[0] << " " << result[1] << endl;
    }

    return 0;
}