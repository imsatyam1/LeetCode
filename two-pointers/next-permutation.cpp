class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int flag = -1;

        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] < nums[n-1]) flag = i;
            break;
        }

        if(flag == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        swap(nums[flag], nums[n-1]);

        reverse(nums.begin()+flag+1, nums.end());
    }
};