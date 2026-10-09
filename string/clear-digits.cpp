class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i]) && !st.empty()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string temp = "";

        while(!st.empty()){
            char ch = st.top();
            temp += ch;
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        return temp;
    }
};