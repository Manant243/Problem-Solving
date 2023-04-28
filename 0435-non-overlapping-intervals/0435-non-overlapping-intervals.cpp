class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int erased_intervals = 0;
        int previous_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < previous_end) {
                erased_intervals++;
                previous_end = min(previous_end, intervals[i][1]);
            } else {
                previous_end = intervals[i][1];
            }
        }
        return erased_intervals;
    }
};