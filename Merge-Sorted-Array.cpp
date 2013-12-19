class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        //A is empty!!!!
        //if(0 == m)
        //    {
                //copy all the elements of B to A
        //        for(int i=0; i<n; ++i)
        //            A[i] = B[i];
        //        return;
        //    }
        //put all the elements into A from big to small
        //@idx: current index of the new sorted array(right-most)
        //@m: the index of the A[] we have processed from right to left
        //@n: the index of the B[] we have processed from right to left
        int idx = m+n-1;
        --m;
        --n;
        //while m>=0 && n >=0
        //m == idx means we don't need to process anymore!!!
        while((m>=0) && (n>=0) && (m != idx))
            {
                //if A[m] > B[n]
                if(A[m] > B[n])
                    {
                        A[idx] = A[m];
                        --m;
                    }
                else
                    {//A[m] <= B[n]
                        A[idx] = B[n];
                        --n;
                    }
                --idx;
            }
        //while B has not been fully processed 
        //copy the remainder elements in B[] to A[]
        while(n>=0)
            {
                A[n] = B[n];
                --n;
            }
    }
}; 
