class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        return work(s, 0, p, 0);
    }
    //@s: the given string
    //@idx: current index of s
    //@p: the pattern string
    //@:: current index of p
    bool work(const char *s, int idx, char const *p, int l)
    {
        //match
        if(strlen(s) == idx && strlen(p) == l)
            return true;
        //doesn't match
        if(strlen(p) == l)
            return false;
        //reach the end of s
        if(strlen(s) == idx)
        {
            //test if all left string in p can match empty string
            while(l < strlen(p))
            {
                if(l+1<strlen(p) && p[l+1] == '*')
                    l = l+2;
                else
                    break;
            }
            return (l == strlen(p));
        }
        if(l+1<strlen(p) && p[l+1]=='*')//if p[l+1] == '*'
        {
            bool ret = false;
            int i;
            for(i=idx; i<= strlen(s); ++i)
            {
                ret = ret || work(s, i, p, l+2);//match 0 or more of the preceding character
                if('.' != p[l] && s[i] != p[l])
                    break;
            }
            return ret;
        }
        else
            return ((p[l] == s[idx] || p[l] == '.') && work(s, idx+1, p, l+1));
    }
};