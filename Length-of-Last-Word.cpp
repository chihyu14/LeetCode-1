class Solution {
public:
    int lengthOfLastWord(const char *s) {
        //find vector rbegin
        //
        //@len the biggest index of s
        int len = strlen(s)-1;
        int i;
        //find the rightest no-space character
        while(len >= 0 && s[len] == ' ')
            --len;
        i = len;
        //find a space or the start of the string
        while(i >= 0)
            {
                if(s[i] == ' ')
                    break;
                --i;
            }
        //++i;
        //return the answer
        return len-i;
    }
}; 
