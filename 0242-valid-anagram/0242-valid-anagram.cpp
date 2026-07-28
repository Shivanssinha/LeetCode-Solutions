class Solution {
public:
    bool isAnagram(string s, string t) {

        if (t.length() != s.length()) {
            return false;
        }

        vector<int> v(26, 0);

        for (int i = 0; i < s.length(); i++) {
            v[s[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            v[t[i] - 'a']--;
        }

        for (int k : v) {
            if (k != 0) {
                return false;
            }
        }

        return true;
    }
};