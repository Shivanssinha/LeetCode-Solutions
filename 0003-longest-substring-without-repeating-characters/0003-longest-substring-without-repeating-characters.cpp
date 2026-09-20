class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l = 0,r = 0,maxlen = 0;
        int len = 0;
        while(r<s.length()){
            if(!seen.count(s[r])){
                seen.insert(s[r]);
                len++;
                maxlen = max(len,maxlen);
                r++;
            }
            else{
                seen.erase(s[l]);
                l++;
                len--;
            }

        }
        return maxlen;
    }
};