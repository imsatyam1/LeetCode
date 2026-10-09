class Solution {
    private List<Integer> genrateRows(int row)
    {
        int ans = 1;
        List<Integer> temp = new ArrayList<Integer>();
        temp.add(1);

        for(int col=1; col<row; col++)
        {
            ans *= row-col;
            ans /= col;
            temp.add(ans);
        }

        return temp;
    }
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();

        for(int row=1; row<=numRows; row++)
        {
            List<Integer> temp = new ArrayList<Integer>();

            temp = genrateRows(row);
            result.add(temp);
        }

        return result;
    }
}