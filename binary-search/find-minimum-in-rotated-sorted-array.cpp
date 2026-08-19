class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(nums[0] < nums[n-1]) return nums[0];

        int start = 0, end = n-1;

        while(start < end)
        {
            int mid = start  + (end - start)/2;

            if(nums[mid] > nums[end]) start = mid+1;
            else end = mid;
        }

        return nums[start];
    }
};