class Solution {
public:
    string longestPalindrome(string s) {
        //empty string
        if(0 == s.length())
            return string();
        //@idx: start index of the palindromic substring
        //@l: length of the palindromic substring
        int idx=0, l=1;
        //loop the string
        for(int i=0; i<s.length(); ++i)
        {
            int j, k;
            //let s[i] be the palindromic substring's middle character
            for(j=i-1,k=i+1; j>=0&&k<s.length(); --j,++k)
            {
                if(s[j] != s[k])
                    break;
            }
            if(k-j-1>l)//if we have found a longer palindromic substring
            {
                idx = j+1;
                l = k-j-1;
            }
            //left part of palindromic substring begin from i-1 to 0
            //right part of palindromic substring begin form i to s.length()
            for(j=i-1,k=i; j>=0 && k<s.length(); --j,++k)
            {
                if(s[j] != s[k])
                    break;
            }
            if(k-j-1>l)//found a longer palindromic substring
            {
                idx = j+1;
                l = k-j-1;
            }
        }
        string ret = s.substr(idx, l);//create the palindromic substring
        return ret;//return the longest palindromic substring
    }
};