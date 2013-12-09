//Solution 1: O(n)
class Solution {
public:
    int maxSubArray(int A[], int n) {
        //if A has only one element
        //return it
        if(n==1)
            return A[0];
        //ret: the answer we will return
        //last: the maximum subarray end at the current index
        int ret = INT_MIN;
        int last = 0;
        for(int i=0; i<n; ++i)
        {
            //if last is less than 0
            //update last to A[i], no matter A[i] is positive or negative
            if(A[i]+last < A[i])
                last = A[i];
            else
            //update last to A[i] + last
                last = A[i] + last;
            //if last is bigger than ret(the answer), update it
            if(last > ret)
                ret = last;
        }
       return ret;
    }
};

//Solution 2: divide and conquer