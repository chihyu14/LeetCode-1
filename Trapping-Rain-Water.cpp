class Solution {
public:
    int trap(int A[], int n) {
        //@ret: answer
        int ret = 0;
        //@s: start of the array
        //@e: end of the array
        int s, e;
        //find the first node bigger than the next node
        for(s =0; s<n-1; ++s)
        {
            if(A[s] > A[s+1])
                break;
        }
        //find the last node bigger than the before node
        for(e=n-1; e>0; --e)
        {
            if(A[e] > A[e-1])
                break;
        }
        //travel from right to left
        if(A[s]>A[e])
            travel_left(s, e, ret, A);
        else//travel from left to right
            travel_right(s, e, ret, A);
        return ret;
    }
    //travel from right to left[e--->s], the answer added to ret
    void travel_left(int s, int e, int &ret, const int A[])
    {//travel to left
        for(int i=e; i>=s; --i)
            {
                if(A[i] > A[e])
                    {//if A[i] > A[e]
                     //update e, then, travel the rest array
                        e = i;
                        if(A[s] > A[e])
                            travel_left(s, e, ret, A);
                        else
                            travel_right(s, e, ret, A);
                        break;//break the loop!!!!!!
                    }
                else
                    {
                        ret += A[e]-A[i];//added to ret(the answer)
                    }
            }
    }
    //travel from left to right[s--->e], the answer added to ret
    void travel_right(int s, int e, int &ret,const int A[])
    {//travel to right
        for(int i=s; i<=e; ++i)
        {
            if(A[i] > A[s])
            {//if A[i] > A[s], update s, then travel the rest array
                s = i;
                if(A[s] > A[e])
                    travel_left(s, e, ret, A);
                else
                    travel_right(s, e, ret, A);
                break;//break the loop!!!!!!!!!!
            }
            else
            {//added to ret(the answer)
                ret += A[s]-A[i];
            }
        }
    }
};
