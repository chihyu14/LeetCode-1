class Solution {
public:
    bool isPalindrome(string s) {
        //@l: left index
        //@r: right index
        int l=0, r = s.length()-1;
        //run the loop
        while(l<r)
        {
            //if s[l] isn't an alphanumeric, ++l
            if(!isalnum(s[l]))
                {
                    ++l;
                    continue;
                }
            //if s[r] isn't an alphanumeric, --r
            if(!isalnum(s[r]))
                {
                    --r;
                    continue;
                }
            //set lc, rc by s[l] and s[r] 
            char lc, rc;
            if(isalpha(s[l]))//ignore case
                lc = tolower(s[l]);
            else
                lc = s[l];
            if(isalpha(s[r]))//ignore case
                rc = tolower(s[r]);
            else
                rc = s[r];
            if(lc != rc)//lc doesn't match with rc, return false
                return false;
            ++l;
            --r;
        }
        return true;
    }
};
