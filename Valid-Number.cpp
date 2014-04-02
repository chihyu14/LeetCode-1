class Solution {
//digit = '0' - '9'
//digits = digit^{+}
//opt_fraction = ('.'digits)?
//opt_exponent = ('e'('+'+'-'+'empty')digits)?
//digits opt_fraction opt_exponent
public:
    bool isNumber(const char *s) {
        int len = strlen(s);
        int idx = 0;
        bool on = false, two = false;;
        while(len>0 && s[len-1] == ' ')
            --len;
        while(idx < len && s[idx] == ' ')
            ++idx;
        
        //digits
        if(idx < len && '+' == s[idx] || '-' == s[idx])
            ++idx;
        while(idx < len && s[idx]>='0' && s[idx]<='9')
        {
            ++idx;
            on = true;
        }
        //opt_fraction
        if(idx < len && '.' == s[idx])
        {
            ++idx;
            while(idx < len && s[idx]>='0' && s[idx]<='9')
            {
                ++idx;
                on = true;//there must have digits before *OR* after '.'
            }
        }
        //opt_exponent
        if(idx < len && 'e' == s[idx])
        {
            ++idx;
            if(idx < len && '+' == s[idx] || '-'==s[idx])
                ++idx;
            while(idx < len && on && s[idx]>='0' && s[idx]<='9')
            {
                ++idx;
                two = true;
            }
            on = on && two;//there must have digits before *AND* after e!!!
        }
        if(idx>=len && on)
            return true;
        return false;
    }
};