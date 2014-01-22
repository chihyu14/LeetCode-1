class Solution {
public:
    string convert(string s, int nRows) {
        //special case
        if(1 == nRows)
            return s;
        string ret;
        int len = s.length();
        //dRows = (nRows*2)
        int dRows = (nRows<<1)-2; //auxiliray value
        //first row
        for(int i=0; ; ++i)
        {
            int t = i*(dRows)+1 -1;//"-1" changes 1-base to 0-base
            if(t>=len)
                break;
            ret.push_back(s[t]);
        }
        //second row to row but
        for(int i=1; i<nRows-1; ++i)
        {
            for(int j=0; ;++j)
            {
                int l = j*(dRows)+(i+1); //"+1" changes 0-base to 1-base
                int r = ((j<<1) + 1)*(dRows)+2;

                //cout << (j<<1+1) << ":" << dRows << ":" <<i <<":"<< "(:" << l <<")" << "(" << r << ":)" ;
                r -= l;
                --l; --r;//"-1" changes 1-base to 0-base
                //cout << "(" << l <<")"<< s[l] << "(" << r << ")" << s[r];
                if(l>=len)
                    break;
                ret.push_back(s[l]);
                if(r >= len)
                    break;
                ret.push_back(s[r]);
            }
        }
        //last row
        for(int i=0; ;++i)
        {
            int t=i*(dRows)+nRows -1;
            if(t>=len)
                break;
            ret.push_back(s[t]);
        }
        //ret.push_back('\0');
        //cout << endl;
        return ret;
    }
};
