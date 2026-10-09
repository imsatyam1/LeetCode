class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int value = abs(nums[i]);
            if(nums[value] < 0){
                return abs(nums[i]);
            }
            else{
                nums[value] = -1* nums[value];
            }
        }
        return -1;
    }
};