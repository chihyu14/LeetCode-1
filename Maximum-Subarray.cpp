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

//Solution 2: divide and conquers 
class Solution {
public:
    int maxSubArray(int A[], int n) {
        ///use diveide and conquer
        return divideandconquer(A, 0, n-1);
    }
    //divide and conquer function
    //@A: the array
    //@l: the leftest index
    //@h: the rightest index
    int divideandconquer(int A[], int l, int h)
        {
            //l == h, return directly
            if(l == h)
                return A[l];
            //@ret: answer we will return
            //we divide A[l,h] to two subarrays
            //A[l,mid] && A[mid+1, h],
            //the maximum subarray is either in the left subarray
            //or the right subarray, or cross the mid-point
            int ret = INT_MIN;
            int mid = (l+h)>>1, t;
            ///get the maximum subarray of the left subarray
            t = divideandconquer(A,l,mid);
            //update ret
            if(t > ret)
                ret = t;
            //get the maximum subarray of the right subarray
            t = divideandconquer(A,mid+1,h);
            //update ret
            if(t > ret)
                ret = t;
            //get the maximum subarray if it crosses the mid-point
            t = crossmax(A, l, mid, h);
            //update ret
            if(t > ret)
                ret = t;
            return ret;
        }
    //get the maximum subarray of A[l,h], and, it crosses
    //the mid-point!!!
    int crossmax(int A[], int l, int mid, int h)
        {
            //the left maximum sum including A[mid]
            int left_ret = INT_MIN;
            int sum = 0;
            //get the maximum subarray A[i, mid]
            //i from mid to l
            for(int i=mid;i>=l;--i)
                {
                    sum += A[i];
                    if(left_ret < sum)
                        left_ret = sum;
                }
            sum = 0;
            //same as above
            int right_ret = INT_MIN;
            //get the maximum subarray A[mid+1, j]
            //j form mid+1 to h
            for(int i=mid+1;i <=h; ++i)
                {
                    sum += A[i];
                    if(right_ret < sum)
                        right_ret = sum;
                }
            //return the answer
            return left_ret + right_ret;
        }
};
