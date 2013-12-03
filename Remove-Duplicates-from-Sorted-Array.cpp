 
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        //the first position
        int first = 0;
        //the length we return
        int ret = 0;
        //if first is less than n
        while(first < n)
            {
                //second is the position will compare with first
                int second = first + 1;
                //if second is less than n and A[first] == A[second]
                //second moves forward a step
                while((second < n) && (A[first] == A[second]))
                    ++second;
                //adjust the array, so that the first ret elements are the answer
                A[ret] = A[first];
                //the length plus 1
                ++ret;
                //updates first, the next position to progress
                first = second;
            }
        //return the answer
        return ret;
    }
};