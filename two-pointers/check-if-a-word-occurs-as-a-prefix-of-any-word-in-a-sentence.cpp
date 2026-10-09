class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word;
        stringstream ss(sentence);
        int i =0;
        while(ss >> word){
            i++;
            int j = 0;

            for(int k=0; k<word.length(); k++){
                while((j==k) && word[k] == searchWord[j]) j++;

                if(j== searchWord.length()) return i;
            }
        }
        return -1;
    }
};