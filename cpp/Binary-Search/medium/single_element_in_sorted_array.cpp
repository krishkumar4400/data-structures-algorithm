/**
 * Problem: Single Element in a Sorted Array
 * Leetcode: 540
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
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    // simple loop -> T.C = O(n), S.C. = O(1)
    // int singleNonDuplicate(vector<int> nums)
    // {
    //     int n = nums.size();

    //     // case-1: array contains single element
    //     if (n == 1)
    //     {
    //         return nums[0];
    //     }

    //     // case-2: first element is answer
    //     if (nums[0] != nums[1])
    //     {
    //         return nums[0];
    //     }

    //     // case-3: last element is answer
    //     if (nums[n - 1] != nums[n - 2])
    //     {
    //         return nums[n - 1];
    //     }

    //     for (int i = 1; i < n - 2; i++)
    //     {
    //         if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
    //         {
    //             return nums[i];
    //         }
    //     }
    //     return -1;
    // }

    // XOR Operator->T.C = O(n), S.C.= O(1)
    // int singleNonDuplicate(vector<int> nums)
    // {
    //     int ans = 0;
    //     for(int val : nums) {
    //         ans ^= val;
    //     }
    //     return ans;
    // }

    // unordered map
    //  int singleNonDuplicate(vector<int> nums)
    //  {
    //      unordered_map<int, int> m;
    //      int n = nums.size();
    //      for (int i = 0; i < n; i++)
    //      {
    //          if (m.find(nums[i]) == m.end())
    //          {
    //              m[nums[i]] = i;
    //          }
    //          else
    //          {
    //              m.erase(nums[i]);
    //          }
    //      }
    //      return m.begin()->first;
    //  }

    // unordered set
    // int singleNonDuplicate(vector<int> nums)
    // {
    //     unordered_set<int> s;
    //     for (int val : nums)
    //     {
    //         if (s.count(val))
    //         {
    //             s.erase(val);
    //         }
    //         else
    //         {

    //             s.insert(val);
    //         }
    //     }
    //     return *s.begin();
    // }

    // binary search
    int singleNonDuplicate(vector<int> nums)
    {
        int st = 1;
        int end = nums.size() - 2;
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        if (nums[0] != nums[1])
        {
            return nums[0];
        }

        if (nums[n - 1] != nums[n - 2])
        {
            return nums[n - 1];
        }

        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            else if (mid % 2 == 0)
            { // even
                if (nums[mid] == nums[mid - 1])
                {
                    end = mid - 1;
                }
                else
                {
                    st = mid + 1;
                }
            }
            else
            { // odd
                if (nums[mid] == nums[mid - 1])
                {
                    st = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    // vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 8};
    // vector<int> nums = {2,2,1};
    vector<int> nums = {1,1,2,3,3};
    Solution s = Solution();
    int ans = s.singleNonDuplicate(nums);
    cout << "Ans = " << ans << endl; // 2
    return 0;
}