    
class Solution {
public:
    int dm(string s, int days[]) {
        int m = (s[0] - '0') * 10 + (s[1] - '0');
        int d = (s[3] - '0') * 10 + (s[4] - '0');

        int sum = d;
        if (m > 1) {
            sum += days[m - 2];
        }

        return sum;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int days[] = {31, 59, 90, 120, 151, 181,
                      212, 243, 273, 304, 334, 365};

        int aa = dm(arriveAlice, days);
        int la = dm(leaveAlice, days);
        int ab = dm(arriveBob, days);
        int lb = dm(leaveBob, days);

        if (la < ab || lb < aa) {
            return 0;
        }

        int start = max(aa, ab);
        int end = min(la, lb);

        return end - start + 1;
    }
};

