#include <string>
#include <algorithm>
using namespace std;

// Problem: Convert a Number to Hexadecimal
// Difficulty: Easy
// Platform: LeetCode
//
// Intuition:
// Hexadecimal is base-16, so every hex digit represents 4 bits.
// Instead of dividing by 16, we can extract the last 4 bits using bitwise operations.
// This makes the solution efficient and clean, even for negative numbers.
//
// Approach:
// 1. Handle the special case when num == 0.
// 2. Repeatedly extract the last 4 bits using (num & 15).
// 3. Convert the extracted value to the corresponding hex character.
// 4. Right shift num by 4 bits to process the next hex digit.
// 5. Reverse the result since digits are generated from least significant to most significant.
// Time Complexity: O(1)
// (At most 8 iterations since an int has 32 bits)
// Space Complexity: O(1)

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string ans = "";
        int count = 0;

        
        while (num != 0 && count < 8) {
            int digit = num & 15;   

            if (digit < 10)
                ans.push_back('0' + digit);
            else
                ans.push_back('a' + (digit - 10));

            num >>= 4;  
            count++;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
