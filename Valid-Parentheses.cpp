class Solution {
public:
    bool isValid(string s) {
        //stack store the left characters
        stack<char> t;
        int size = s.length();
        for(int i=0; i<size; ++i)
            {
                //push the left charcters into the stack
                if('(' == s[i])
                    t.push('(');
                if('{' == s[i])
                    t.push('{');
                if('[' == s[i])
                    t.push('[');
                //test the right characters
                if(')' == s[i])
                    {
                        ///stack is empty or the toppest character doesn't match
                        if(t.empty() || '(' != t.top())
                            return false;
                        else
                            t.pop();
                    }
                if('}' == s[i])
                    {
                        if(t.empty() || '{' != t.top())
                            return false;
                        else
                            t.pop();
                    }
                if(']' == s[i])
                    {
                        if(t.empty() || '[' != t.top())
                            return false;
                        else
                            t.pop();
                    }
            }
        //if t isn't empty
        if(!t.empty())
            return false;
        return true;
    }
}; 
