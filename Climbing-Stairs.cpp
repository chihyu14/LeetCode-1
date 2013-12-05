class Solution {
public:
    int climbStairs(int n) {
        //init ret[] with two one,
        //ret[0]=1 and ret[1]=1
        static vector<int> ret(2, 1);
        //if ret[n] has been calculated before
        if(n<ret.size())
            return ret[n];
        //calculates the ret[] value from ret.size() to n
        //ret[i] = ret[i-1]+ret[i-2]
        for(int i=ret.size(); i<=n; ++i)
            ret.push_back(ret[i-1]+ret[i-2]);
        return ret[n];//return the answer
    }
}; 
