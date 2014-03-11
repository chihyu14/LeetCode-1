class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        //sort num for optimazition
        sort(num.begin(), num.end());
        //@t: auxiliray set
        set<vector<int> > t;
        //@ans: each solution
        vector<int> ans(4);
        //search all the solution
        work(t, num, 0, ans, 0, target);
        //@ret: answer we will return
        vector<vector<int> > ret(t.begin(), t.end());
        return ret;
    }
    //@tmp: auxiliray set
    //@num: the given num vector
    //@l: how many numbers we have handled in vector num
    //@ans: each solution vector
    //@indx: how many numbers in ans
    //@target: the given target
    void work(set<vector<int> > &tmp, vector<int> &num, int l, vector<int> &ans, int idx, int target)
    {
        //@t: the sum of numbers in ans
        int t = 0;
        for(int i=0; i<idx; ++i)
            t += ans[i];
        //if we have found a solution or have handled all numbers in num
        if(4 == idx || l>=num.size())
        {
            if(target == t && (4 == idx)) //found a solution
            {
                vector<int> a(ans.begin(), ans.end());
                sort(a.begin(), a.end());
                tmp.insert(a);
            }
            return;
        }
        if(l+(4-idx) <= num.size()) //the left numbers in num[] can still make a solution
        {
            int ta = t;
            int tb = t;
            for(int i=l,j=0;j<4-idx;++j,++i)
                ta += num[i];
            for(int i=num.size()-1, j=0; j<4-idx; --i,++j)
                tb += num[i];
            if(ta<=target && tb>=target)///we have sorted the vector before, so, if ta>tareget or tb<target, the solution is impossible
            {
                work(tmp, num, l+1, ans, idx, target);//solution doesn't include num[l]
                ans[idx] = num[l];
                work(tmp, num, l+1, ans, idx+1, target);///solution include num[l]
            }
        }
    }
};