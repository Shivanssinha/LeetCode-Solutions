class Solution {
public:
    bool isPal(string s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void func(vector<vector<string>>& ans, vector<string>& p, int index,
              string s) {

        if (index == s.length()) {
            ans.push_back(p);
            return;
        }

        for (int i = index; i < s.length(); i++) {

            if (isPal(s, index, i)) {

                p.push_back(s.substr(index, i - index + 1));
                func(ans, p, i + 1, s);

                p.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> p;

        func(ans, p, 0, s);

        return ans;
    }
};