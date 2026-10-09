class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int target = 0;

        for(int num: nums){
            target = (target+num)%p;
        }

        if(target == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        int curr = 0;
        int result = n;

        for(int i=0; i<n; i++){
            curr = (curr+nums[i])%p;

            int prev = (curr - target + p)%p;

            if(mp.find(prev) != mp.end()){
                result = min(result, i-mp[prev]);
            }
            mp[curr] = i;
        }
        return result==n?-1:result;
    }
};