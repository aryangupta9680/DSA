// First Method
class Solution {
public:
    bool check(int n, vector<string>&Board, int i, int j)
    {
        // upper left diagonal
        int row = i, col = j;
        while(row>-1 && col>-1)
        {
            if(Board[row][col] == 'Q')
            {
                return 0;
            }
            row--, col--;
        }

        // upper right diagonal
        row = i, col = j;
        while(row>-1 && col < n)
        {
            if(Board[row][col] == 'Q')
            {
                return 0;
            }
            row--, col++;
        }

        return 1;
    }

    void find(int row, int n, vector<vector<string>>&ans, vector<string>&Board, vector<bool>&column)
    {
        // Base condition
        if(row==n)
        {
            ans.push_back(Board);
            return;
        }

        // put queen at any n position
        for(int j = 0; j < n;j++)
        {
            if(column[j]==0 && check(n, Board, row, j))
            {
                column[j] = 1;
                Board[row][j] = 'Q';
                find(row+1, n, ans, Board, column);
                column[j] = 0;
                Board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>Board(n);
        for(int i = 0; i < n;i++)
        {
            for(int j = 0; j < n;j++)
            {
                Board[i].push_back('.');
            }
        }

        vector<bool>column(n, 0);

        find(0, n, ans, Board, column);
        return ans;
    }
};





// Second Method
class Solution {
public:
    void find(int row, int n, vector<vector<string>>&ans, vector<string>&Board, vector<bool>&column, vector<bool>&LeftDiagonal, vector<bool>&RightDiagonal)
    {
        // Base condition
        if(row==n)
        {
            ans.push_back(Board);
            return;
        }

        // put queen at any n position
        // LeftDiagonal = n-1 + col-row
        // RightDiagonal = row + col
        for(int j = 0; j < n;j++)
        {
            if(column[j]==0 && LeftDiagonal[n-1 + j-row]==0 && RightDiagonal[row + j]==0)
            {
                column[j] = 1;
                Board[row][j] = 'Q';
                LeftDiagonal[n-1 + j-row] = 1;
                RightDiagonal[row + j] = 1;
                find(row+1, n, ans, Board, column, LeftDiagonal, RightDiagonal);
                column[j] = 0;
                Board[row][j] = '.';
                LeftDiagonal[n-1 + j-row] = 0;
                RightDiagonal[row + j] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>Board(n);
        for(int i = 0; i < n;i++)
        {
            for(int j = 0; j < n;j++)
            {
                Board[i].push_back('.');
            }
        }

        vector<bool>LeftDiagonal(2*n-1, 0);
        vector<bool>RightDiagonal(2*n-1, 0);
        vector<bool>column(n, 0);

        find(0, n, ans, Board, column, LeftDiagonal, RightDiagonal);
        return ans;
    }
};