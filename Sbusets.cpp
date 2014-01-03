class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        //sort S to gurantee the Note 1!!!
        sort(S.begin(), S.end());
        //@ret: the answer we will return
        vector<vector<int> > ret;
        int size = 1<<S.size();
        //travel all possible subsets
        for(int i=0; i<size; ++i)
            {
                vector<int> tmp;
                for(int j=0; j<S.size(); ++j)
                    {
                        //if S[j] is coverd by subset i
                        //treat all elements in S as a bit in binary(left to right)
                        if(i&(1<<j))
                            tmp.push_back(S[j]);
                    }
                ret.push_back(tmp);
            }
        return ret;
    }
}; 
