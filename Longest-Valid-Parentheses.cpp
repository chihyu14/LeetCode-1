Solution 1:
class Solution {
public:
    int longestValidParentheses(string s) {
        //@ret: answer we will return
        int ret = 0;
        //@l: number of '('
        //@r: number of ')'
        //@tmp: auxiluray variable
        int l, r, tmp;
        //@next: the longest valid parentheses from current index
        int next;
        //set all the characters to the biginning parentheses
        for(int i=0; i<s.length(); )
        {
            if(')' == s[i])//skip all ')'
            {
                ++i;
                continue;
            }
            //we have one '(' and zero ')'
            l = 1;
            r = 0;
            int j = i+1;
            //@we don't have any parentheses
            next = 0;
            //work on all the characters
            while(j<s.length() && l>=r)
            {
                if(s[j]=='(')
                    ++l;
                else
                    ++r;
                ++j;
                if(l == r)//found parentheses, update next
                {
                    next = l + r;
                }
            }
            if(next > ret)//if next(the longest valid parentheses in current loop) is longer than ret
                ret = next;
            if(0 == next)//next is zero, there are more '(' than ')' in s[i]->s[j], skip the excess '('
                i += l-r;
            else
                i += next;//skip the longest valid parentheses, may be there be wrong(we update next if and only if l==r), so, we need a reverse loop below
            
        }
        //do a reverse loop to get the right answer, in case there is a test case like '((())('[there are more '(' than ')' and , any '(' in the end]
        for(int i=s.length()-1; i>=0; )
        {
            if('(' == s[i])
            {
                --i;
                continue;
            }
            l = 0;
            r = 1;
            int j = i-1;
            next = 0;
            while(j>=0 && r>=l)
            {
                if(s[j] == ')')
                    ++r;
                else
                    ++l;
                --j;
                if(l == r)
                    next = l+r;
            }
            if(next>ret)
                ret = next;
            if(0 == next)
                i -= r-l;
            else
                i -= next;
        }
        return ret;
    }
};

Solution 2:
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> st(s.length());
        int idx=0;
        int ret = 0;
        int last = -1;
        for(int i=0; i<s.length(); ++i)
        {
            if('(' == s[i])
                st[idx++] = i;
            else
            {
                if(idx == 0)
                {
                    //do nothing
                    last = i;
                }
                else
                {
                    --idx;
                    if(idx == 0)//a valid parenthese
                    {
                        ret = max(ret, i-last);
                    }
                    else
                    {
                        ret = max(ret, i-st[idx-1]);
                    }
                }
            }
        }
        return ret;
    }
};