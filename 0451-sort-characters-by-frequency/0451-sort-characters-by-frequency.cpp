class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128, 0);
        for (char c : s) {
            freq[c]++;
        }
        vector<pair<int, char>> p;
        for (int i = 0; i < 128; i++) {
            if (freq[i]) {
                p.push_back({freq[i], (char)i});
            }
        }
        sort(p.rbegin(), p.rend());
        string ans = "";

        for (auto k : p) {
            int count = k.first;
            char ch = k.second;

            while (count--) {
                ans += ch;
            }
        }
        return ans;
    }
};