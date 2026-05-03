/**
 * Problem: Reverse Words in a String
 * Difficulty: Medium
 * Pattern: String
 * Leetcode: 443
 *
 *
 * TC = O(n)
 */

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int idx = 0;

        for (int i = 0; i < n; i++)
        {
            char ch = chars[i];
            int count = 0;
            while (i < n && chars[i] == ch)
            {
                count++;
                i++;
            }
            if (count == 1)
            {
                chars[idx++] = ch;
            }
            else
            {
                string str = to_string(count);
                chars[idx++] = ch;
                for (int digit : str)
                {
                    chars[idx++] = digit;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};

int main()
{

    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    Solution s;
    int ans = s.compress(chars);
    cout << "Ans = " << ans << endl; // 6

    return 0;
}