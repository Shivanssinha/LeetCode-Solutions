class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;

        // XOR of all numbers = unique1 ^ unique2
        for (int num : nums) {
            xr ^= num;
        }

        // Find the rightmost set bit safely
        unsigned int diff = (unsigned int)xr & -(unsigned int)xr;

        int a = 0, b = 0;

        // Divide numbers into two groups
        for (int num : nums) {
            if ((unsigned int)num & diff) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};