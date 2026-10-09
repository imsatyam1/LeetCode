class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;

        int n = pref.length();

        for(string &word:words){
            for(int i=0; i<n; i++){
                if(word[i] != pref[i]) break;

                if(i==n-1 && word[i] == pref[i]){
                    count++;
                }
            }
        }
        return count;
    }
};