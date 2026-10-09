class Solution {
public:
    string makeFancyString(string s) {
       int count = 1;
       string newStr;
       newStr += s[0];

       for(int i=1; i<s.length(); i++){
            if(s[i-1] == s[i]) count++;
            else count = 1;
            if(count < 3) newStr += s[i]; 
       }
       return newStr;
    }
};