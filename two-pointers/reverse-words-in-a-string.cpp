class Solution {
public:
    string reverseWords(string s) {
        int n = s.size() - 1;
        string ans = "";

        int i = s.size() -1;

        while(i >= 0)
        {
            while(i >= 0 && s[i] == ' ') i--;

            if(i <  0) break;

            int j = i;

            while(i>= 0 && s[i] != ' ') i--;

            ans += s.substr(i+1, j-i);
            ans += ' ';
        }

        return ans.substr(0, ans.size() - 1);
    }
};