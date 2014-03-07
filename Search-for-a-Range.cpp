class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        //@ret:  answer we will return
        vector<int> ret;
        //@l: left
        //@r: right
        //@mid: middle point ==> (l+r)/2
        int l, r, mid;
        l=0;
        r=n-1;
        //calculate the range's left boundary
        while(l<r)
        {
            mid = (l+r)>>1;
            if(A[mid] < target)//if target is between [mid+1, r]
                l = mid + 1;
            else//target is between [l, mid], not mid-1, because A[mid] may equal to target.
                r = mid;
        }
        //if target is in A[], set the left boundary
        if(A[r] == target)
            ret.push_back(r);
        else//set the left boundary to -1.
            ret.push_back(-1);
        l=0;
        r=n-1;
        //calculate the range's right boundary
        while(l<r)
        {
            mid = (l+r+1)>>1; //set mid be the (l+r+1)/2, because we will set l to mid,
                              //if mid=(l+r)/2, this may be infinite loop. such as, [2, 2] and target is 2.
            if(target<A[mid])
                r = mid-1;
            else
                {
                    #if 0 //if mid is setted to (l+r)>>1, then this will be ok
                    if(target>A[mid])
                        l = mid+1;
                    else
                    {
                        if(l == mid)
                        {
                            if(A[l] == A[r])
                                l = r;
                            else
                                r = l;
                        }
                        else
                        {
                            l = mid;
                        }
                    }
                    #endif
                    l = mid; //mid is setted to (l+r+1)>>1
                }
        }
        //set the right boundary
        if(A[l] == target)
            ret.push_back(l);
        else
            ret.push_back(-1);
        return ret;
    }
};