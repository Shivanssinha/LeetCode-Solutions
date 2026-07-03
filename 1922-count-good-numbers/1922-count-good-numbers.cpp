class Solution {
public:
    const long long k = 1e9 + 7;
    long long power(long long b,long long n){
        if(n == 0){
            return 1;
        }
        long long half = power(b,n/2) ;
        long long ans = (half * half) %k;
        if(n % 2 == 1){
            ans = (ans * b)%k;
        }
        return ans;

    }
    int countGoodNumbers(long long n) {
        long long e = (n%2 == 0)? n/2 : (n/2) + 1;
        long long o = n/2;
        return (power(4,o) * power(5,e)) % k;
    }
};