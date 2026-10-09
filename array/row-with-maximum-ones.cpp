class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int row = 0, no_of_one = 0;

        for(int i=0; i<n; i++){
            int one_count = 0;
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1) one_count++;
            }
            if(one_count > no_of_one){
                no_of_one = one_count;
                row = i;
            }
        }
        return {row, no_of_one};
    }
};