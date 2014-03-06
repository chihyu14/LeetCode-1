class Solution {
public:
    bool canJump(int A[], int n) {
        //@single number
        if(1 == n)
            return true;
        //@right: the rightest position we can go, init to 0
        int right = 0;
        //@loop every position, merge interval, update right
        for(int i=0; i<n;++i)
        {
            if(i<=right)//i is in the current interval we can go
                right = max(right, i+A[i]);//update the interval if we can go further
        }
        return (right >= (n-1));//if we can go to the end position
    }
};