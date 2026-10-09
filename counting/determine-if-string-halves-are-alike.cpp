class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0;
        int count2 = 0;

        for(int i=0; i< s.length()/2; i++){
            if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e'|| tolower(s[i]) == 'i'|| tolower(s[i]) == 'o' || tolower(s[i]) == 'u'){
                count1++;
            }
        }

        for(int i=s.length()/2; i< s.length(); i++){
            if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e'|| tolower(s[i]) == 'i'|| tolower(s[i]) == 'o' || tolower(s[i]) == 'u'){
                count2++;
            }
        }

        if(count1 == count2){
            return true;
        }
        return false;
    }
};