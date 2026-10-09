class Solution {
    void solve(vector<int>& candidates, int target, int index, vector<int>& curr, vector<vector<int>>& result)
    {
        if(target == 0) 
        {
            result.push_back(curr);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            solve(candidates, target - candidates[i], i + 1, curr,result);

            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        vector<vector<int>> result;
        solve(candidates, target, 0, curr, result);

        return result;
    }
};