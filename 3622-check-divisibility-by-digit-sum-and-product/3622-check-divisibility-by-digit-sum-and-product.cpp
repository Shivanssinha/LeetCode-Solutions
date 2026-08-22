class Solution {
public:
    bool checkDivisibility(int n) {
        int sum1 = 0,mult1 =  1;
        int n1 = n;
        while(n){
            int dig = n%10;
            sum1 = sum1 + dig;
            mult1 = mult1 * dig;
            n = n/10;
        }
        return n1%(sum1 + mult1) == 0;
        
    }
};