class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        // Edge case
        if (m > n) return -1;

        for (int i = 0; i <= n - m; ++i) {
            // compare instead of substr (more efficient)
            if (haystack.compare(i, m, needle) == 0) {
                return i;
            }
        }
        return -1;
    }
};