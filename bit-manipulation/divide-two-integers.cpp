class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool isPositive = true;

        if(dividend >= 0 && divisor<0) isPositive = false;
        else if(dividend <= 0 && divisor > 0) isPositive = false;

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long quotient = 0;

        while(n >= d)
        {
            int cnt = 0;

            while(n >= (d << (cnt + 1))) cnt += 1;

            quotient +=  1 << cnt;
            n -= ( d<< cnt);
        }

        if(quotient == (1 << 31) && isPositive) return INT_MAX;

        if(quotient == (1 << 31) && !isPositive) return INT_MIN;
         
        return isPositive?quotient:-quotient;
    }
};