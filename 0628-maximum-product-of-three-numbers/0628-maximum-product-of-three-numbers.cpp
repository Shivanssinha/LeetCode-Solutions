class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int larg1 = INT_MIN, larg2 = INT_MIN, larg3 = INT_MIN;
        int ch1 = INT_MAX, ch2 = INT_MAX;

        for (int a : nums) {
            if (a > larg1) {
                larg3 = larg2;
                larg2 = larg1;
                larg1 = a;
            }
            else if (a > larg2) {
                larg3 = larg2;
                larg2 = a;
            }
            else if (a > larg3) {
                larg3 = a;
            }
            if (a < ch1) {
                ch2 = ch1;
                ch1 = a;
            }
            else if (a < ch2) {
                ch2 = a;
            }
        }

        return max(larg1 * larg2 * larg3,
                   ch1 * ch2 * larg1);
    }
};