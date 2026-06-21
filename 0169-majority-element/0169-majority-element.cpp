class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();
        int ele = v[0];
        int c = 1;
        for(int i = 1;i<n;i++){
            if(c ==0){
                ele = v[i];
                c = 1;
            }
            else if(ele == v[i])c++;
            else c--;
        }
        return ele;

    }
};