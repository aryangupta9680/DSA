class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(); // rows
        int n = mat[0].size(); // columns
        vector<int>ans;

        for(int d = 0; d < m+n-1; d++) // each diagonal
        {
            vector<int>temp;
            for(int i = 0; i < m;i++) // check every row
            {
                int j = d - i;
                // valid matrix position
                if(j >= 0 && j < n) 
                {
                    temp.push_back(mat[i][j]);
                }
            }

            // reverse even diagonals
            if(d % 2 == 0) 
            {
                reverse(temp.begin(), temp.end());
            }

            for(int x : temp) 
            {
                ans.push_back(x);
            }
        }

        return ans;
    }
};