
class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int,int> b;
        int l = 0,maxlen = 0;
        for(int r  = 0;r<f.size();r++){
            b[f[r]]++;
            while(b.size()>2){
                b[f[l]]--;
                if(b[f[l]] == 0){
                    b.erase(f[l]);
                }
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;

    }
};