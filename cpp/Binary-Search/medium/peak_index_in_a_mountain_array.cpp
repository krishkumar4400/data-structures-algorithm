/**
 * Problem: Peak Index in a Mountain Array
 * Leetcode: 852
 * Difficulty: Medium
 * Pattern: Binary Search
 *
 * Approach 1: Brute force - linear search
 * TC = O(n)
 * SC = O(1)

 * Approach 2: Optimal  - Binary search
 * TC = O(n)
 * SC = O(log n)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // int peakIndexInMountainArray(vector<int> nums)
    // {
    //     int n = nums.size();
    //     for (int i = 1; i < n - 1; i++)
    //     {
    //         if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    int peakIndexInMountainArray(vector<int> nums)
    {
        int st = 1;
        int end = nums.size() - 2;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[mid - 1] < nums[mid])
            { // right
                st = mid + 1;
            }
            else
            { // left
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {0, 3, 8, 9, 5, 2};
    Solution s = Solution();
    int ans = s.peakIndexInMountainArray(nums);
    cout << "Ans = " << ans << endl;
    return 0;
}