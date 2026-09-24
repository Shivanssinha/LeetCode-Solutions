class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> freq;
        unordered_map<char, int> freq1;
        for (int i = 0; i < t.size(); i++) {
            freq[t[i]]++;
        }
        int longest = INT_MAX;
        int start = 0;
        int have = 0;
        int l = 0;
        int h = freq.size();
        for (int i = 0; i < s.size(); i++) {
            freq1[s[i]]++;
            if(freq.count(s[i]) && freq[s[i]] == freq1[s[i]]){
                have++;
            }
            while (have == h) {
                if (longest > i - l + 1) {
                    longest = i - l + 1;
                    start = l;
                }
                freq1[s[l]]--;
                if (freq.count(s[l]) && freq1[s[l]] < freq[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        if(longest == INT_MAX)
            return "";

        return s.substr(start, longest);
    }
};