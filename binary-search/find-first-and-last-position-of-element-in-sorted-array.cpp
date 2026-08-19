class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n-1;
        vector<int> ans(2, -1);

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(nums[mid] == target)
            {
                int temp = mid;
                while(temp >= -1 && nums[temp] == target) temp--;
                ans[0] = temp+1;
                temp = mid;
                while(temp <= n+1 && nums[temp] == target) temp++;
                ans[1] = temp-1;
                return ans;
            }
            else if(nums[mid] < target) start = mid + 1;
            else end = mid-1;
        }
        return ans;
    }
};