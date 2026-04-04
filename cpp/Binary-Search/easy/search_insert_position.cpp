/**
 * Problem: Search Insert Position
 * Leetcode: 35
 * Difficulty: Easy
 * Pattern: Binary Search
 *
 * Approach 1: Optimal  - Binary search
 * TC = O(n log n)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int insertPosition(vector<int> nums, int target)
    {
        int st = 0, end = nums.size() - 1;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return st;
    }
};

int main()
{
    // vector<int> nums = {1, 3, 5, 6};
    // int target = 5;

    // vector<int> nums = {1, 3, 5, 6};
    // int target = 2;

    vector<int> nums = {1, 3, 5, 6};
    int target = 7;

    Solution s;
    int ans = s.insertPosition(nums, target);
    cout << "Ans = " << ans << endl; // 4
    return 0;
}
