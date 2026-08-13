class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        int c5 = 0, c10 = 0;

        for(int j = 0; j < b.size(); j++) {
            if(b[j] == 5) {
                c5++;
            }
            else if(b[j] == 10) {
                if(c5 == 0) return false;
                c5--;
                c10++;
            }
            else {
                if(c10 > 0 && c5 > 0) {
                    c10--;
                    c5--;
                }
                else if(c5 >= 3) {
                    c5 -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};