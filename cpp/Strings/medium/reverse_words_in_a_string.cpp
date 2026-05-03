/**
 * Problem: Reverse Words in a String
 * Difficulty: Medium
 * Pattern: String
 * Leetcode: 151
 *
 *
 * TC = O(n)
 */

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        string ans = "";
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            string word = "";
            while (s[i] != ' ' && i < n)
            {
                word += s[i];
                i++;
            }

            if (word.length() > 0)
            {
                reverse(word.begin(), word.end());

                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};

int main()
{
    string str = "the sky is blue";
    Solution s;
    string ans = s.reverseWords(str);
    cout << "Ans = " << ans << endl; // "blue is sky the"

    return 0;
}