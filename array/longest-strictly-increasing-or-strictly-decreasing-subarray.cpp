class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxCount = 1;
        int count = 1;
        int maxInc = 1;
        int maxDec = 1;

        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]) count++;
            else{
                maxInc = max(maxInc, count);
                count =1;
            }
        }

        maxInc = max(maxInc, count);
        maxCount = max(maxCount, maxInc);
        count = 1;

        for(int i=1; i<n; i++){
            if(nums[i-1] > nums[i]) count++;
            else{
                maxDec = max(maxDec, count);
                count =1;
            }
        }

        maxDec = max(maxDec, count);
        maxCount = max(maxCount, maxDec);
        return maxCount;
    }
};