class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        //@row: matrix's row
        //@col: matrix's col
        int row = matrix.size();
        int col = matrix[0].size();
        //@tmp: tpm[i]=0 => current column should be setted to 0
        vector<int> tmp(col, 1);
        //@zero: the current should setted to 0 or not
        bool zero;
        //loop all rows
        for(int i=0; i<row; ++i)
            {
                zero = false;//set zero to false
                for(int j=0; j<col; ++j)
                    {
                        if(0 == matrix[i][j])
                            {
                                zero = true;//update zero
                                tmp[j] = 0; //update tmp[j]
                            }
                    }
                if(zero) //set the entire row to 0
                    {
                        for(int j=0; j<col; ++j)
                            matrix[i][j] = 0;
                    }
                else
                    {
                        for(int j=0; j<col; ++j)
                            {
                                if(tmp[j] == 0) //set number at column j to 0
                                    matrix[i][j] = 0;
                            }
                    }
            }
        for(int i=0; i<row; ++i) //handle the case such as [[1,1],[0,0]]
        {
            for(int j=0; j<col; ++j)
                {
                    if(tmp[j] == 0)
                        matrix[i][j] = 0;
                }
        }
    }
};