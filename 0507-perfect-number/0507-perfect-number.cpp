class Solution {
public:
    bool checkPerfectNumber(int n) {
        vector<int> ans;
        for(int i = 1;i*i<=n;i++){
            if(n %i == 0){
                ans.push_back(i);
                if(i != (n/i)){
                    ans.push_back(n/i);
                }
            }
        }
        int sum = 0;
        for(int a:ans){
            sum += a;
        }
        sum = sum - n;
        if(sum != n)return false;
        else return true;
    }
};