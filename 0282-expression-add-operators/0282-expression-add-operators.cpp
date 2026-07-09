class Solution {
public:
    void solve(vector<string>& ans, string& path, string& num,
               int target, int index, long long currValue,
               long long prevOperand) {

        // Base case
        // If we've used all digits, check whether the expression
        // evaluates to the target.
        if (index == num.size()) {
            if (currValue == target)
                ans.push_back(path);
            return;
        }

        long long number = 0;

        // Save current path length so that we can backtrack easily.
        int len = path.size();

        // Try every possible number starting from 'index'
        for (int i = index; i < num.size(); i++) {

            // Prevent numbers like 05, 012, etc.
            if (i > index && num[index] == '0')
                break;

            // Form the current number
            number = number * 10 + (num[i] - '0');

            string currStr = num.substr(index, i - index + 1);

            // First number
            // It doesn't need an operator before it.
            if (index == 0) {

                path += currStr;

                solve(ans, path, num,
                      target,
                      i + 1,
                      number,
                      number);

                path.resize(len);
            }

            else {

                // '+' operator
                path += "+" + currStr;

                solve(ans, path, num,
                      target,
                      i + 1,
                      currValue + number,
                      number);

                path.resize(len);

                // '-' operator
                path += "-" + currStr;

                solve(ans, path, num,
                      target,
                      i + 1,
                      currValue - number,
                      -number);

                path.resize(len);

                // '*' operator
                path += "*" + currStr;

                solve(ans, path, num,
                      target,
                      i + 1,
                      currValue - prevOperand + prevOperand * number,
                      prevOperand * number);

                path.resize(len);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;
        string path;

        solve(ans, path, num, target, 0, 0, 0);

        return ans;
    }
};