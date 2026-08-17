class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i=0; i<n-2; i++)
        {
            int left = i+1, right = n-1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    int leftVal = nums[left];
                    while(left < right && nums[left] == leftVal) left++;
                    
                    int rightVal = nums[right];
                    while(left < right && nums[right] == rightVal) right--;
                }
                else if(sum < 0) left++;
                else right--;
            }

            while(i < n-2 && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};