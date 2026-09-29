class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int sum = 0,mini = INT_MAX;
        for(int i =0;i<n;i++){
            sum += nums[i];
            mini = min(sum, mini);
        }
        if(mini<=0){
            return abs(mini) + 1;
        }
        else{
            return 1;
        }
    }
};