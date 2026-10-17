class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi =INT_MIN,sum = 0;
        for(int x: gain){
            sum += x;
            maxi = max(sum,maxi);
        }
        if(maxi<0){
            return 0;
        }
        return maxi;
    }
};