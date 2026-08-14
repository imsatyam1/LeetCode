class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1 = -1, vote1 = 0;
        int candidate2 = -1, vote2 = 0;

        for(int i=0; i<n; i++)
        {
            if(vote1 == 0 && nums[i] != candidate2)
            {
                candidate1 = nums[i];
                vote1 = 1;
            }
            else if(vote2 == 0 && nums[i] != candidate1)
            {
                candidate2 = nums[i];
                vote2 = 1;
            }
            else if(nums[i] == candidate1) vote1++;
            else if(nums[i] == candidate2) vote2++;
            else
            {
                vote1--;
                vote2--;
            }
        }

        vote1 = 0, vote2 = 0;
        vector<int> result;

        for(int i=0; i<n; i++)
        {
            if(nums[i] == candidate1) vote1++;
            else if(nums[i] == candidate2) vote2++;
        }

        if(vote1 > n/3) result.push_back(candidate1);
        if(vote2 > n/3) result.push_back(candidate2);

        return result;
    }
};