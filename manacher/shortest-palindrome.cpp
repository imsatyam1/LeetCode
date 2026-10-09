class Solution {
public:
    void computeLSP(string pattern, vector<int> &LSP){
        int M = pattern.length();
        int i =1;
        int len = 0;
        LSP[0] = 0;
        while(i<M){
            if(pattern[i] == pattern[len]){
                len++;
                LSP[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = LSP[len-1];
                }
                else{
                    LSP[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));
        string temp =s+'-'+rev;
        vector<int> LSP(temp.length(), 0);
        computeLSP(temp, LSP);
        int longeststr = LSP[temp.length()-1];
        string culprit = rev.substr(0, s.length() - longeststr);
        return culprit+s;
    }
};