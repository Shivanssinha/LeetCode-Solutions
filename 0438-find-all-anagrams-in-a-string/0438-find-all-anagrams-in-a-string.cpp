class Solution {
public:
    bool eq(vector<int>& a,vector<int>& b){
        for(int i = 0;i<26;i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())return {};
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(auto c:p){
            a[c -'a']++;
        }
        int i = 0,j = 0;
        vector<int> ans;
        while(j<s.size()){
            b[s[j] - 'a']++;
            if(j - i + 1 == p.size()){
                if(eq(a,b)){
                    ans.push_back(i);
                }
            }
            if(j - i + 1<p.size()){
                j++;
            }
            else{
                b[s[i] - 'a']--;
                j++;
                i++;
            }
        }
        return ans;
    }
};