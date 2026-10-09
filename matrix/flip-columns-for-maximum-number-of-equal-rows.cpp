class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> mp;
        
        for(auto &row: matrix){
            string s = "";
            int firstVal = row[0];
            for(int i=0; i<n; i++){
                s += (row[i] == firstVal)?'S':'B';
            }
            mp[s]++;
        }

        int maxRow = 0;
        for(auto &it: mp){
            maxRow = max(maxRow, it.second);
        }
        return maxRow;
    }
};