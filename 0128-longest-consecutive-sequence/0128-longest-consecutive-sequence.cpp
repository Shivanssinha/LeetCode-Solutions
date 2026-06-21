class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        unordered_set<int> st;
        for(int j = 0;j<n;j++){
            st.insert(nums[j]);
        }
        for(auto x : st){
            if(st.find(x - 1) == st.end()){
                int y = x;
                int cnt = 1;
                while(st.find(y+1) != st.end()){
                    y = y + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};