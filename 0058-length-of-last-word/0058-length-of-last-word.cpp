class Solution {
public:
    int lengthOfLastWord(string s) {
        int k = s.length();
        int count = 0;

        if (s[k - 1] == ' ') {
            int flag = 0;

            for (int j = k - 1; j >= 0; j--) {
                if (s[j] != ' ') {
                    flag = 1;
                    count++;
                }
                if (s[j] == ' ' && flag == 1) {
                    break;
                }
            }
        } 
        else {
            for (int j = k - 1; j >= 0; j--) {
                if (s[j] == ' ') {
                    break;
                } else {
                    count++;
                }
            }
        }//uuuu

        return count;
    }
};