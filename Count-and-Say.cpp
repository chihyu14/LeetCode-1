class Solution {
public:
    string countAndSay(int n) {
        //[string -> string ] run the loop
        string str1("1");
        for(int i=1; i< n; ++i)
        {
            string str2;
            for(int first=0; first<str1.length(); )
                {
                    int second=first+1;
                    for(; second<str1.length(); ++ second)
                        {
                            if(str1[second] != str1[first])
                                break;
                        }
                    str2.push_back(second-first+'0');
                    str2.push_back(str1[first]);
                    first = second;
                }
            str1 = str2;
        }
        return str1;
    }
};