class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();  
        int i=0, j = 0, sum = 0, score = 0;
        unordered_map<int, int> count;

        while(j<n){
            while(!count.empty() && count.find(nums[j]) != count.end()){
                sum -= nums[i];
                count.erase(nums[i]);
                i++;
            }
            count[nums[j]]++;
            sum += nums[j];
            score = max(score, sum);

            j++;
        }
        return score;
    }
};