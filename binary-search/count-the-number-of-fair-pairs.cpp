class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        long long count = 0;

        for(int i=0; i<n; i++){
            int indx = lower_bound(nums.begin()+1+i, nums.end(), lower-nums[i]) - nums.begin();
            int x = indx - i -1;

            indx = upper_bound(nums.begin()+1+i, nums.end(), upper - nums[i]) - nums.begin();
            int y = indx - 1 -i;

            count += (y-x);
        }
        return count;
    }
};