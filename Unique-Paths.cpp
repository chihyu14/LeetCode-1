class Solution {
public:
    int uniquePaths(int m, int n) {
        //minus m and n, and, we get the 
        //pascal triangle
        --m; --n;
        //guarante m <= n
        if(m > n)
            {//m <= n
                int t = m;
                m = n;
                n = t;
            }
        //define ret as long long for calculating!!!!
        //because in the loop ret will be multiplied by j
        //and this will beyound the INT_MAX
        long long  ret = 1;
        for(int i=1,j=n+1; i<=m; ++i,++j)
            {//ret = (m+n)!/(m!*n!)
             //eliminate the same n!, then, we get
             //ret = {(n+1)*...*(m+n)}/(1*...*m)
                ret *= j;
                ret /= i;
            }
        //return ret, and, this will be ok
        //because m<=100&&n<=100, ret is less than
        //C(200,100)
        return ret;
    }
};