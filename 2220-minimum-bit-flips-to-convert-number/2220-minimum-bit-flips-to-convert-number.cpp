class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        int a = start ^ goal;
        while(a){
            ans += a & 1;
            a = a>> 1;
        }
        return ans;
    }
};