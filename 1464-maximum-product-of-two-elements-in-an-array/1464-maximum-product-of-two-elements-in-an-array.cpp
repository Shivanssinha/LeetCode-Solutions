class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int larg = 0,larg1 = 0;
        for(int k:nums){
            if(k>larg){
                larg1 = larg;
                larg = k;
            }
            else {
                if(k>larg1){
                    larg1 = k;
                }
            }
        }
        return (larg - 1)*(larg1 - 1);
    }
};