class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int len = strlen(needle);
        int s = strlen(haystack);
        if(len == 0 && s == 0)
            return haystack;
        vector<int> next(len+1);
        int p, q;
        next[0] = -1;
        next[1] = 0;
        //calculat next[]
        for(int i=1; i<len; ++i)
        {
            p = i;
            q = next[i];  // q = next[i-1+1], we have the first i-1 characters match, and the +1 is the function of next and needle index
            while(q>=0)   // find the maximum common length of the biginning and the end of the first i+1 characters
            {
                if(needle[q] == needle[p])//find one
                    break;
                q = next[q];
            }
            next[i+1] = q+1;   //adjust the index (including the -1)
        }
        p = 0;
        q = 0;
        while(p < s)
        {
            //skip all the matched characters
            while(p < s && q < len && haystack[p] == needle[q])
            {
                ++q;
                ++p;
            }
            //find one match
            if(q == len)
                return haystack+p-q;
            //test all of the characters
            if(p == s)
                return NULL;
            q = next[q];//q = next[q-1+1]  其中 q-1 表示前 q-1 各字符都匹配好了，+1 表示 next 数组 needle 的对应关系
            if(q<0)
            {
                ++p;
                ++q;
            }
        }
        return NULL;
    }
}; 
