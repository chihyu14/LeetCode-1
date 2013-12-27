class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        //@ret : answer
        vector<vector<int> > ret;
        //@tmp auxiliary array
        vector<int> tmp;
        //travel all possible combinations
        work(ret, n+1, k, tmp, 1);
        //return the answer
        return ret;
    }
    //@ret: answer
    //@n:
    //@k: same as in the description
    //@tmp: the current picked number
    //@cur: the current number
    void work(vector<vector<int> > &ret, int n, int k, vector<int> tmp, int cur)
    {
        //if cur is bigger than the given n(we call the function with n+1!!!!)
        if(cur == n)
            {
                //add a solution
                if(tmp.size() == k)
                    ret.push_back(tmp);
                return;
            }
        //the combination doesn't contain this number
        work(ret, n, k, tmp, cur+1);
        //the combination contains this number
        tmp.push_back(cur);
        work(ret, n, k, tmp, cur+1);
    }
}; 
