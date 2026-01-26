#include <vector>
using namespace std;
// Problem: Smaller Numbers Than Current
// Difficulty: Easy
// Approach: Counting + Prefix Sum
// Time Complexity: O(n)
// Space Complexity: O(1)
//2nd question in array 2nd quest section of leetcode

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101, 0);

        for (int x : nums) {
            freq[x]++;
        }

        for (int i = 1; i <= 100; i++) {
            freq[i] += freq[i - 1];
        }

        vector<int> output(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                output[i] = 0;
            else
                output[i] = freq[nums[i] - 1];
        }

        return output;
    }
};
