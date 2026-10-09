class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;

        for(char &ch: allowed){
            mask |= 1 << (ch-'a');
        }

        int count = 0;

        for(string &word : words){
            bool allChar = true;
            for(int i=0; i<word.length(); i++){
                if(((mask >> (word[i] - 'a')) & 1) == 0){
                    allChar = false;
                    break;
                }
            }
            count += allChar;
        }
        return count;
    }
};