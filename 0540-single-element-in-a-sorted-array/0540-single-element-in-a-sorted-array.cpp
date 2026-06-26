class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x = 0;
        for(int k : nums){
            x = x ^k;
        }
        return x;
    }
};