class Solution {
public:
    int numDecodings(string s) {
        //empty string
        if(s.empty())
            return 0;
        vector<int> f;
        //init f[0] && f[1]
        if(s[0]=='0')
            {
                f.push_back(0);
                f.push_back(0);
            }
        else
            {
                f.push_back(1);
                f.push_back(1);
            }
        for(int i=1; i<s.length(); ++i)
            {
                //init f[i+1] = 0
                //f[i+1]---->answer for s[1...i]
                f.push_back(0);
                if('0' == s[i])
                    {//...10... or ...20...
                        if(s[i-1]=='1' || '2'==s[i-1])
                            f[i+1] = f[i-1];
                    }
                else
                    {
                        if(s[i]>'0' && s[i]<'7')
                            {//...1[1-6].... or ...2[1-6]....
                                if('1'==s[i-1] || '2'==s[i-1])
                                    f[i+1] = f[i-1]+f[i];
                                else//...[0,7,8,9][1-6]....
                                    f[i+1] = f[i];
                            }
                        else
                            {
                                if('1'==s[i-1])//...1[0,7-9]....
                                    f[i+1] = f[i]+f[i-1];
                                else//...[0,2-9][0,7-9]....
                                    f[i+1] = f[i];
                            }
                    }
            }
        //return answer of s
        return f[s.length()];
    }
    
};