/**
 * Problem: Valid Palindrome
 * Leetcode: 125
 * Difficulty: Easy
 * Pattern: Two Pointer's
 *

 * Approach 1: Optimal  - Binary search
 * TC = O(n)
 * SC = O(log n)
 */

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

bool isAlphaNum(char ch)
{
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    {
        return true;
    }
    return false;
}

bool isPalindrome(string s)
{
    int st = 0;
    int end = s.length() - 1;

    while (st <= end)
    {
        if (!(isAlphaNum(s[st])))
        {
            st++;
            continue;
        }
        if (!isAlphaNum(s[end]))
        {
            end--;
            continue;
        }

        if (tolower(s[st]) != tolower(s[end]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    bool ans = isPalindrome(s);
    cout << "Ans = " << ans << endl;
    return 0;
}