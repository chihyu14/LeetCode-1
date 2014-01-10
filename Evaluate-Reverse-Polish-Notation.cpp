class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int ret;
        stack<int> stk;
        for(int i=0; i<tokens.size(); ++i)
            {
                if(tokens[i].size() == 1)
                    {//this string may be an operator
                        switch(tokens[i][0])
                            {
                                case '+':
                                    {
                                        int a = stk.top();  stk.pop();
                                        int b = stk.top();  stk.pop();
                                        stk.push(a+b);
                                        break;
                                    }
#if 1
                                case '-':
                                    {
                                        //be careful!!!!
                                        //it's b-a not a-b!!!!
                                        int a = stk.top();  stk.pop();
                                        int b = stk.top();  stk.pop();
                                        stk.push(b-a);
                                        break;
                                    }
                                case '*':
                                    {
                                        int a = stk.top();  stk.pop();
                                        int b = stk.top();  stk.pop();
                                        stk.push(a*b);
                                        break;
                                    }
                                case '/':
                                    {
                                        //be careful!!!!
                                        //it's b/a not a/b!!!!!
                                        int a = stk.top();  stk.pop();
                                        int b = stk.top();  stk.pop();
                                        stk.push(b/a);
                                        break;
                                    }
#endif
                                default:
                                    {
                                        int a = strnum(tokens[i]);
                                        stk.push(a);
                                    }
                            }
                    }
                else
                    {
                        int a = strnum(tokens[i]);
                        stk.push(a);
                    }
            }
        return stk.top();
    }
    //convert a string to num
    //num could be negative
    int strnum(string str)
    {
        int ret= 0, i=0;
        if(str[0] < '0' || str[0] > '9')
            {
                i = 1;
            }
        for(;i<str.size(); ++i)
            ret = ret*10 + str[i]-'0';
        if('-' == str[0])
            ret = -ret;
        return ret;
    }
};