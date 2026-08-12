class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int positive = 0, negative = 1;


        vector<int> result(n);

        for(int i=0; i<n; i++)
        {
            if(nums[i] < 0)
            {
                result[negative] = nums[i];
                negative += 2;
            }
            else
            {
                result[positive] = nums[i];
                positive += 2;
            }
        }

        return result;
    }
};