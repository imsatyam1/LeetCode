class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closet_sum = INT_MAX/2;

        for(int i=0; i<n-2; i++){
            int left = i+1, right = n-1;
            while(left < right){
                int curr_sum = nums[i]+ nums[left] + nums[right];

            if(abs(target - curr_sum) < abs(closet_sum - target)){
                closet_sum = curr_sum;
            }
            
            if(curr_sum < target) left++;
            else if(curr_sum > target) right--;
            else return curr_sum;
            }
        }
        return closet_sum;
    }
};