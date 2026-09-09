class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int l = 0,r = n - 1,maxl = 0,maxr = 0;
        int t = 0;
        while(l<r){
            if(h[l]<h[r]){
                if(h[l]>=maxl)maxl = h[l];
                else{
                    t += maxl - h[l];
                }
                l++;
            }
            else{
                if(h[r]>=maxr)maxr = h[r];
                else{
                    t += maxr - h[r];
                }
                r--;
            }
        }
        return t;
    }
};