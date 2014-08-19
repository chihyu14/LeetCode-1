class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        //@ret: answer we will return
        vector<string> ret;
        //@t: each solution
        string t(s.length()+6, ' ');
        //search all solutions
        work(ret, s, 0,t,0,0);
        //return ret
        return ret;
    }
    //@ret: answer
    //@s: the given string
    //@l: the index of s we have procedured
    //@t: solution string
    //@idx: the index of t
    //@cnt: how many '.' has been added to t.
    void work(vector<string> &ret, string &s, int l, string t, int idx,int cnt)
    {
        //reach the end of s
        if(l>=s.length())
        {
            if(cnt == 4)//4 parts
            {
                string tmp(t.begin(), t.begin()+idx-1);
                int t=0;
                //all numbers of the 4 parts are between [0,255]
                for(int i=0; i<tmp.length(); ++i)
                {
                    if(t>255)
                        break;
                    if('.' == tmp[i])
                        t = 0;
                    else
                        t = t*10 + tmp[i]-'0';
                }
                if(t<256)
                    ret.push_back(tmp);
            }
            return;
        }
        if(cnt>3)//can't be a possible combination
            return;
        if('0' == s[l])//the current digit is '0'
        {
            t[idx] = s[l];
            t[idx+1] = '.';
            work(ret, s, l+1, t, idx+2, cnt+1);
        }
        else
        {
            if(s[l] < '3')//the current digit is '1' or '2', the current part can be 1/2/3 digits,
            {
                for(int i=0; i<3&&l+i<s.length();++i)
                {
                    t[idx+i] = s[l+i];
                    t[idx+i+1] = '.';
                    work(ret, s, l+i+1, t, idx+i+2, cnt+1);
                }
            }
            else
            {
                for(int i=0; i<2&&i+l<s.length(); ++i)//the current part can be 1/2 digits.
                {
                    t[idx+i] = s[l+i];
                    t[idx+i+1] = '.';
                    work(ret,s,l+i+1, t, idx+i+2, cnt+1);
                }
            }
        }
    }
};