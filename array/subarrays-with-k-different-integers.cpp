class Solution {
    int func(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int i=0, j = 0,count = 0, n = nums.size();

        while(j<n){
            mp[nums[j]]++;

            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k-1);
    }
};