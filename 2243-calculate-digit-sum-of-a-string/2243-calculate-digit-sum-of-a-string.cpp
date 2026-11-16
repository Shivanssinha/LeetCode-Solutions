class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k) {
            string x = "";
            int sum = 0;
            int j = 0;

            for(int i = 0; i < s.length(); i++) {
                sum += s[i] - '0';
                j++;

                if(j == k) {
                    x += to_string(sum);
                    sum = 0;
                    j = 0;
                }
            }

            if(j > 0) {
                x += to_string(sum);
            }

            s = x;
        }

        return s;
    }
};