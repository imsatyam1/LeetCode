public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        int row = matrix.Length;
        int col = matrix[0].Length;

        int rowIndx = 0;
        int colIndx = col-1;

        while(rowIndx < row && colIndx >= 0)
        {
            int element = matrix[rowIndx][colIndx];
            if(element == target) return true;
            else if(element < target) rowIndx++;
            else colIndx--;
        }
        return false;
    }
}