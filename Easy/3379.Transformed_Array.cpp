#include <vector>
using namespace std;

// Problem: 3379. Transformed Array
// Difficulty: Easy
// Platform: LeetCode
//
// Intuition:
// Each element nums[j] tells us how many steps to move from index j.
// The movement is circular (wraps around the array).
// So we compute the new index using modulo arithmetic.
//
// Approach:
// 1. Create a result array of the same size.
// 2. For each index j:
//      - If nums[j] == 0 → value stays the same.
//      - Otherwise move nums[j] steps from j.
// 3. Use modulo (%) to wrap around the array.
// 4. Handle negative modulo results by adding n.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n);  

        for (int j = 0; j < n; j++) {
            if (nums[j] == 0) {
                r[j] = nums[j];
            }
            else {
                int newIndex = (j + nums[j]) % n;
                if (newIndex < 0) {
                    newIndex += n;
                }

                r[j] = nums[newIndex];
            }
        }

        return r;
    }
};
