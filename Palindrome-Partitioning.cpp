class Solution {
public:
    vector<vector<string>> partition(string s) {
        //@ret: answer we will return 
        vector<vector<string> > ret;
        //@ans: each solution
        vector<string> ans(s.length());
        //search all solutions
        work(s, 0, ans, 0, ret);
        return ret;
    }
    //@s: a string
    //return true if s is a palindrome, else false
    inline bool ispalindrome(string s)
    {
        for(int i=0, j=s.length()-1; i<j; ++i, --j)
            if(s[i] != s[j])
                return false;
        return true;
    }
    //@s: the given string
    //@idx: the index we has manipulated
    //@ans: each solution
    //@l: how many string in ans
    //@ret: final answer 
    void work(const string &s, int idx, vector<string> &ans, int l, vector<vector<string> > &ret)
    {
        //the partition is over
        if(idx >= s.length())
            {
                vector<string> tt(ans.begin(), ans.begin()+l);
                ret.push_back(tt);
                return;
            }
        //test all possiblility
        for(int i=idx; i<s.length(); ++i)
            {
                string t = s.substr(idx, i-idx+1);
                if(ispalindrome(t))//t is a palindrome string
                {
                    ans[l] = t;
                    work(s, i+1, ans, l+1, ret);
                }
            }
    }
};