class Solution {
public:
    string getPermutation(int n, int k) {
        //empty string
        if(0 == n)
            return string();
        //@ret: answer we will return
        string ret;
        //@used[i]: number i is used or not
        vector<bool> used(n+1, false);
        //@p[i]: permutation of i ==> i!
        int p[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        //@sum: auxilary var
        int sum = 0;
        //set all bits
        for(int i=n-1; i>=0; --i)
        {
            int t = 0, j;
            //find the right number we will place at current index
            while(sum + t*p[i] < k)
                ++t;
            sum += (t-1)*p[i];//update sum
            //find the t-th smallest number that hasn't been used
            for(j=1; t; ++j)
                if(!used[j])
                    --t;
            //place this number at current index
            //set it to used!!!
            used[j-1] = true;
            ret.push_back('0' + j-1);
        }
        //return the answer
        return ret;
    }
}; 
