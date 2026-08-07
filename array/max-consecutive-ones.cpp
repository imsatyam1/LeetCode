class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int count = 0;

        for(int i: nums)
        {
            if(i == 1) count++;
            else
            {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }

        maxCount = max(maxCount, count);
        return maxCount;
    }
};