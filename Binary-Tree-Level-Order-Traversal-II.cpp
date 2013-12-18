class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        //map<int, int> tmp : index--->value
        //index := the index travels by level
        //the index array of the example is{{1,3},{2,9},{3,20},{6,15},{7,17}} .
        //@ret: the answer we will return
        vector<vector<int> > ret;
        //travel the tree
        process(root, 0, ret);

		int size = ret.size()-1;
		for(int i=0; (i<<1)<size; ++i)
			{
				//vector<int> tmp = ret[i];
				//ret[i] = ret[size-i];
				//ret[size-i] = tmp;
				swap(ret[i], ret[size-i]);
			}
        //return the answer
        return ret;
    }
    //travel the tree
    //@cur: the current node
    //@key: the level of the current node (0-based)
    //@ret: the answer array
    void process(TreeNode *cur, int key, vector<vector<int> > &ret)
        {
            if(NULL == cur)
                return;
			int idx = key;
			if(idx>=ret.size())
				ret.push_back(vector<int>());
			ret[idx].push_back(cur->val);
            process(cur->left, key+1, ret);
            process(cur->right, key+1, ret);
        }
}; 
