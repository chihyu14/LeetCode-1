class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        //special case
        if(num.size() < 1)
            return 0;
        //store num in the set
        set<int> temp;
        for(int i=0; i<num.size(); ++i)
            temp.insert(num[i]);
        //@ret: answer will return
        int ret = 1;
        set<int>::iterator ite = temp.begin();
        while(ite != temp.end())
        {
            set<int>::iterator next = ite;
            ++next;
            int l = 1;
            //find the Consecutive Sequence from ite
            while((next != temp.end()) && (*next - *ite) == l)
                {
                    ++l;
                    ++next;
                }
            if(l>ret)//if current consecutive sequence's length bigger than ret
                ret = l;
            ite = next;//update ite
        }
        return ret;//return the answer
    }
};