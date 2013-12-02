class Solution {
public:
    int numTrees(int n) {
        //init the ans with two one.
        //ans[0] = 1 && ans[1] = 1
        static vector<int> ans(2, 1);
        //if ans[n] hasn't been calculated
        if(n >= ans.size())
            {
                //calculates the answer from ans[ans.size()] to ans[n]
                for(int i=ans.size(); i<=n; ++i)
                    {
                        //tmp: ans for i
                        int tmp = 0;
                        //f(n) = sigma{f(i-1) * f(n-i)}(1<= i <= n)
                        for(int j=1;j<=i;++j)
                            tmp += ans[j-1]*ans[i-j];
                        //update the answer
                        ans.push_back(tmp);
                    }
            }
        //return answer[n]
        return ans[n];
    }
}; 
