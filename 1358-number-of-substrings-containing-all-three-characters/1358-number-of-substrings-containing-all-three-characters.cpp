class Solution {
public:
    int numberOfSubstrings(string s) {
        int ca = 0, cb = 0, cc = 0;
        int l = 0;
        int count = 0;
        int n = s.size();
        for (int r = 0; r < s.size(); r++) {
            if (s[r] == 'a')
                ca++;
            if (s[r] == 'b')
                cb++;
            if (s[r] == 'c')
                cc++;
            if (cc && ca && cb) {
                
                while (ca && cb && cc) {
                    count += n - r;
                    if (s[l] == 'a')
                        ca--;
                    if (s[l] == 'b')
                        cb--;
                    if (s[l] == 'c')
                        cc--;
                    l++;
                }
            }
        }
        return count;
    }
};