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
                sum = sum*10 + digit;
                i++;
            }
            else 
            {
                break;
            }
        }

        if(sign * sum < INT_MIN) return INT_MIN;
        if(sign * sum > INT_MAX) return INT_MAX;

        return (int)sum*sign;
    }
};