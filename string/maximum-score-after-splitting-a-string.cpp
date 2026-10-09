class Solution {
public:
    int maxScore(string s) {
        int zero = 0,  ones = 0;;
        int n = s.length();

        for(int i=0; i<n; i++){
            if(s[i] == '0') zero++;
            else ones++;
        }

        if(ones == 0) return (zero -1);

        int count = 0;
        int maxCount = 0;

        for(int i=0; i<n-1; i++){
            if(s[i] == '0') count++;
            else ones--;

            maxCount = max(maxCount, count+ ones);
        }

        return maxCount;
    }
};