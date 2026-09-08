class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long larg = LLONG_MIN;
        long long slarg = LLONG_MIN;
        long long tlarg = LLONG_MIN;

        for (int x : nums) {
            // Ignore duplicates
            if (x == larg || x == slarg || x == tlarg) {
                continue;
            }

            if (x > larg) {
                tlarg = slarg;
                slarg = larg;
                larg = x;
            }
            else if (x > slarg) {
                tlarg = slarg;
                slarg = x;
            }
            else if (x > tlarg) {
                tlarg = x;
            }
        }

        if (tlarg == LLONG_MIN) {
            return larg;
        }

        return tlarg;
    }
};