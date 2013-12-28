class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //@ret : the answer
        vector<string> ret;
        //@tmp : the string we will push into the vector
        string tmp(2*n, 'j');
        //generate all possible parentheses
        work(ret, tmp, (n), 0, 0);
        return ret;
    }
    //@ret  : the answer
    //@tmp : the string we will push into the vector
    //@n : same as above in the problem
    //@left : the number of '(' we have used
    //@right: the number of ')' we have used
    void work(vector<string> &ret, string &tmp, int n, int left, int right)
    {
        //we have a solution
        if(left == n && right == n)
            {
                ret.push_back(tmp);
                return;
            }
        //push a '(' into the string
        if(left == right)
            {
                tmp[left+right] = '(';
                work(ret, tmp, n, left+1, right);
            }
        else
            {
                //push a '(' into the string if possible
                if(left<n)
                    {
                        tmp[left+right] = '(';
                        work(ret, tmp, n, left+1, right);
                    }
                //push a ')' into the string if possible
                //be careful (left<=n), we must use <= instead of < here!!!!!
                if((left<=n) && (right<n) && (left>right))
                    {
                        tmp[left+right] = ')';
                        work(ret, tmp, n, left, right+1);
                    }
            }
    }
};class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //@ret : the answer
        vector<string> ret;
        //@tmp : the string we will push into the vector
        string tmp(2*n, 'j');
        //generate all possible parentheses
        work(ret, tmp, (n), 0, 0);
        return ret;
    }
    //@ret  : the answer
    //@tmp : the string we will push into the vector
    //@n : same as above in the problem
    //@left : the number of '(' we have used
    //@right: the number of ')' we have used
    void work(vector<string> &ret, string &tmp, int n, int left, int right)
    {
        //we have a solution
        if(left == n && right == n)
            {
                ret.push_back(tmp);
                return;
            }
        //push a '(' into the string
        if(left == right)
            {
                tmp[left+right] = '(';
                work(ret, tmp, n, left+1, right);
            }
        else
            {
                //push a '(' into the string if possible
                if(left<n)
                    {
                        tmp[left+right] = '(';
                        work(ret, tmp, n, left+1, right);
                    }
                //push a ')' into the string if possible
                //be careful (left<=n), we must use <= instead of < here!!!!!
                if((left<=n) && (right<n) && (left>right))
                    {
                        tmp[left+right] = ')';
                        work(ret, tmp, n, left, right+1);
                    }
            }
    }
};