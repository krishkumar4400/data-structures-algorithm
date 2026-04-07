/**
 *
 */

#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &nums, int n)
{ // TC -> O(n^2)
    for (int i = 0; i < n-1; i++)
    {  // 1 * n
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        { // 1 * n -> n * n 
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                isSwap = true;
            }
        }
        if(!isSwap) { // array is already sorted
            return;
        }
    }
}

void traverse(vector<int> nums)
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
    int n = nums.size();
    bubbleSort(nums, n);
    traverse(nums);

    return 0;
}
