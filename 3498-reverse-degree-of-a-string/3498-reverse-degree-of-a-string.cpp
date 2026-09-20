class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int i = 0;
        for(char c:s){
            sum += ((i + 1)*(26-(c - 'a')));
            i++;
        }
        return sum;
    }
};