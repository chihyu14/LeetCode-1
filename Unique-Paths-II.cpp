class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        
        //  if  obstacleGrid[i][j] == 0   ans[i][j] = ans[i-1][j]+ans[i][j-1]
        //else  ans[i][j] = 0
        //@row row of the matrix
        //@col col of the matrix
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        //@f  the matrix of answer f[i][j] --> the unique paths from (0,0) to (i,j)
        vector<vector<int> > f(row, vector<int>(col, 0));
        //set the first row
        f[0][0] = obstacleGrid[0][0] == 0?1:0;
        for(int i=1; i<col; ++i)
            f[0][i] = obstacleGrid[0][i] == 0?f[0][i-1]:0;
        for(int i=1; i<row; ++i)
            {
                f[i][0] = obstacleGrid[i][0] == 0?f[i-1][0]:0;
                for(int j=1; j<col; ++j)
                    {
                        f[i][j] = obstacleGrid[i][j] == 0?f[i-1][j] + f[i][j-1]:0;
                    }
            }
        //return the answer
        return f[row-1][col-1];
    }
};