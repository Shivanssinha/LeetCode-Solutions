// Problem: 1523. Count Odd Numbers in an Interval Range
// Difficulty: Easy
// Platform: LeetCode
//
// Intuition:
// Instead of iterating through the range [low, high], we can use math.
// The count of odd numbers up to any number x is x / 2 (integer division).
// Using this observation, we can compute the answer in O(1) time.
//
// Approach:
// 1. The number of odd numbers from 1 to x is x / 2.
// 2. To count odd numbers in [low, high], subtract:
//      odds up to high  -  odds up to (low - 1)
// 3. This logic can be simplified using integer division and parity checks.
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int countOdds(int low, int high) {
        if (low % 2 == 0 && high % 2 == 0)
            return high / 2 - low / 2;
        if (low % 2 == 1 && high % 2 == 0)
            return high / 2 - low / 2;
        if (low % 2 == 0 && high % 2 == 1)
            return high / 2 - low / 2 + 1;
        return high / 2 - low / 2 + 1;
    }
};
