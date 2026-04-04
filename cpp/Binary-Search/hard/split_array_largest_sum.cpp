/**
 * Problem: Split Array Largest Sum
 * Leetcode: 410
 * Difficulty: Hard
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
    int sum(vector<int> nums)
    {
        int arraySum = 0;
        for (int val : nums)
        {
            arraySum += val;
        }
        return arraySum;
    }

    bool isValid(vector<int> nums, int n, int k, int maxAllowedPages)
    {
        int student = 1, pages = 0;

        for (int val : nums)
        {
            if (val > maxAllowedPages)
            {
                return false;
            }

            if (pages + val <= maxAllowedPages)
            {
                pages += val;
            }
            else
            {
                student++;
                pages = val;
            }
        }
        return student <= k;
    }

    int splitArray(vector<int> nums, int k)
    {
        int st = 0, end = sum(nums);
        int n = nums.size();
        int ans = -1;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (isValid(nums, n, k, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
Input:
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    Solution s = Solution();
    int ans = s.splitArray(nums, k);
    cout << "Ans = " << ans << endl; // 18
    return 0;
}