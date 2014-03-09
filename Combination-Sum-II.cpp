class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        //@tmp: use set to kick the same combination
        set<vector<int> > tmp;
        //@ans: each combination
        vector<int> ans(num.size());
        //calculate tmp
        work(num, tmp, ans, 0, 0, target);
        //translate set<vector<int> > to vector<vector<int> >
        vector<vector<int> > ret(tmp.begin(), tmp.end());
        //return the answer
        return ret;
    }
    //@num: collection vector
    //@ret: answer we will return
    //@ans: each combination
    //@idx: how many elements in vector ans
    //@l: how may elements we have handled in num
    //@target: the given target
    void work(const vector<int> &num, set<vector<int> > &ret, vector<int> &ans, int idx, int l, int target)
    {
        //@t: sum of all number we have picked
        int t=0;
        for(int i=0; i<idx; ++i)
            t += ans[i];
        
        //we have found a solution
        if(t == target)
        {
            vector<int> tmp(ans.begin(), ans.begin()+idx);
            sort(tmp.begin(), tmp.end());
            ret.insert(tmp);
            return;
        }
        //sum is bigger than target
        if(t>target) //all elements are positive
            return;
        //if we have not tried all the number in vector num
        if(l < num.size())
        {
            work(num, ret, ans, idx, l+1, target); //skip the current element
            //pick the current element
            ans[idx] = num[l];
            work(num, ret, ans, idx+1, l+1, target);
        }
    }
};