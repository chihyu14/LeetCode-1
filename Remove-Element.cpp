class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        //scan all element
        for(int i=0; i<n; ++i)
            {
                //if A[i] equals to elem,
                //delete it, and move the last element to here
                if(elem == A[i])
                    {
                        A[i] = A[n-1];//A[n-1] is the last one currently.
                        --n;        //the length of the array minus one
                        --i;        //i minuses one to test the whether the last element euquals to elem
                    }
            }
        return n;   //return the length
    }
}; 
