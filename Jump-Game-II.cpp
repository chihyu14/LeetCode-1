class Solution {//BFS?
public:
    int jump(int A[], int n) {
        //single number
        if(n==1)
            return 0;
        //@a: queue to store current level numbers and next level numbers
        //first, a[0] is the current queue, then, a[1] is current queue, and so on.
        vector<vector<int> > a(2, vector<int>(n));
        //@used: used[i]=true, number i has been in the queue
        vector<bool> used(n, false);
        //@idx1: length of current level queue
        //@idx2: length of next level queue
        //@sw: flag for current queue
        int idx1, idx2, sw = 0;
        //push 0 in the queue
        a[0][0] = 0;
        idx1 = 0;
        used[0] = true;
        int l = 0;
        //f[0] = 0;
        //while we still have elements in the queue
        while(idx1 >= 0)
        {
            idx2=-1;
            ++l;
            //start from 0 to idx1!!!!!
            //reverse will get TLE
            for(int j=0; j<=idx1; ++j)//(idx1 >= 0)
            {
                int t = a[sw][j];//get current element
                for(int i=A[t]; i>0; --i)//push all elements t can reach to the nexe level queue
                    {
                        if(!used[t+i])
                        {
                            a[1-sw][++idx2] = t+i;
                            used[t+i] = true;
                            if(t+i >= n-1)//reach the final point
                                return l;
                        }
                    }
            }
            //switch current queue
            idx1 = idx2;
            sw = 1-sw;
        }
        return -1;
    }
};