class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        //@tmp: auxiliary set, kick the duplicate vecter<int>
        set<vector<int> > tmp;
        //@t: size of candidates
        int t=candidates.size();
        //@size: size of ans
        int size = max(t, target);
        //@ans: each combination
        vector<int> ans(size);
        //search all the solutions
        work(candidates, tmp, ans, 0, 0, target);
        //translate set<vector<int> > to vector<vector<int> >
        vector<vector<int> > ret(tmp.begin(), tmp.end());
        ///return the answer
        return ret;
    }
    //@candidates: the same as above
    //@tmp: auxiliary set
    //@ans: each solution
    //@idx: how many elements in ans
    //@l: how many elements we have maniplated in candidates
    //@target: the given target
    void work(const vector<int> &candidates, set<vector<int> > &tmp, vector<int> &ans, int idx, int l, int target)
    {
        //@t: sum of all the number in ans
        int t = 0;
        for(int i=0; i<idx;++i)
            t += ans[i];
        if(t == target)//found a solution
        {
            vector<int> aa(ans.begin(), ans.begin()+idx);
            sort(aa.begin(), aa.end());
            tmp.insert(aa);
            return;
        }
        if(t < target && l<candidates.size())
        {
            //skip the current number
            work(candidates, tmp, ans, idx, l+1, target);//doesn't include candidates[l]
            //contain the current number
            ans[idx] = candidates[l];
            work(candidates, tmp, ans, idx+1, l, target);//include candidates[l] && still can include candidates[l]
            //work(candidates, tmp, ans, idx+1, l+1, target);//
        }
    }
};