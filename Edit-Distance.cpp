class Solution {
public:
    int minDistance(string word1, string word2) {
        if(0 == word1.length())
            return word2.length();
        if(0 == word2.length())
            return word1.length();
        vector<vector<int> > f(word1.length()+2, vector<int>(word2.length()+2, 0));
        //be careful!!!!!
        //i and j begin from *1* to str's lenght!!!!!
        //because f[i][j] is distance of word1[0...(i-1)] and word2[0...(j-1)]
        for(int i=1; i<=word1.length(); ++i)
            f[i][0] = i;
        for(int i=1; i<=word2.length(); ++i)
            f[0][i] = i;
        
        for(int i=0; i<word1.length(); ++i)
        {
            for(int j=0; j<word2.length(); ++j)
            {
                if(word1[i] == word2[j])//f[i+1][j+1] = f[i][j]
                    f[i+1][j+1] = f[i][j];
                else
                    {
                        //no insertion,!!!!!
                        int a = f[i][j+1]+1;//delete
                        int b = f[i+1][j]+1;//delete
                        int c = f[i][j]+1;//replace
                        f[i+1][j+1] = min(min(a,b),c);//update f[i+1][j+1]
                    }
            }
        }
        //return answer
        return f[word1.length()][word2.length()];
    }
};
