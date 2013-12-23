class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret(n, vector<int>(n));
        int l=0, r=n-1, t=0, b=n-1;
        int i,j;
        int cur = 1;
        int total = n*n;
        while(l <=r && t <= b)
            {
                //top
                for(i=t,j=l; cur<=total && j<=r; ++j)
                    ret[i][j] = cur++;
                //right
                for(i=t+1,j=r; cur<=total && i<=b; ++i)
                    ret[i][j] = cur++;
                //button
                for(i=b,j=r-1; cur<=total && j>=l; --j)
                    ret[i][j] = cur++;
                //left
                for(i=b-1,j=l; cur<=total && i>t; --i)
                    ret[i][j] = cur++;
                ++t; --b;
                ++l; --r;
            }
        return ret;
    }
};