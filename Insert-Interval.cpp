/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        //first insert newInterval into the sorted interval
        //then union all interval that overlapped each other
        vector<Interval> tmp;
        bool used = false;
        for(int i=0; i<intervals.size(); ++i)
        {
            if(!used && newInterval.start < intervals[i].start)
            {
                tmp.push_back(newInterval);
            }
            tmp.push_back(intervals[i]);
        }
        if(!used)
        {
            tmp.push_back(newInterval);
        }
        vector<Interval> ret;
        //union all intervals that overlapped each other
        for(int i=0; i<tmp.size()-1; ++i)
        {
            if(tmp[i].end>=tmp[i+1].start)
            {
                tmp[i+1].start = tmp[i].start;
                tmp[i+1].end = max(tmp[i].end, tmp[i+1].end);
            }
            else
            {
                ret.push_back(tmp[i]);
            }
        }
        ret.push_back(tmp[tmp.size()-1]);
        return ret;
    }
};