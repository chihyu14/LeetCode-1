class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        //if()
        //@ret: answer
        vector<int> ret;
        //@m: row
        //@n: col
        int m = matrix.size();
        if(0 == m)
            return ret;
        int n = matrix[0].size();
        //@total: the number of elements in the matrix
        int total = m*n;
        
        //@l,@r,@t,@b:left,right,top,butoom of *current* matrix
        int l = 0, r = n-1, t = 0, b = m-1;
        int i, j;
        while(ret.size() < total)
            {
                //the upper line
                for(i=t,j=l; j<=r; ++j)
                    ret.push_back(matrix[i][j]);
                ++t;
                //if all the elements have been processed
                if(ret.size() >= total)
                    break;
                //the rightest line
                for(i=t,j=r; i<=b; ++i)
                    ret.push_back(matrix[i][j]);
                if(ret.size() >= total)
                    break;
                --r;
                //the buttom line
                for(i=b,j=r; (j>=l); --j)
                    ret.push_back(matrix[i][j]);
                if(ret.size() >= total)
                    break;
                --b;
                //the leftest line
                for(i=b,j=l; (i>=t); --i)
                    ret.push_back(matrix[i][j]);
                ++l;
            }
        return ret;
    }
}; 
