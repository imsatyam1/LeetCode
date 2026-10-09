class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, size = 0;
        for(char ch: s){
            if(ch == '('){
                open++;
                size++;
            }
            else if(open > 0 && ch == ')'){
                open--;
                size--;
            }
            else{
                size++;
            }
        }
        return size;
    }
};