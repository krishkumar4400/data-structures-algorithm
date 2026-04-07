/**
 * Problem: Magnetic Force Between Two Balls
 * Leetcode: 1552
 * Difficulty: Medium
 * Pattern: Binary Search
 *
 * Approach 1: Optimal  - Binary search
 * TC = O(n log n)
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool isPossible(vector<int> position, int N, int M, int minPossibleDist)
    { // O(N)
        int balls = 1, lastPosition = position[0];

        for (int i = 1; i < N; i++)
        {
            if (position[i] - lastPosition >= minPossibleDist)
            {
                balls++;
                lastPosition = position[i];
            }

            if (balls == M)
            {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int> &position, int m)
    { // O(log Range * N) + O(nlogn)
        sort(position.begin(), position.end()); // O(n log n)
        int n = position.size();
        int st = 1;
        int end = position[n - 1] - position[0];
        int ans = -1;

        while (st <= end)
        { // O(log Range)
            int mid = st + (end - st) / 2;

            if (isPossible(position, n, m, mid))
            {
                ans = mid;
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};
using namespace std;

int main()
{
    // vector<int> position = {5, 4, 3, 2, 1, 1000000000};
    // int m = 2;

    vector<int> position = {1, 2, 3, 4, 7};
    int m = 3;

    Solution s;
    int ans = s.maxDistance(position, m);
    cout << "Ans: " << ans << endl; // 999999999

    return 0;
}