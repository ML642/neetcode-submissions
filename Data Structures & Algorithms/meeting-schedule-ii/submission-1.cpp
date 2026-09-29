/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const Interval& first,const Interval& second ){
            return first.start<second.start;
        });
        int count = 0;
        int answer = 0;
        priority_queue<int,vector<int>,greater<int>> min_heap;  

        for(int i=0;i<intervals.size();i++){

            if(!min_heap.empty() && intervals[i].start >= min_heap.top()){
                min_heap.pop();
            }
            min_heap.push(intervals[i].end);
            
            answer = max(answer,(int)min_heap.size());
        }
        return answer;

    }
};
