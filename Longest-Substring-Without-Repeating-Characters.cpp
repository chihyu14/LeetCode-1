class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //@ret[]: ret[i] ---> the length of substring without repeating charaters end at s[i]
        vector<int> ret(s.length(),1);
        
        for(int i=1; i<s.length(); ++i)
            {
                for(int j=1; j<=ret[i-1]; ++j)
                {//test s[i-ret[i-1]] to s[i-1]
                    if(s[i-j] == s[i])//if duplicates occure
                        break;
                    ++ret[i];//ret[i] pluses one
                }
            }
        //find the *longest* substring without repeating characters
        int max = 0;
        for(int i=0; i<s.length(); ++i)
            if(ret[i] > max)
                max = ret[i];
        //return the answer
        return max;
    }
};