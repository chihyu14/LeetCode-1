class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        //@n  matrix's size
        int n = matrix.size();
        //@row the number of rows we will process
        //@col the number of cols we will process
        int row = n>>1;
        int col = row;
        //col adds one if the matrix's size is odd
        if(n&1)
            ++col;
        //n minuses 1 for convenience
        --n;
        for(int i=0; i<row; ++i)
            {
                for(int j=0; j<col; ++j)
                    {
                        //the transform
                        //matrix[i][j] = matrix[n-j][i]
                        //matrix[n-j][i] = matrix[n-i][n-j];
                        //matrix[n-i][n-j] = matrix[j][n-i];
                        //matrix[j][n-i] = matrix[i][j]
                        int a = matrix[i][j];
                        matrix[i][j] = matrix[n-j][i];
                        matrix[n-j][i] = matrix[n-i][n-j];
                        matrix[n-i][n-j] = matrix[j][n-i];
                        matrix[j][n-i] = a;
                    }
            }
    }
};