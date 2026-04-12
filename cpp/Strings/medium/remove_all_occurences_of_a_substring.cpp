/**
 * Problem: Remove All Occurrences of a Substring
 * Difficulty: Medium
 * Pattern: String
 *
 * Approach 1: -
 * TC = O(n)
 */

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        if (s.length() < part.length())
        {
            return s;
        }
        while (s.length() > 0 && s.find(part) < s.length())
        {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    Solution soln;
    string ans = soln.removeOccurrences(s, part);
    cout << "Ans = " << ans << endl; // dab
    return 0;
}