class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        while(i < n && s[i] == ' ') i++;

        int sign = 1;

        if(i < n && (s[i] == '-' || s[i] == '+'))
        {
            if(s[i] == '-') sign = -1;
            i++;
        }

        long long sum = 0;

        while(i < n)
        {
            if(isdigit(s[i]))
            {
                int digit = s[i] - '0';

                if (sum > (INT_MAX - digit) / 10) {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

                sum = sum*10 + digit;
                i++;
            }
            else 
            {
                break;
            }
        }

        return (int)sum*sign;
    }
};