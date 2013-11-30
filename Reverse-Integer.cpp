class Solution {
public:
    int reverse(int x) {
        //t is the temporary of x
        int t = x;
        if(x<0)//let t be positive
            t = -x;
        int ret = 0;
        while(t>0)
            {//converte t to ret
                ret = ret*10 + t%10;
                t /= 10;
            }
        if(x<0)//if x is negtive then ret should be negtive too
            ret = -ret;
        return ret;
    }
}; 
