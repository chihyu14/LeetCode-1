class Solution {
public:
    //read http://en.wikipedia.org/wiki/Roman_numerals for more details
    int romanToInt(string s) {
        //@ret: answer we will return 
        int ret = 0;
        //@len: the length of s
        int len = s.length();
        //process each character in s
        for(int i=0; i<len; ++i)
            {
                switch(s[i])
                    {
                        //if s[i] == 'I'
                        case 'I':
                            if(i+1<len)
                                {
                                    //'IV'
                                    if('V' == s[i+1])
                                        {
                                            ret += 4;
                                            ++i;    //skip 'V'
                                        }
                                    else
                                        {
                                            //'IX'
                                            if('X' == s[i+1])
                                                {
                                                    ret += 9;
                                                    ++i;    //skip 'X'
                                                }
                                            else    //other
                                                ret += 1;
                                        }
                                }
                            else    //other
                                ret += 1;
                            break;
                        case 'V':   //'V'
                            ret += 5;
                            break;
                        case 'X':
                            //if s[i] == 'X'
                            if(i+1 < len)
                                {
                                    //'XL'
                                    if('L' == s[i+1])
                                        {
                                            ret += 40;
                                            ++i;    //skip 'L'
                                        }
                                    else
                                        {
                                            //'XC'
                                            if('C' == s[i+1])
                                                {
                                                    ret += 90;
                                                    ++i;    //skip 'C'
                                                }
                                            else    //other
                                                ret += 10;
                                        }
                                }
                            else    //other
                                ret += 10;
                            break;
                        case 'L':   //'L'
                            ret += 50;
                            break;
                        case 'C':
                            //if s[i] == 'C'
                            if(i+1 < len)
                                {
                                    //'CD'
                                    if('D' == s[i+1])
                                        {
                                            ret += 400;
                                            ++i;    //skip 'D'
                                        }
                                    else
                                        {
                                            //'CM'
                                            if('M' == s[i+1])
                                                {
                                                    ret += 900;
                                                    ++i;    //skip 'M'
                                                }
                                            else    //other
                                                ret += 100;
                                        }
                                }
                            else    //other
                                ret += 100;
                            break;
                        case 'D':   //'D'
                            ret += 500;
                            break;
                        case 'M':   //'M'
                            ret += 1000;
                            break;
                    }
            }
        //return the answer
        return ret;
    }
};