class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = *max_element(nums.begin(),nums.end());
        if(n == 1)return 1;
        if(n == 2)return 2;
        int a = 1;
        while(a<= n){
            a = a*2;
        }
        return a;
    }
};