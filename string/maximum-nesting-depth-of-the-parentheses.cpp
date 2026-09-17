class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int depth = 0;

        for(char &ch: s)
        {
            if(ch == '(')
            {
                depth++;
            }
            else if(depth > 0 && ch == ')')
            {
                ans = max(ans, depth);
                depth--;
            }
        }

        return ans;
    }
};