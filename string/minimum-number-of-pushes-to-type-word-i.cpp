class Solution {
public:
    int minimumPushes(string word) {
       int n = word.size();
        int ans = 8;

        if(n <= 8) return n;

        else if(n > 8  && n <= 16) 
        {
            int rem = n - 8;
            ans += rem*2;

            return ans;
        }

        else if(n > 16 && n <= 24)
        {
            ans = 24;
            int rem = n - 16;
            ans += rem *3;

            return ans;
        }

        else
        {
            ans = 48;

            int rem = n - 24;
            ans += rem *4;

            return ans;
        }

        return -1; 
    }
};