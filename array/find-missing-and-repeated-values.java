class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int req_num = (int)Math.pow(n, 2);
        long totalSum = (long)(req_num * (req_num + 1))/2;
        
        int xor = 0;
        int extra = 0;
        long sum = 0;

        int[] freq = new int[req_num+1];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                sum += grid[i][j];

                if(freq[grid[i][j]] == 1) extra = grid[i][j];
                else freq[grid[i][j]] = 1;
            }
        }

        int missing = (int)(totalSum - (sum -extra));

        int[] result = new int[2];
        result[0] = extra;
        result[1] = missing;
        return result;
    }
}