class Solution {
    int countSubset(int indx, int currOr, vector<int> &nums, int maxOr){
        if(indx == nums.size()){
            if(currOr == maxOr){
                return 1;
            }
            return 0;
        }

        int takeCount = countSubset(indx+1, currOr|nums[indx], nums, maxOr);

        int notTakeCount = countSubset(indx+1, currOr, nums, maxOr);

        return takeCount+ notTakeCount;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int &num : nums){
            maxOr |= num;
        }
        int currOr = 0;
        return countSubset(0, currOr, nums, maxOr);
    }
};