class Solution {
public:
    int totalNQueens(int n) {
        //@place[i]: place the queen in row i at col place[i]
        vector<int> place(n+1);
        //@ret: answer we will return
        int ret = 0;
        //set the first row, and search the other row
        for(int i=0; i<n; ++i)
        {
            place[0] = i;
            cal(place, 1, ret, n);
        }
        //return the answer
        return ret;
    }
    //@place: flag vector used avoid the confict of every two queens
    //@row: the current row
    //@ret: answer
    //@n: total rows
    void cal(vector<int> &place, int row, int &ret, const int &n)
    {
        //we have found a answer
        if(n == row)
        {
            ++ret;
            return;
        }
        //place the queen in current row at col i
        for(int i=0; i<n; ++i)
        {
            int j;
            //whethea we can place the queen in current row at col i
            for(j=0; j<row; ++j)
            {
                //we have placed a queen in col i
                if(place[j] == i)
                    break;
                //the current queen will confict with the queen in row j
                if(abs(row-j) == abs(place[j]-i))
                    break;
            }
            //if we could place the queen at col j
            if(j == row)
                {
                    place[row] = i;//place the queen at col j, then, search the next row
                    cal(place, row+1, ret, n);//we don't need to unplace the queen, because we use the same flag vector to store them.
                }
        }
    }
};