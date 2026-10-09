class Solution {
    bool check(vector<string>& Board, int row, int col, int n)
    {
        int i= row;
        int j = col;

        while(i>-1 && j>-1)
        {
            if(Board[i][j] == 'Q') return false;

            i--;
            j--;
        }

        i = row;
        j = col;

        while(i>-1 && j<n)
        {
            if(Board[i][j] == 'Q') return false;

            i--;
            j++;
        }

        return true;
    }
    void solve(
        int row,
        int n,
        vector<vector<string>>& ans,
        vector<string>& Board,
        vector<bool>& column
    )
    {
        // Base case
        if (row == n)
        {
            ans.push_back(Board);
            return;
        }

        // Try every column
        for (int j = 0; j < n; j++)
        {
            if (column[j] == 0 && check(Board, row, j, n))
            {
                // Choose
                column[j] = 1;
                Board[row][j] = 'Q';

                // Explore
                solve(
                    row + 1,
                    n,
                    ans,
                    Board,
                    column
                );

                // Backtrack
                column[j] = 0;
                Board[row][j] = '.';
            }
        }
    }

public:

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;

        vector<string> Board(
            n,
            string(n, '.')
        );

        vector<bool> column(n, false);

        vector<bool> LeftDig(
            2 * n - 1,
            false
        );

        vector<bool> RightDig(
            2 * n - 1,
            false
        );

        solve(
            0,
            n,
            ans,
            Board,
            column
        );

        return ans;
    }
};