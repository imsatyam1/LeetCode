class Solution {
public:
    int maximumCount(vector<int>& nums) {
          int n = nums.size();
          int pCount = 0;
          int nCount = 0;
          int low = 0;
          int high = n-1;

          if(n <= 1){
            if(nums[0] == 0){
                return 0;
            }
            return n;
          }

          while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] < 0){
                nCount = mid+1;
                low = mid+1;
            }
            else if(nums[mid] > 0){
                pCount = n-mid;
                high = mid-1;
            }
            else{
                if(nums[mid-1] < 0) nCount = mid;
                low = mid+1;
            }
          }
        return max(nCount, pCount);
    }
};