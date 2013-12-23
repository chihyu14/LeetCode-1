class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        //DP;
        //f[i][j] = triangle[i][j] + min{f[i+1][j],f[i+1][j+1]}
        int size = triangle.size();
        vector<int> tmp;
        for(int i=0; i<size; ++i)
            tmp.push_back(triangle[size-1][i]);
        for(int i=size-2; i>=0; --i)
            {
                for(int j=0; j<=i; ++j)
                    {
                        tmp[j] = triangle[i][j]+min(tmp[j],tmp[j+1]);
                    }
            }
        return tmp[0];
    }
};