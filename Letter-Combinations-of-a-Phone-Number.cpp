class Solution {
private:
    //vector<vector<char> > num2ch(10, vector<char>(5));//vector<char>(5, ' '));
    char num2ch[10][6];//map number ---> char
    void init()
    {
        //0:' '
        num2ch[0][0] = 1;
        num2ch[0][1] = ' ';
        //1:??????
        num2ch[1][0] = 1;
        num2ch[1][1] = '@';
        //2:abc
        num2ch[2][0] = 3;
        num2ch[2][1] = 'a';
        num2ch[2][2] = 'b';
        num2ch[2][3] = 'c';
        //3:def
        num2ch[3][0] = 3;
        num2ch[3][1] = 'd';
        num2ch[3][2] = 'e';
        num2ch[3][3] = 'f';
        //4:ghi
        num2ch[4][0] = 3;
        num2ch[4][1] = 'g';
        num2ch[4][2] = 'h';
        num2ch[4][3] = 'i';
        //5:jkl
        num2ch[5][0] = 3;
        num2ch[5][1] = 'j';
        num2ch[5][2] = 'k';
        num2ch[5][3] = 'l';
        //6:mno
        num2ch[6][0] = 3;
        num2ch[6][1] = 'm';
        num2ch[6][2] = 'n';
        num2ch[6][3] = 'o';
        //7:pqrs
        num2ch[7][0] = 4;
        num2ch[7][1] = 'p';
        num2ch[7][2] = 'q';
        num2ch[7][3] = 'r';
        num2ch[7][4] = 's';
        //8:tuv
        num2ch[8][0] = 3;
        num2ch[8][1] = 't';
        num2ch[8][2] = 'u';
        num2ch[8][3] = 'v';
        //9:wxyz
        num2ch[9][0] = 4;
        num2ch[9][1] = 'w';
        num2ch[9][2] = 'x';
        num2ch[9][3] = 'y';
        num2ch[9][4] = 'z';
    }
public:
    vector<string> letterCombinations(string digits) {
        init();//init the map
        string t(digits.length(), ' ');//string
        vector<string> ret;//answer
        work(ret, digits, 0, t);
        return ret;
    }
    //@ret: answer will return
    //@digits: ordinary string(number)
    //@idx: current index of digits we have scanned
    //@str: string of each answer
    void work(vector<string> &ret, string &digits, int idx, string &str)
    {
        if(idx == digits.length())
        {//add this answer
            ret.push_back(str);
            return;
        }
        //@k: number
        int k=digits[idx] - '0';
        for(int i=1; i<=num2ch[k][0]; ++i)
        {
            str[idx] = num2ch[k][i];//set this bit
            work(ret, digits, idx+1, str);
        }
    }
};
