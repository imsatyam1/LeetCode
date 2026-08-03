public class Solution {
    public int Reverse(int x) {
        int temp = x;
        long ans = 0;

        while(temp != 0)
        {
            int rem = temp%10;
            ans = ans*10+rem;

            temp /=10;
        }
        return (ans >= int.MaxValue || ans <= int.MinValue) ? 0 : (int)ans;
    }
}