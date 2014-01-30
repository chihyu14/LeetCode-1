/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 //comparet function
 bool mycmp(Interval a, Interval b)
    {
        if(a.start<b.start)
            return true;
        if(a.start==b.start)
            return a.end<b.end;
        return false;
    }
class Solution {
public:
    
    vector<Interval> merge(vector<Interval> &intervals) {
        //special case
        if(intervals.size() < 2)
            return intervals;
        //sort intervals[]
        sort(intervals.begin(), intervals.end(), mycmp);
        vector<Interval> ret;
        Interval first(intervals[0]);
        for(int i=1; i<intervals.size(); ++i)
        {//merge overlapping intervals
            Interval tmp(intervals[i]);
            if(tmp.start>first.end)
            {//don't overlapping
                ret.push_back(first);
                first = tmp;
            }
            else
            {//merge overlapping intervals
                first.end = max(first.end, tmp.end);
            }
        }
        ret.push_back(first);
        return ret;
    }
};
