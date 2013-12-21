class Solution {
public:
    void sortColors(int A[], int n) {
        //@one : the numbe of 1 in A[]
        //@zero: the number of 0 in A[]
        int one = 0, zero = 0;
        //calculate zero and one
        for(int i=0; i<n; ++i)
            {
                if(0 == A[i])
                    ++zero;
                if(1 == A[i])
                    ++one;
            }
        int j=zero;
        //this loop will put all the 0 in the right position
        //no matter where 1s and 2s are
        for(int i=0; i<zero; ++i)
            {
                if(0 != A[i])
                    {
                        //find a 0
                        //and swap the two numbers
                        while(j<n && 0 != A[j])
                            ++j;
                        //if(j < n)
                        //    {
                                int t = A[i];
                                A[i] = A[j];
                                A[j] = t;
                        //    }
                    }
            }
        //this sentence is required!!!!
        j = zero+one;
        //this loop will put all the 1s in the right position!!!
        for(int i=zero; i<one+zero;++i)
            {
                if(1 != A[i])
                    {
                        //find an 1
                        //and swap the two numbers
                        while(j<n && 1 != A[j])
                            ++j;
                        //if(j<n)
                        //    {
                                int t = A[i];
                                A[i] = A[j];
                                A[j] = t;
                        //    }
                    }
            }
        //after putting all the 0s and 1s in the right position
        //the 2s are also in the right position!!!!
    }
}; 
