class Solution {
public:
    bool search(vector<int>& v, int t) {
        int l = 0;
        int h = v.size()- 1;
        while(l<=h){
            int m = l + ( h - l)/2;
            if(v[m] == t)return true;
            if(v[m] == v[l] && v[m] == v[h]){
                l++;
                h--;
                continue;
            }
            if(v[m]>=v[l]){
                if(t>= v[l] && t<=v[m]){
                    h = m - 1;
                }
                else{
                    l = m + 1;
                }
            }
            else{
                if(t>= v[m] && t<= v[h]){
                    l = m + 1;
                }
                else {
                    h = m - 1;
                }
            }
        }
        return false;
    }
};