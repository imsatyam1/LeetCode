class Solution {
    void solve(vector<int>& nums, int index, vector<int>& temp, vector<vector<int>>& ans)
    {
        ans.push_back(temp);

        for(int i=index; i<nums.size(); i++)
        {
            if(i > index && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            solve(nums, i+1, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<int> temp;
        vector<vector<int>> ans;

        solve(nums, 0, temp, ans);

        return ans;
    }
};