class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        //see Unique Paths for more details
        for(int i=0; i<=rowIndex; ++i)
            {
                int n=rowIndex;
                int m=i>rowIndex/2?rowIndex-i:i;
                //use long long to prevent out of range!!!!!
                long long ans = 1;
                for(int j=1; j<=m; ++j)
                    {
                        ans *= (j+n-m);
                        ans /= j;
                    }
                ret.push_back(ans);
            }
        return ret;
    }
};