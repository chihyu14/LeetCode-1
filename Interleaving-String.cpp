class Solution {
    //DP:
    //can[i][j] : use i-th characters of s1 and j-th characters of s2 can(or not) generate the (i+j)-th characters of s3
public:
    bool isInterleave(string s1, string s2, string s3) {
        //@l1: length of s1
        //@l2: length of s2
        //@l3: length of s3
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        if(l1 + l2 != l3) // test the length first
            return false;
        //@can: can[i][j]=true, if the first i-th characters of s1 and the first j-th characters of s2 can generate the first
        //(i+j)-th characters of s3, can[i][j]=false, can't generate
        vector<vector<bool> > can(l1+6, vector<bool>(l2+6,false));
        //init the board value
        can[0][0] = true;
        for(int i=1; i<=l1; ++i)
        {
            if(s3[i-1] == s1[i-1])
                can[i][0] = can[i-1][0];
        }
        for(int i=1; i<=l2; ++i)
        {
            if(s3[i-1] == s2[i-1])
                can[0][i] = can[0][i-1];
        }
        for(int i=1; i<=l1; ++i)
        {
            for(int j=1; j<=l2; ++j)
            {
                if(s1[i-1] == s3[i+j-1])//s1[i-1] == s3[i+j-1], then test can[i-1][j]
                    can[i][j] = can[i][j] || can[i-1][j];
                if(s2[j-1] == s3[i+j-1])//s2[j-1] == s3[i+j-1], then test can[i][j-1]
                    can[i][j] = can[i][j] || can[i][j-1];
            }
        }
        return can[l1][l2];//return the answer
        //return work(s1, s2, s3, 0, 0, 0);
    }
};