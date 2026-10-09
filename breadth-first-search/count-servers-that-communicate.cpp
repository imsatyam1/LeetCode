class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int result = 0;

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == 1){
                    bool canCommunicate = false;

                    for(int otherCol = 0; otherCol < m; otherCol++){
                        if(otherCol != col && grid[row][otherCol] == 1){
                            canCommunicate = true;
                            break;
                        }
                    }
                    if(canCommunicate){
                        result++;
                    }
                    else{
                        for(int otherRow = 0; otherRow < n; otherRow++){
                            if(otherRow != row && grid[otherRow][col] == 1){
                                canCommunicate = true;
                                break;
                            }
                        }
                        if(canCommunicate) result++;
                    }
                }
            }
        }
        return result;
    }
};