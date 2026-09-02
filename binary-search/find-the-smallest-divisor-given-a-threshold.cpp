class Solution {
    bool isPossible(vector<int>& nums, int threshold, int mid)
    {
        int n = nums.size();
        int sum = 0;

        for(int i=0; i<n; i++)
        {
            sum += nums[i]/mid;
            if(nums[i]%mid != 0) sum++;
        }

        return (sum <= threshold);  
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        if(n == 1) return nums[0];
        if(threshold == n) return high;

        while(low < high)
        {
            int mid = low + (high - low)/2;

            if(isPossible(nums, threshold, mid)) high = mid;
            else low = mid+1;
        }
        return low;
    }
};