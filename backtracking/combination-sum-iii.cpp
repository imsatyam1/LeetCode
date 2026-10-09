class Solution {
    void solve(
        int start,
        int k,
        int n,
        vector<int>& curr,
        vector<vector<int>>& result)
    {
        if(curr.size() == k) 
        {
            if(n == 0) result.push_back(curr);
        }

        for(int i=start; i<=9; i++)
        {
            if(i > n) break;

            curr.push_back(i);
            solve(i+1, k, n - i, curr, result);

            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> result;

        solve(1, k, n, curr, result);

        return result;
    }
};