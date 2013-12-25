class Solution {
public:
    int atoi(const char *str) {
        //empty string
        if(NULL == str || 0 == strlen(str))
            return 0;
        //use unsigned int to calculate the answer
        unsigned int ans = 0;
        int add;
        //@flag : if the number is negative?
        bool flag(false);
        //pass through all the space
        while('\0' != *str)
            {
                if(' ' == *str)
                    ++str;
                else
                    break;
            }
        //process '-' and '+'
        if('-' == *str)
            {
                ++str;
                flag = true;
            }
        else
            {
                if('+' == *str)
                    ++str;
            }
        //process the string
        while('\0' != *str)
            {
                //if the character isn't a number, break;
                if(!(*str>='0' && *str<='9'))
                    break;
                add = *str-'0';
                //if the number is too big already(for int)!!!!
                if(ans > 214748364)
                    {
                        ans = 2147483648;
                        break;
                    }
                ans = ans*10 + add;
                ++str;
            }
        int ret;
        //if ans is bigger than INT_MAX+1
        //we use INT_MAX+1, because the number will be negative,
        //and the negative number is -(INT_MAX+1)
        if(ans > 2147483648)
            ans = 2147483648;
        if(flag)
            {
                ret = -ans;
            }
        else
            {
                //minus ans to fit integer
                if(2147483648 == ans)
                    --ans;
                ret = ans;
            }
        return ret;
    }
};