class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> parityDiff(n, 0);

        // Precompute parity differences
        for (int i = 1; i < n; ++i) {
            parityDiff[i] = (nums[i] % 2 != nums[i - 1] % 2) ? 1 : 0;
        }

        // Prefix sum of parityDiff
        vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + parityDiff[i];
        }

        // Answer queries
        vector<bool> answer;
        for (const auto& query : queries) {
            int from = query[0];
            int to = query[1];

            // Special condition if subarray has only one element
            if (from == to) {
                answer.push_back(true);
                continue;
            }

            // Check if the sum of parityDiff in the range matches the expected
            int rangeSum = prefixSum[to] - prefixSum[from];
            answer.push_back(rangeSum == (to - from));
        }

        return answer;
    }
};
