class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int count = 0;

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int product = nums[i]* nums[j];

                mp[product]++;
            }
        }

        for(auto &it: mp){
            if(it.second > 1){
                count += it.second*(it.second-1)*4;
            }
        }

        return count;
    }
};