class Solution {
    long long power(long long base, long long exp)
    {
        const long long MOD = 1e9+7;
        long long ans = 1;

        while(exp > 0)
        {
            if(exp % 2 == 1)
            {
                ans = (ans * base) % MOD;
            }

            base = (base * base)%MOD;
            exp /= 2;
        }

        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        const long long MOD = 1e9+7;

        long long evenIndx = (n+1)/2;
        long long oddIndx = (n)/2;

        long long evenWays = power(5, evenIndx);
        long long oddWays = power(4, oddIndx);

        return (evenWays * oddWays)%MOD;
    }
};