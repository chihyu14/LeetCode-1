class Solution {
    //algorithm:
    //we set the middle of the three numbers,
    //then left for the smallest number and right for the biggest number
    //in this case, we loop all numbers for middle,
    //and, each middle number, we update left and right
    //time complexity is ((1+(n-2)) + (2+(n-3)) + (3+(n-4)) + ... + ((n-2)+1))
    //is O(n^2)
public:
    int threeSumClosest(vector<int> &num, int target) {
        //sort the vector
        sort(num.begin(), num.end());
        int ret=0;
        for(int i=0; i<3; ++i)
            ret += num[i];
        int size = num.size();
        if(size<=3)
            return ret;
        int left, right;
        int tmp;
        for(int i=1; i<size; ++i)
        {
            left = i-1;
            right = i+1;
            while(left>=0 && right<size)
            {
                tmp = num[i]+num[left]+num[right];
                if(tmp == target)
                    return tmp;
                if(tmp<target)
                {
                    if(abs(tmp-target) < abs(ret-target))
                        ret = tmp;
                    ++right;
                }
                else
                {
                    if(abs(tmp-target) < abs(ret-target))
                        ret = tmp;
                    --left;
                }
            }
        }
        return ret;
    }
};