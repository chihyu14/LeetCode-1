class Solution {
public:
    bool isPalindrome(int x) {
        //negative number!!!
        if(x<0)
            return false;
        //zero
        if(0 == x)
            return true;
        //@l: bits of x
        int l=0, t=x;
        while(t)
            {
                ++l;
                t /= 10;
            }
        //@t: biggest pow of 10 less than x
        t = 1;
        while(--l)
            {
                t *= 10;
            }
        //@l: 1 ----> 10^i
        //@t: 10^i ---> 1
        l = 1;
        while(l <= t)
            {
                int small = (x/l)%10;//the rightest bit hasn't been processed
                int big = (x/t)%10;//the leftest bit hasn't been processed
                if(small != big)//doesn't match, return false
                    return false;
                l *= 10;//l moves one step to right
                t /= 10;//t moves one step to left
            }
        //return true;
        return true;
    }
};