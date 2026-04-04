/**
 * Problem: Painters Partition Problem
 * Difficulty: Hard
 * Pattern: Binary Search
 *
 * Approach 1: Optimal  - Binary search
 * TC = O(n log n)
 */

#include <iostream>
#include <vector>
#include <algorithm>
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

    int isPossible(vector<int> nums, int maxAllowedTime, int k)
    {
        int painters = 1;
        int time = 0;
        for (int val : nums)
        {
            if (val + time <= maxAllowedTime)
            {
                time += val;
            }
            else
            {
                painters++;
                time = val;
                if(painters > k) return false; // early exit
            }
        }
        return true;
    }

    int partition(vector<int> nums, int k)
    {
        int st = *max_element(nums.begin(), nums.end());
        int end = sum(nums);
        int ans = -1;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (isPossible(nums, mid, k))
            {
                end = mid - 1;
                ans = mid;
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
    vector<int> nums = {40, 30, 10, 20};
    int k = 2;
    Solution s;
    int ans = s.partition(nums, k);
    cout << "Ans = " << ans <<endl;
    return 0;
}