class Solution {
    int func(vector<int>& nums, int goal){
        if(goal < 0)return 0;
        int i=0, j=0, count =0, sum =0, n = nums.size();

        while(j<n){
            sum += nums[j];
            while(sum > goal){
                sum -= nums[i];
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums, goal) - func(nums, goal-1);
    }
};