/**
 * Problem: Find First and Last Position of Element in Sorted Array
 * Leetcode: 34
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
    int getPosition(vector<int> &nums, int target, bool isStart)
    {
        int st = 0;
        int end = nums.size() - 1;
        int ans = -1;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                if (isStart)
                {
                    end = mid - 1;
                }
                else
                {
                    st = mid + 1;
                }
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
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return {getPosition(nums, target, true), getPosition(nums, target, false)};
    }
};

int main()
{

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution s;
    vector<int> ans = s.searchRange(nums, target);
    cout << "Ans = [" << ans[0] << "," << ans[1] << "]" << endl;
    return 0;
}