/**
 *
 */

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void selectionSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    { // O(n^2)
        int smallestIndex = i; // unsorted part starting
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[smallestIndex])
            {
                smallestIndex = j;
            }
        }
        swap(nums[i], nums[smallestIndex]);
    }
}

void printArray(vector<int> nums)
{
    for (int val : nums)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {4, 1, 5, 2, 3};
    printArray(nums);
    selectionSort(nums);
    printArray(nums);

    return 0;
}