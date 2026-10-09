class Solution {
    void solve(string curr, int n, int open, int close, vector<string> &result)
    {
        if(curr.length() == 2*n)
        {
            result.push_back(curr);
            return;
        }

        if(open < n)
        {
            curr.push_back('(');
            solve(curr, n, open+1, close, result);
            curr.pop_back();
        }

        if(close < open)
        {
            curr.push_back(')');
            solve(curr, n, open, close+1, result);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        int open = 0;
        int close = 0;

        string curr = "";

        solve(curr, n, open, close, result);

        return result;
    }
};