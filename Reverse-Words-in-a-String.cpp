class Solution {
public:
    void reverseWords(string &s) {
        string tmp;//auxiluray string
        //@idx: how many words have been reversed
        //@last: the last index of current word
        int idx = 0, last=s.length();
        //malipulate the ' ' in s
        for(last=s.length()-1; last>=0; --last)
            if(' ' != s[last])
                break;
        if(last<0)//if s only has ' '
            {
                s="";
                return;
            }
        //loop s, reverse all words
        for(int i=last; i>=0; --i)
        {
            if(s[i] == ' ')//find a word
                {
                    int j;
                    if(idx>0)//if it's not the first word in reversed string
                        j = i;
                    else
                        j = i+1;//first word, skip the ' '
                    for(; j<=last; ++j)
                        tmp.append(1,s[j]);
                    last=i-1;//update last
                    while(last>=0)//skip all the empty space
                        {
                            if(' ' != s[last])
                                break;
                            else
                                --last;
                        }
                    ++idx;//update idx
                }
        }
        if(idx && (last>=0))//there is still a word we haven't added to tmp
            tmp.append(" ");
        for(int i=0; i<=last; ++i)//add the last word if there is any.
            tmp.append(1,s[i]);
        s = tmp;//update s
    }
};