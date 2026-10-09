class Solution {
public:
    long long minimumSteps(string s) {
        long long black = 0, swap =0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '0') swap += black;
            else black++;
        }
        return swap;
    }
};