class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        bool negative = (dividend < 0) ^ (divisor < 0);
        long long divi = llabs((long long)dividend);
        long long sor  = llabs((long long)divisor);
        long long q = 0;
        for(int i = 31;i>=0;i--){
            if((sor<<i) <= divi){
                q += (1LL<<i);
                divi -= (sor<<i);
            }
        }
        if(negative){
            q = -q;
        }
        return (int)q;
    }
};
