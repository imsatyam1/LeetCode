class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int preProduct = 1; 
        int suffixProduct = 1;
        
        int ans = INT_MIN;

        for(int i=0; i<nums.size(); i++)
        {
            if(preProduct == 0) preProduct = 1;
            if(suffixProduct == 0) suffixProduct = 1;

            preProduct *= nums[i];
            suffixProduct *= nums[nums.size() - i -1];

            ans = max(ans, max(preProduct, suffixProduct));
        }

        return ans;
    }
};