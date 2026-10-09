class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        vector<int> vec(m);

        for(int j=1; j<n; j++){
            int leftTop = 0;
            bool found = false;

            for(int i=0; i<m; i++){
                int curr = -1;
                int nxtLeftTop = vec[i];

                if(i-1>= 0 && leftTop != -1 && grid[i][j] > grid[i-1][j-1]){
                    curr = max(curr, leftTop+1);
                }
                if(vec[i] != -1 && grid[i][j] > grid[i][j-1]){
                    curr = max(curr, vec[i]+1);
                }
                if(i+1 < m && vec[i+1] != -1 && grid[i][j] > grid[i+1][j-1]){
                    curr = max(curr, vec[i+1] + 1);
                }
                vec[i] = curr;
                found = found || (vec[i] != -1);
                leftTop = nxtLeftTop; 
            }
            if(!found) break;
            res = j;
        }
        return res;
    }
};