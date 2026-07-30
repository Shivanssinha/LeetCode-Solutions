class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l = 0, r = 0, maxlen = 0;

        while (r < s.length()) {
            if (!seen.count(s[r])) {
                seen.insert(s[r]);
                maxlen = max(maxlen, r - l + 1);
                r++;
            } else {
                seen.erase(s[l]);
                l++;
            }
        }

        return maxlen;
    }
};