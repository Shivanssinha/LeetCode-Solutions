class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        int total1 = count(s.begin(), s.end(), '1');
        vector<int> pref(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt++;
                
            }
            pref[i] = cnt;
        }
        vector<bool> ans;
        for (string t : strs) {
            int ones = 0, ques = 0;

            for (char c : t) {
                if (c == '1')
                    ones++;
                else if (c == '?')
                    ques++;
            }
            int need = total1 - ones;
            if (need < 0 || need > ques) {
                ans.push_back(false);
                continue;
            }
            for (int i = n - 1; i >= 0; i--) {
                if (t[i] == '?') {
                    if (need > 0) {
                        t[i] = '1';
                        need--;
                    } else {
                        t[i] = '0';
                    }
                }
            }
            bool possible = true;
            cnt = 0;
            for (int i = 0; i < n; i++) {
                if (t[i] == '1')
                    cnt++;
                if (cnt > pref[i]) {
                    possible = false;
                    break;
                }
            }
            ans.push_back(possible);
        }
        return ans;
    }
};