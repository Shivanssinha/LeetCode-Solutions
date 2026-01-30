#include <string>
using namespace std;

// Problem: 1328. Break a Palindrome
// Difficulty: Medium
// Approach: Greedy
// Platform: LeetCode
//
// Intuition:
// To make the palindrome non-palindromic while keeping it lexicographically smallest,
// we should try to change the earliest possible character to the smallest character ('a').
// Only the first half needs to be checked because palindromes are symmetric.
//
// Approach:
// 1. If the string length is 1, it is impossible to break the palindrome, so return "".
// 2. Traverse only the first half of the string.
// 3. Find the first character that is not 'a' and change it to 'a'.
//    This guarantees the smallest lexicographical result.
// 4. If all characters in the first half are 'a',
//    change the last character to 'b' to break the palindrome.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string breakPalindrome(string p) {
        // Edge case: single character palindrome
        if (p.length() == 1) return "";
        for (int j = 0; j < p.length() / 2; j++) {
            if (p[j] != 'a') {
                p[j] = 'a';
                return p;
            }
        }
        p[p.length() - 1] = 'b';
        return p;
    }
};
