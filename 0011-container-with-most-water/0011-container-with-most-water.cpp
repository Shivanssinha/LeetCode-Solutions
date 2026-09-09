class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0,r = n - 1;
        int m = 0;
        while(l<r){
            int k = min(height[l],height[r]);
            int dist = r - l;
            m = max(dist*k,m);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return m;
    }
};