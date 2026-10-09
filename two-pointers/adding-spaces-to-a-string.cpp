class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i=0, j=0;

        int n = s.length();
        int m = spaces.size();

        string newStr = "";

        while(i< n && j<m){
            if(i == spaces[j]){
                newStr += " ";
                j++;
            }
            else{
                newStr += s[i];
                i++;
            }
        }
        while(i<n){
            newStr += s[i];
            i++;
        }
        return newStr;
    }
};