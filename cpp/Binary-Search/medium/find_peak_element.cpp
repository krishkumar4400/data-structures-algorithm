/**
 * Problem: Find Peak Element
 * Leetcode: 162
 * Difficulty: Medium
 * Pattern: Binary Search
 *

 * Approach 1: Optimal  - Binary search
 * TC = O(n)
 * SC = O(log n)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }

        if (nums[0] > nums[1])
        {
            return 0;
        }

        if (nums[n - 1] > nums[n - 2])
        {
            return n - 1;
        }

        int st = 1;
        int end = n - 2;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[mid - 1] < nums[mid])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
};

int
main()
{

    // vector<int> nums = {1, 2, 3, 1};
    vector<int> nums = {1, 2, 1, 3, 4, 6, 4};
    Solution s;
    int ans = s.findPeakElement(nums);
    cout << "Ans = " << ans << endl; // 5

    return 0;
}