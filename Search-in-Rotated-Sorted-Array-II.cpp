Solution-I:
class Solution {
public:
    bool search(int A[], int n, int target) {
        //loop the vector A[], find if target in A[] or not
        for(int i=0; i<n; ++i)
            if(A[i] == target) //some element equals to target
                return true;
        return false;//no elements equals to target
    }
};
Solution-II:
class Solution {
public:
    bool search(int A[], int n, int target) {
        int l=0, r=n-1;
        int m;
        while(l<=r)
        {
            m = (l+r)>>1;
            if(A[m] == target)
                return true;
            if(A[l]<A[m])//left part is sorted
            {
                if(A[l]<=target && target<=A[m])
                    r = m-1;
                else
                    l = m+1;
            }
            else
            {
                if(A[m]<A[r])//right part is sorted
                {
                    if(A[m]<=target && target<=A[r])
                        l = m+1;
                    else
                        r = m-1;
                }
                else
                {
                    if(A[l] == target)//if A[l] equals to target or not
                        return true;
                    ++l;//increase l
                }
            }
        }
        return false;
    }
};
Solution-III:
class Solution {
public:
    bool search(int A[], int n, int target) {
        int l=0, r=n-1;
        int m;
        while(l<=r)
        {
            m = (l+r)>>1;
            if(A[m] == target)
                return true;
            if(A[l]<A[m])//left part is sorted
            {
                if(A[l]<=target && target<=A[m])
                    r = m-1;
                else
                    l = m+1;
            }
            else
            {
                if(A[m]<A[r])//right part is sorted
                {
                    if(A[m]<=target && target<=A[r])
                        l = m+1;
                    else
                        r = m-1;
                }
                else
                {
                    if(A[m] == A[l] && A[m] != A[r])//A[m] to A[l] must be identical
                        l = m+1;
                    else
                        {
                            if(A[m] != A[l] && A[m] == A[r])//A[m] to A[r] must be identical
                                r = m-1;
                            else//search both parts
                            {
                                ++l;
                                --r;
                            }
                        }
                }
            }
        }
        return false;
    }
};