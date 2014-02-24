class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
#if 1
        for(int i=1; i<(1<<n); ++i)
            //ret.push_back((i>>1)^i);  //it's ok, but it's hard to remember
            ret.push_back(ret[i-1] ^ (i&((i-1)^i)));
            //(i-1)^i  : all different bits of i and i-1
            //i & ((i-1)^i) : get the bit(1) change i-1 to i.
            //change the same bit in gray code.
#endif
        return ret;
    }
    //int 
};