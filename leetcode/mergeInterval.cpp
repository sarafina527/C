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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        sort(intervals.begin(),intervals.end(),IntervalCMP);
        print(intervals);
        for(int i=0;i<intervals.size();){
        	Interval tmp(intervals[i].start,intervals[i].end);
        	int j=i+1;
        	for(;j<intervals.size();j++){
        	    //cout<<tmp.end<<" "<<intervals[j].start<<endl;
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
    static bool IntervalCMP(Interval in1,Interval in2){
    	return in1.start<in2.start;
    }
    void print(vector<Interval> &intervals){
    	for(int i=0;i<intervals.size();i++){
    		cout<<'['<<intervals[i].start<<','<<intervals[i].end<<']'<<',';
    	}
    	cout<<endl;
    }
};