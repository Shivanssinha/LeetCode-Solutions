class Solution {
public:
    void sortColors(vector<int>& v) {
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        for(int j = 0;j<v.size();j++){
            if(v[j] == 0)c0++;
            if(v[j] == 1)c1++;
            if(v[j] == 2)c2++;
            //yoyo
        }
        for(int j = 0;j<v.size();j++){
            if(j<c0)v[j] = 0;
            else if((j - c0)<c1)v[j] = 1;
            else v[j] = 2;
        }
    }
};