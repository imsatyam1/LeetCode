class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int MIN = INT_MAX;
        int MAX = INT_MIN;

        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                MIN = min(MIN, nums[i]);
            }
        }

        for(int i=n-2; i>=0; i--){
            if(nums[i] > nums[i+1]){
                MAX = max(MAX, nums[i]);
            }
        }

        int start = 0;
        for(int i=0; i<n; i++){
            if(nums[i] > MIN){
                start = i;
                break;
            }
        }

        int end = 0;
        for(int i=n-1; i>=0; i--){
            if(nums[i] < MAX){
                end = i;
                break;
            }
        }

        return (end - start)<=0?0:end-start+1;
    }
};