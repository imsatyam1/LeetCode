class Solution {
public:
    int reverse(int x) {
        int temp = x;
        long ans = 0;

        while(temp != 0)
        {
            int rem = temp%10;
            ans = ans*10+rem;
            temp /= 10;
        }

        return (ans >= INT_MAX || ans <= INT_MIN) ? 0 : (int)ans;
    }
};