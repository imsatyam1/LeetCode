class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word_comb1 = "";
        string word_comb2 = "";

        for(string word : word1){
            word_comb1 += word;
        }

        for(string word : word2){
            word_comb2 += word;
        }

        if(word_comb1.length() != word_comb2.length()){
            return false;
        }

        for(int i=0; i<word_comb1.length(); i++){
            if(word_comb1[i] != word_comb2[i]){
                return false;
            }
        }
        return true;
    }
};