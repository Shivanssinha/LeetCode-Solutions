class Solution {
public:
    int sumsq(int n){
        int sum = 0;
        while(n>0){
            int digit = n%10;
            n = n/10;
            sum += digit*digit;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = sumsq(slow);
            fast = sumsq(sumsq(fast));
        }while(slow!= fast);
        return slow == 1;
    }
};