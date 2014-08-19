class Solution {
public:
    void solve(vector<vector<char> > &board) {
        //empty board
        if(0 == board.size())
            return;
        //@used: used[i][j] : board[i][j] has been reached or not
        vector<vector<bool> > used(board.size(), vector<bool>(board[0].size(), false));
        //@st: a queue
        vector<int> st(board.size() * board[0].size());
        //@r: row of board
        //@c: col of board
        //@front,@end:  two points of queue
        int r = board.size();
        int c = board[0].size();
        int front = 0, end=0;;
        //@flag: the current region will change to 'X' or not
        bool flag = true;
        //@x,y: direction addtion
        int x[] = {-1,0,1,0};
        int y[] = {0,1,0,-1};
        //multiply each cell
        for(int i=0; i<board.size(); ++i)
        {
            for(int j=0; j<board[i].size(); ++j)
            {
                //if current cell is 'O' and hasn't been reached.
                if('O' == board[i][j] && !used[i][j])
                    {
                        //work(board, used, i, j);        
                        front = end = 0;
                        st[front++] = i*c+j;//push the current node into st
                        used[i][j] = true;
                        flag = true;
                        //find the whole region
                        while(end<front)
                        {
                            int cur = st[end++];//get a node front st
                            int ii = cur/c;
                            int jj = cur%c;
                            if(ii==0 || ii==r-1 || jj==0 || jj==c-1)//if cur is at the board of the board
                                flag = false;
                            int next_x, next_y;
                            for(int k=0; k<4; ++k)//add the four neighbors if needed
                            {
                                next_x = ii+x[k];
                                next_y = jj+y[k];
                                if(next_x>=0 && next_x < r && next_y>=0 && next_y <c && !used[next_x][next_y] && board[next_x][next_y] == 'O')
                                {
                                    st[front++] = next_x * c + next_y;
                                    used[next_x][next_y] = true;
                                }
                            }
                        }
                        if(flag)//change the current region to 'X' if needed
                        {
                            for(int k=0; k<front; ++k)
                            {
                                int next_x = st[k]/c;
                                int next_y = st[k]%c;
                                board[next_x][next_y] = 'X';
                            }
                        }
                    }
            }
        }
        
    }
};