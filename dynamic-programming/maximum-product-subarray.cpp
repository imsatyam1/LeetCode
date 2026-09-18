class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() - 1;
        int product = INT_MIN;
        int prefixProduct = 1, suffixProduct = 1;

        for(int i=0; i<n; i++)
        {
            prefixProduct = prefixProduct * nums[i];
            suffixProduct = suffixProduct * nums[n-i];
            product = max(product, max(prefixProduct, suffixProduct));
        }

        return product;
    }
};