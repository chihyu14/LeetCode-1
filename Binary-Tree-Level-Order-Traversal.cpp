class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        //map<int, int> tmp : index--->value
        //index := the index travels by level
        //the index array of the example is{{1,3},{2,9},{3,20},{6,15},{7,17}} .
        map<int, int> tmp;
        //travel the tree
        process(root, 1, tmp);
        //@ret: the answer we will return
        vector<vector<int> > ret;
        //translates to the answer from the map<int, int>
        for(map<int,int>::iterator ite = tmp.begin(); ite != tmp.end(); ++ite)
            {
                //get the levle
                int idx = log2(ite->first);
                //resize the ret if needed
                if(idx>=ret.size())
                    ret.push_back(vector<int>());
                //add the answer
                ret[idx].push_back(ite->second);
                //s = s<idx?s:idx;
            }
        //return the answer
        return ret;
    }
    //return the level of x
    //@x: the index of the node (>=1)
    int log2(int x)
        {
            int ret = 0;
            while((1<<ret) <= x)
                ++ret;
            return ret-1;
        }
    //travel the tree
    void process(TreeNode *cur, int key, map<int,int> &ret)
        {
            if(NULL == cur)
                return;
            ret[key] = cur->val;
            process(cur->left, key*2, ret);
            process(cur->right, key*2+1, ret);
        }
}; 
