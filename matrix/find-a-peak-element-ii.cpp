class Solution {
public:
    int findMaxIndx(vector<vector<int>> &mat, int n, int m, int col){
        int maxValue = -1;
        int indx = -1;
        for(int i=0; i<n; i++){
            if(mat[i][col] > maxValue){
                maxValue = mat[i][col];
                indx = i;
            }
        }
        return indx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m-1;

        while(low <= high){
            int mid = (low+high)/2;
            int maxRowIndx = findMaxIndx(mat, n, m, mid);
            int left = mid-1 >= 0 ? mat[maxRowIndx][mid-1]:-1;
            int right = mid+1 < m ? mat[maxRowIndx][mid+1]:-1;

            if(mat[maxRowIndx][mid] > left && mat[maxRowIndx][mid] > right){
                return {maxRowIndx, mid};
            }
            else if(mat[maxRowIndx][mid]  < left){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {-1,-1};
    }
};