public class Solution {
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

    public bool IsPalindrome(int x) {

        if(x < 0) return false;

        int newNum = reverseNum(x);
        if(newNum <= int.MinValue || newNum >= int.MaxValue) return false;

        return x == newNum;
    }
}