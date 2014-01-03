class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        //sort S to gurantee note 1
        sort(S.begin(), S.end());
        //use set to kick out the duplicate subsets
        set<vector<int> > auxi;
        int size = 1<<S.size();
        for(int i=0; i<size; ++i)
            {
                vector<int> tmp;
                for(int j=0; j<S.size(); ++j)
                    {
                        if(i&(1<<j))
                            tmp.push_back(S[j]);
                    }
                auxi.insert(tmp);
            }
        //translate set to vector
        vector<vector<int> > ret(auxi.begin(), auxi.end());
        return ret;
    }
}; 
