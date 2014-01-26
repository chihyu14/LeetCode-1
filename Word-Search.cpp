class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        for(int i=0; i<board.size(); ++i)
        {
            for(int j=0; j<board[0].size(); ++j)
            {
                if(board[i][j] == word[0])
                    {
                        bool t = work(board, i, j, word, 0);
                        if(t)
                            return t;
                    }
            }
        }
        return false;
    }
    bool work(vector<vector<char> > &board, int i, int j, const string& word, int idx)
    {
        //have found the word
        if(idx == word.length())
            return true;
        if(i<0 || i>=board.size())
            return false;
        if(j<0 || j>=board[0].size())
            return false;
        if(!isalpha(board[i][j]))
            return false;
        if(board[i][j] != word[idx])
            return false;
        bool ret = false;
        char ch = board[i][j];
        board[i][j] = '0';
        int next_i, next_j;
        //upper
        next_i = i-1;
        next_j = j;
        ret = work(board, next_i, next_j, word, idx+1);
        if(ret)
            {
                board[i][j] = ch;
                return true;
            }
        //right
        next_i = i;
        next_j = j+1;
        ret = work(board, next_i, next_j, word, idx+1);
        if(ret)
        {
            board[i][j] = ch;
            return true;
        }
        
        //down
        next_i = i+1;
        next_j = j;
        ret = work(board, next_i, next_j, word, idx+1);
        if(ret)
        {
            board[i][j] = ch;
            return true;
        }
        
        //left
        next_i = i;
        next_j = j-1;
        ret = work(board, next_i, next_j, word, idx+1);
        if(ret)
        {
            board[i][j] = ch;
            return true;
        }
        
        
        board[i][j] = ch;
        return false;
    }
};
