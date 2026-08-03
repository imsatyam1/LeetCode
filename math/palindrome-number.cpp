class Solution {
public:
    int reverseNum(int x)
    {
        int newNum = 0;

        while(x != 0)
        {
            int rem = x%10;
            
            newNum = newNum*10+rem;
            x /= 10;
        }
        return newNum;
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;

        int newNum = reverseNum(x);
        if(newNum <= INT_MIN || newNum >= INT_MAX) return false;

        return x == newNum;
    }
};