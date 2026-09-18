class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() - 1;
        int product = INT_MIN;
        int prefixProduct = 1, suffixProduct = 1;

        for(int i=0; i<nums.size(); i++)
        {
            if(prefixProduct == 0) prefixProduct = 1;
            if(suffixProduct == 0) suffixProduct = 1;
            
            prefixProduct = prefixProduct * nums[i];
            suffixProduct = suffixProduct * nums[n-i];
            product = max(product, max(prefixProduct, suffixProduct));
        }

        return product;
    }
};