class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        //lo: the low index of A[]
        //hi: the high index of A[]
        //mi: middle of lo and hi
        int lo, hi, mi;
        //init lo and hi
        lo = 0;
        hi = n-1;
        while(lo < hi)
            {
                //calculates mi
                mi = (lo + hi)>>1;
                //if A[mi] == target, return the answer
                if(A[mi] == target)
                    return mi;
                //if A[mi] is less than target, then, updates lo
                if(A[mi] < target)
                    lo = mi+1;
                //updates hi, hi may be less than 0!!!!
                else
                    hi = mi-1;
            }
        //if all the elements in A[] is less than target
        //such as {{1}, 2}
        if(A[hi] < target)
            ++hi;
        //if hi is less than 0
        //hi will be less than 0 if (lo=0 && hi=1 && A[mi]>=target)
        if(hi<0)
            hi = 0;
        return hi;
    }
};