class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        string str = "";
        for(char ch: num){
            while(!st.empty() && k>0 && st.top() > ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        
        while(k >0 && !st.empty()){
            st.pop();
            k--;
        }

        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());

        int i =0;
        while(i<str.size() && str[i] == '0'){
            i++;
        }

        str = str.substr(i);

        if(str.size() == 0) return "0";

        return str;
    }
};