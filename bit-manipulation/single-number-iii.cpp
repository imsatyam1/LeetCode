class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;

        for (int num : nums) {
            xorAll ^= num;
        }

        unsigned int ux = static_cast<unsigned int>(xorAll);

        unsigned int diffBit = ux & (~ux + 1);

        int a = 0;
        int b = 0;

        for (int num : nums) {
            if (static_cast<unsigned int>(num) & diffBit) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};