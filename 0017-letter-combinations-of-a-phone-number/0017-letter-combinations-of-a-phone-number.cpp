class Solution {
public:
    vector<string> mp = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void solve(int index, string &digits, string &curr,
               vector<string> &ans) {
        if (index == digits.size()) {
            ans.push_back(curr);
            return;
        }

        int digit = digits[index] - '0';

        for (char ch : mp[digit]) {
            curr.push_back(ch);          
            solve(index + 1, digits, curr, ans);
            curr.pop_back();               
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if (digits.empty())
            return ans;

        string curr;

        solve(0, digits, curr, ans);

        return ans;
    }
};