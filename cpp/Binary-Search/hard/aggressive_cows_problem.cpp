/**
 * Problem: Book Allocation Problem
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
    int maxElement(vector<int> nums)
    {
        int maxElement = INT_MIN;
        for (int val : nums)
        {
            if (val > maxElement)
            {
                maxElement = val;
            }
        }
        return maxElement;
    }

    bool isPossible(vector<int> nums, int minAllowedDist, int N, int C)
    { // O(N)

        int cows = 1, lastPosition = nums[0];

        for (int i = 1; i < N; i++)
        {
            if (nums[i] - lastPosition >= minAllowedDist)
            {
                cows++;
                lastPosition = nums[i];
            }

            if (cows == C)
            {
                return true;
            }
        }
        return false;
    }

    int
    getDistance(vector<int> nums, int N, int C)
    { // O(log Range * N) + O(NlogN)
        sort(nums.begin(), nums.end()); // O(NlogN)
        int min = 1, max = nums[N - 1] - nums[0];
        int ans = -1;
        while (min <= max)
        { // O(log Range)
            int mid = min + (max - min) / 2;
            if (isPossible(nums, mid, N, C))
            { // right
                ans = mid;
                min = mid + 1;
            }
            else
            { // left
                max = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    int N = 5, C = 3;
    vector<int> nums = {1, 2, 4, 8, 9};

    Solution s;
    int ans = s.getDistance(nums, N, C);
    cout << "Ans = " << ans << endl;

    return 0;
}