class Solution {
public:
    int search(int A[], int n, int target) {
        int hi, lo, mid;
        hi = n-1;
        lo = 0;
        //find a position i, that [0, i-1] is sorted and [i, n-1] is sorted also.
        while(lo<hi)
        {
            if(A[hi]>A[lo])//[lo, hi] is sorted 
                break;
            mid = (lo+hi)>>1;//calculate the middle position
            if(A[mid]<A[lo])
                hi=mid-1;
            else
                {
                    //if(A[mid]>A[hi])
                        lo = mid+1;
                }
        }
        //if the ordinary array isn't rotated
        if((0 == lo) && (n-1 == hi))
        {
            mid = 0;
        }
        else
        {
            if(0 != lo)
            {//[0, lo-1] and [lo, n-1] are sorted array.
                if(A[hi]<A[lo-1])
                    mid = lo;
                else
                    mid = hi+1;//[0, hi] and [hi+1, n-1] are sorted array.
            }
            else
            {
                mid = hi+1;//[0, hi] and [hi+1], n-1] are sorted array.
            }
        }
        if(0 == mid)//if ordinary array isn't rotated.
            return search(A, 0, n-1, target);
        else
        {
            if(target>=A[0])//if target is between A[0] and A[mid-1]
                return search(A, 0, mid-1, target);
            else//target is between A[mid] and A[n-1]
                return search(A, mid, n-1, target);
        }
    }
    int search(int A[], int lo, int hi, int target)
    {
        int mid;
        while(lo<=hi)
        {
            mid = (lo+hi)>>1;
            if(A[mid] == target)
                return mid;
            if(A[mid]>target)
                hi = mid-1;
            else
                lo = mid+1;
        }
        return -1;
    }
};
