class Solution {
    int func(vector<int> nums, int k){
        if(k<0) return 0;
        int i=0, j=0, count =0, sum =0, n= nums.size();

        while(j<n){
            sum += (nums[j]%2);

            while(sum >k){
                sum -= nums[i]%2;
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k-1);
    }
};