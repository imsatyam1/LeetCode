class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1, vote = 0;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(vote == 0)
            {
                candidate = nums[i];
                vote++;
            }
            else if(nums[i] == candidate) vote++;
            else vote--;
        }

        return candidate;
    }
};