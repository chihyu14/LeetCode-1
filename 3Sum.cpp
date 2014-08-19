class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        //num doesn't have 3 numbers
        if(num.size()<3)
            return vector<vector<int> >();
        //sort num
        sort(num.begin(), num.end());
        //use set to kick the duplicates,
        set<vector<int> > ret;
        //@add: each solution
        vector<int> add(3);
        int s = num.size();
        int i, j, k, t;
        int jj, kk;
        //search every middle number
        for(i=1; i<s-1; ++i)
        {
            //@j: the index of the smallest number
            //@k: the index of the largest number
            j = i-1;
            k = i+1;
            while(j>=0 && k<s)
            {
                //calculate the sum
                t = num[i] + num[j] + num[k];
                //found a solution
                if(0 == t)
                {
                    add[0] = num[j];
                    add[1] = num[i];
                    add[2] = num[k];
                    ret.insert(add);//push this solution into ret
                    kk = k+1;//skip all the number same as num[k]
                    while(kk<s && num[kk] == num[k]) ++kk;
                    k = kk;
                    jj = j-1;//skip all the number same as num[j]
                    while(jj>0 && num[jj] == num[j]) --jj;
                    j = jj;
                }
                else
                {
                    if(t>0)//update j, because the sum bigger than 0
                    {
                        --j;
                    }
                    else//update k, because the sum less than 0
                    {
                        ++k;
                    }
                }
            }
        }
        vector<vector<int> > r(ret.begin(), ret.end());
        return r;
    }
};