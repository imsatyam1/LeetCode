class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = INT_MIN;
        int prefixProduct = 1;
        int suffixProduct = 1;

        for(int i=0; i<nums.size(); i++)
        {
            if(prefixProduct == 0) prefixProduct = 1;
            if(suffixProduct == 0) suffixProduct = 1;

            prefixProduct *= nums[i];
            suffixProduct *= nums[nums.size() - 1 -i];

            product = max(product, max(prefixProduct, suffixProduct));
        }

        return product;
    }
};