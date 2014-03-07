class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        //@ret: answer we will return
        vector<vector<string> > ret;
        //@used: used[i] => col i is used or not
        vector<bool> used(n, false);
        //@place: place[i] => put the queen in row i at col place[i]
        vector<int> place(n);
        //loop the first row
        for(int i=0; i<n; ++i)
        {
            used[i] = true;
            place[0] = i;
            work(ret, 1, n, used, place);
            used[i] = false;
        }
        return ret;
    }
    //@ret: answer
    //@lev: the current row index
    //@n: the total rows
    //@used: same as above
    //@place: same as above
    void work(vector<vector<string> > &ret, int lev, int n, vector<bool> &used, vector<int> &place)
    {
        if(lev == n)
        {//we have found a solution
            vector<string> add;
            string str(n,'.');
            for(int i=0; i<n; ++i)
            {
                str[place[i]] = 'Q';
                add.push_back(str);
                str[place[i]] = '.';
            }
            ret.push_back(add);
        }
        for(int i=0; i<n; ++i)//col i
        {
            if(used[i])//this col has been used
                continue;
            int j;
            for(j=0; j<lev; ++j)//row j
            {
                if(abs(lev-j) == abs(i-place[j])) // conflict
                    break;
            }
            if(j == lev)///could place the queen in current row at col i
            {
                place[lev] = i;
                used[i] = true;
                work(ret, lev+1, n, used, place);
                used[i] = false;
            }
        }
    }
};