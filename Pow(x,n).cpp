class Solution {
public:
    double pow(double x, int n) {
        //x^n = x^a0 * x^a1 * x^a2 ... * x^ak
        //ai is pow of 2
        double ret = 1.0;
        //unsigned int!!!!
        //because n maybe INT_MIN, its abs value will be not in
        //the range of int
        unsigned int t = n<0?-n:n;
        //process x^t
        while(t)
            {
                if(t&1)
                    {
                        ret = ret*x;
                    }
                t >>= 1;
                x = x*x;
            }
        //if n is negative,
        if(n<0)
            ret = 1/ret;
        return ret;
    }
}; 
