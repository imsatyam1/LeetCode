class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = strs[0];

        if(n == 1) return ans;

        for(string &s: strs)
        {
            int i = 0;

            if(s[0] != ans[0]) return "";

            while(i< s.size() && s[i] == ans[i]) i++;

            ans = ans.substr(0, i);
        }

        return ans;
    }
};