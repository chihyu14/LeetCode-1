class Solution {
public:
    int maxArea(vector<int> &height) {
        //@tmp: tmp[i] store all the x-value of height i
        map<int, set<int> > tmp;
        for(int i=0; i<height.size(); ++i)//init tmp
        {
                tmp[height[i]].insert(i);
        }
        //@left: leftmost x-value of who's height is not less than current height
        //@right: rightmost x-value of who's height is not less than current height
        //@max: answer
        int left, right, max=0;
        //init left and right
        left = INT_MAX;
        right = INT_MIN;
        //loop all heights,
        for(map<int,set<int> >::reverse_iterator ite=tmp.rbegin(); ite!=tmp.rend(); ++ite)
        {
               //find the left, and right of the current height
                set<int>::iterator first=ite->second.begin();
                set<int>::reverse_iterator last=ite->second.rbegin();
                //update left and right if needed.
                if(*first<left)
                    left = *first;
                if(*last>right)
                    right = *last;
                //update max if needed.
                if(max < (right-left)*ite->first)
                    max = (right-left)*ite->first;
        }
        //return the answer
        return max;
    }
}; 