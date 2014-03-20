class Solution {
    //DP:
    //f[i][j] = f[i][j-1]+(T[i-1] == S[j-1]?1:0)*f[i-1][j-1];
public:
    int numDistinct(string S, string T) {
        int ls = S.length();
        int lt = T.length();
        //if(ls<lt)
        //    return 0;
        vector<vector<int> > f(lt+6, vector<int>(ls+6, 0));
        for(int i=0; i<=ls; ++i)
            f[0][i] = 1;
        for(int i=1; i<=lt; ++i)
        {
            for(int j=i; j<=ls; ++j)
            {
                if(T[i-1] == S[j-1])
                  f[i][j] = f[i-1][j-1] + f[i][j-1];
                else
                  f[i][j] = f[i][j-1];
            }
        }
        return f[lt][ls];
    }
};