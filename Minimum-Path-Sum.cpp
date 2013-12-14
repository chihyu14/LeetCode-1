class Solution {
public:
    //dp: f[n][m] = min{f[n-1][m],f[n][m-1]}+grid[n][m]
    //we could solve this problem whit O(n) space complexity!!!
    //because we need only store the answer of previous row and the current row
    int minPathSum(vector<vector<int> > &grid) {
        //@ret: store the minimum sum from left-top to this element
        vector<vector<int> > ret(grid.size());
        
        //process the first row
        ret[0].push_back(grid[0][0]);
        for(int i=1; i<grid[0].size(); ++i)
            ret[0].push_back(ret[0][i-1]+grid[0][i]);
        //process the second row to the last row
        for(int i=1; i<grid.size(); ++i)
            {
                //process the left most element
                ret[i].push_back(grid[i][0]+ret[i-1][0]);
                for(int j=1; j<grid[i].size(); ++j)
                    {//process the other elements in row-i
                        int t = ret[i][j-1]<ret[i-1][j]?ret[i][j-1]:ret[i-1][j];
                        ret[i].push_back(t+grid[i][j]);
                    }
            }
        //return the answer
        return ret[grid.size()-1][grid[0].size()-1];
    }
};