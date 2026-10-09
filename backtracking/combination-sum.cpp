class Solution {
    void solve(vector<int>& candidates, int target, int index, vector<int>& curr, vector<vector<int>>& result)
    {
        if(target == 0) 
        {
            result.push_back(curr);
            return;
        }

        if(index == candidates.size() || candidates[index] > target) return;

        curr.push_back(candidates[index]);
        solve(candidates, target - candidates[index], index, curr, result);

        curr.pop_back();
        solve(candidates, target, index + 1, curr, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> curr;
        vector<vector<int>> result;
        solve(candidates, target, 0, curr, result);

        return result;
    }
};