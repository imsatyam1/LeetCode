class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int rows = matrix.size();
        int columns = matrix[0].size();

        int startRow = 0, endRow = rows-1;
        int startCol = 0, endCol = columns-1;

        int count = 0;
        int total = rows*columns;

        while(count < total)
        {
            for(int i=startCol; count < total && i <= endCol; i++)
            {
                result.push_back(matrix[startRow][i]);
                count++;
            }

            startRow++;

            for(int i=startRow; count < total && i <= endRow; i++)
            {
                result.push_back(matrix[i][endCol]);
                count++;
            }

            endCol--;

            for(int i=endCol; count < total && i>=startCol; i--){
                result.push_back(matrix[endRow][i]);
                count++;
            }

            endRow--;

            for(int i=endRow; count < total && i>=startRow; i--){
                result.push_back(matrix[i][startCol]);
                count++;
            }

            startCol++;
        }

        return result;
    }
};