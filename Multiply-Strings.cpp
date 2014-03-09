class Solution {
public:
    string multiply(string num1, string num2) {
        //@carry: carry of each add 
        int carry=0;
        //@l1: num1's length
        //@l2: num2's length
        int l1 = num1.size();
        int l2 = num2.size();
        //@ret: auxiluray int vector
        vector<int> ret(l1+l2, 0);
        //loop each bit of num1 and num2
        for(int i=l1-1; i>=0; --i)
        {
            int a = num1[i]-'0';//get int value of num1[i]
            for(int j=l2-1; j>=0; --j)
            {
                //int a = num1[i]-'0';
                int b = num2[j]-'0';//get int value of num2[j]
                ret[(l1-1-i)+(l2-1-j)] += a*b;//add a*b to ret[(l1-1-i)+(l2-1-j)] (ret is reverse order)
            }
        }
        //maluplate the carry
        for(int i=0; i<ret.size();++i)
            {
                ret[i] += carry;//add last carry
                carry = ret[i]/10;//update carry
                ret[i] = ret[i]%10;//set the current number
            }
        //@tmp: string we will return 
        string tmp;
        int i=ret.size()-1;
        while(i>=0 && 0==ret[i])//skip all the zeroes ahead the string
            --i;
        if(i<0)///the answer is zero
            tmp.push_back('0');
        else
            {
                for(; i>=0; --i)//add all the char into tmp
                    tmp.push_back(ret[i]+'0');
            }
        //return tmp
        return tmp;
    }
};