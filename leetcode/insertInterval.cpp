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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans(intervals.begin(),intervals.end());
        if(ans.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        if(newInterval.start<=ans[0].start){//插入到头部时
            ans.insert(ans.begin(),newInterval);
            
        }else{
            int newstart = newInterval.start;
            for(int i=0;i<ans.size();i++){
                if(ans[i].start<=newstart&&(i+1==ans.size()||ans[i+1].start>=newstart))//找到插入的位置i+1
                    ans.insert(ans.begin()+i+1,newInterval);
            }
        }
        return merge(ans);
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        for(int i=0;i<intervals.size();){
            Interval tmp(intervals[i].start,intervals[i].end);
            int j=i+1;
            for(;j<intervals.size();j++){
                if(intervals[j].start>tmp.end)
                    break;
                else{
                    if(intervals[j].end>tmp.end)
                        tmp.end = intervals[j].end;
                }
            }
            ans.push_back(tmp);
            i = j;
        }
        return ans;
    }
};