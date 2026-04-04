/**
 * Problem: Book Allocation Problem
 * Leetcode:
 * Difficulty: Hard
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
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
    
    public:
    int sum(vector<int>nums) {
        int sum = 0;
        for(int val : nums) {
            sum += val;
        }
        return sum;
    }

    bool isValid(vector<int>nums, int n, int m, int maxAllowedPages) {
        int student = 1, pages = 0;
        for(int val : nums) {
            if(val > maxAllowedPages) {
                return false;
            }
            if(pages + val <= maxAllowedPages) {
                pages += val;
            } else {
                student++;
                pages = val;
            }
        }
        return student <= m;
    }

    int bookAllocation(vector<int>nums, int n, int m) {
        int st = 0, end = sum(nums);
        int ans = -1;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if(isValid(nums, n, m, mid)) {
                ans = mid;
                end = mid-1;
            } else {
                st = mid + 1;
            }
        }
    return ans;  
    }
};

int main()
{
    vector<int>nums = {2,1,3,4};
    int n = nums.size();
    int m = 2;
    Solution s = Solution();
    int ans = s.bookAllocation(nums, n, m);
    cout << "Ans = " << ans << endl;
    return 0;
}