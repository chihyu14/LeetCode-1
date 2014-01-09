class Solution {
public:
    int removeDuplicates(int A[], int n) {
        //@first: element first appears in the array
        //@second: we use this parament to remove duplicates
        //@idx: the length we will return
        int first, second;
        int idx=0;
        for(first=0; first<n; )
            {
                //copy A[first] to A[idx]
                A[idx++] = A[first];
                second = first+1;
                //if A[first] == A[second], copy A[second] to A[idx] and move to the next element
                if(second<n && A[first]==A[second])
                    {
                        A[idx++] = A[second];
                        ++second;
                    }
                //pass over all the duplicates 
                while(second<n && A[second] == A[first])
                    ++second;
                //update first
                first = second;
            }
        //return the length
        return idx;
    }
};