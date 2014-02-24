//See details in Problem Permutations
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size() < 2)
            return;
        int idx, i, t;
        for(idx = num.size()-2; idx>=0; --idx)
        {
            if(num[idx] < num[idx+1])
                break;
        }
        if(idx<0)
            {
                sort(num.begin(), num.end());
                return;
            }
        for(i=num.size()-1; i>=0; --i)
            if(num[i] > num[idx])
                break;
        t = num[i];
        num[i] = num[idx];
        num[idx] = t;
        for(idx=idx+1, i=num.size()-1; idx<i; ++idx,--i)
        {
            t = num[i];
            num[i] = num[idx];
            num[idx] = t;
        }
    }
};