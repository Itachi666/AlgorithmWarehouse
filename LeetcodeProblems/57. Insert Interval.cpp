// Runtime: 28 ms
// Memory Usage: 10.2 MB

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
    static bool Cmpare(const Interval & a,const Interval & b)           
    {
         return (a.start < b.start);
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> answer;
        
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), Solution::Cmpare);
        
        Interval k=intervals[0];
        for (int i=1;i<intervals.size();i++)
            if (k.end<intervals[i].start)
            {
                answer.push_back(k);
                k=intervals[i];
            }
            else
                k.end=max(intervals[i].end, k.end);
        answer.push_back(k);
        
        return answer;
    }
};