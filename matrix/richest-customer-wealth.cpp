class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[0].size();

        int maxWealth = INT_MIN;

        for(int i=0; i<n; i++)
        {
            int sum = 0;

            for(int j=0; j<m; j++)
            {
                sum += accounts[i][j];
            }

            maxWealth = max(maxWealth, sum);
        }

        return maxWealth;
    }
};