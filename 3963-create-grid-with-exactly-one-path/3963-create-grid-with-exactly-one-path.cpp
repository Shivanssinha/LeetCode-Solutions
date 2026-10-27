class Solution {
public:
    vector<string> createGrid(int m, int n) {
        int k = min(m, n);

        vector<string> s(m, string(n, '#'));

        int r = 0, c = 0;
        s[r][c] = '.';

        for (int i = 0; i < k - 1; i++) {
            s[r][c + 1] = '.';
            c++;

            s[r + 1][c] = '.';
            r++;
        }

        if (r == m - 1 && c == n - 1) {
            return s;
        }

        if (r == m - 1) {
            while (c < n - 1) {
                c++;
                s[r][c] = '.';
            }
        } else {
            while (r < m - 1) {
                r++;
                s[r][c] = '.';
            }
        }

        return s;
    }
};