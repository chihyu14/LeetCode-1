//solution 1
class Solution {
public:
    string intToRoman(int num) {
        string ret;
        while(num)
            {
                if(num>=1000)   //>=1000
                    {
                        ret += "M";
                        num -= 1000;
                    }
                else
                    {
                        if(num >= 900)  //[900, 1000)
                            {
                                ret += "CM";
                                num -= 900;
                            }
                        else
                            {
                                if(num >= 500)  //[500, 899]
                                    {
                                        ret += "D";
                                        num -= 500;
                                    }
                                else
                                    {
                                        if(num >= 400)  //[400, 499]
                                            {
                                                ret += "CD";
                                                num -= 400;
                                            }
                                        else
                                            {
                                                if(num >= 100)  //[100, 399]
                                                    {
                                                        ret += "C";
                                                        num -= 100;
                                                    }
                                                else
                                                    {
                                                        if(num >= 90)//[90, 99]
                                                            {
                                                                ret += "XC";
                                                                num -= 90;
                                                            }
                                                        else
                                                            {
                                                                if(num >= 50)   //[50, 89]
                                                                    {
                                                                        ret += "L";
                                                                        num -= 50;
                                                                    }
                                                                else
                                                                    {
                                                                        if(num >= 40)   //[40, 49]
                                                                            {
                                                                                ret += "XL";
                                                                                num -= 40;
                                                                            }
                                                                        else
                                                                            {
                                                                                if(num >= 10)   //[10, 39]
                                                                                    {
                                                                                        ret += "X";
                                                                                        num -= 10;
                                                                                    }
                                                                                else
                                                                                    {
                                                                                        if(num >= 9)    //[9, 9]
                                                                                            {
                                                                                                ret += "IX";
                                                                                                num -= 9;
                                                                                            }
                                                                                        else
                                                                                            {
                                                                                                if(num >= 5)    //[5, 8]
                                                                                                    {
                                                                                                        ret += "V";
                                                                                                        num -= 5;
                                                                                                    }
                                                                                                else    
                                                                                                    {
                                                                                                        if(num >= 4)    //[4,4]
                                                                                                            {
                                                                                                                ret += "IV";
                                                                                                                num -= 4;
                                                                                                            }
                                                                                                        else
                                                                                                            {   //[1,3]
                                                                                                                ret += "I";
                                                                                                                num -= 1;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
        return ret;
    }
};
//solution 2
//int f[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000}
//while(num > f[i])
//    ....