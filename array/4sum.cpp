class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-3; i++)
        {
            for(int j=i+1; j<n-2; j++)
            {
                int left = j+1, right = n-1;

                while(left < right)
                {
                    long long sum = 1LL * (nums[i] + nums[j] + nums[left] + nums[right]);

                    if(sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        int leftVal = nums[left];
                        while(left < right && nums[left] == leftVal) left++;

                        int rightVal = nums[right];
                        while(left < right && nums[right] == rightVal) right--;
                    }
                    else if(sum < target) left++;
                    else right--;
                }
                while(j < n-2 && nums[j] == nums[j+1]) j++;
            }
            while(i < n-3 && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};