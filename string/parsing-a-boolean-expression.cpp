class Solution {
    char solveOp(char op, vector<char> &vec){
        if(op == '!') return vec[0] == 't'?'f':'t';

        if(op == '|'){
            for(char &ch: vec){
                if(ch == 't') return 't';
            }
            return 'f';
        }
        if(op == '&'){
            for(char &ch: vec){
                if(ch == 'f') return 'f';
            }
            return 't';
        }
        return 't';
    }
public:
    bool parseBoolExpr(string expression) {
        int n = expression.length();
        stack<char> st;

        for(int i=0; i<n; i++){
            if(expression[i] == ',') continue;

            if(expression[i] == ')'){
                vector<char> vec;
                while(st.top() != '('){
                    vec.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                st.push(solveOp(op, vec));
            }
            else{
                st.push(expression[i]);
            }
        }
        return (st.top() == 't');
    }
};