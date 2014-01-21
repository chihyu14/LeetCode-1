class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        //@ret: answer
        string ret;
        //@l: the length of prefix's maxsize
        int l=INT_MAX;
        //update l
        for(int i=0; i<strs.size(); ++i)
        {
            if(strs[i].length() < l)
                l = strs[i].length();
        }
        //calculate ret
        for(int i=0; i<l; ++i)
        {
            int j;
            //
            for(j=1; j<strs.size(); ++j)
                if(strs[j][i] != strs[0][i])
                    break;
            //if strs[0][i] isn't a letter of prefix
            if(j != strs.size())
                break;
            //add strs[0][i] to ret
            ret.push_back(strs[0][i]);
        }
        return ret;
    }
};
