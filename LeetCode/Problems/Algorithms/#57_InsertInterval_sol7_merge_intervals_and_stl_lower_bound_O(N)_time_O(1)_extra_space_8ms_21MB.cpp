class Solution {
private:
    bool intersects(const vector<int>& A, const vector<int>& B){
        return max(A[0], B[0]) <= min(A[1], B[1]);
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int N = intervals.size();

        for(int i = 0; i < N; ++i){
            if(intersects(newInterval, intervals[i])){
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        int i = lower_bound(intervals.begin(), intervals.end(), vector<int>{newInterval[0], newInterval[0]}) - intervals.begin();
        int j = lower_bound(intervals.begin(), intervals.end(), vector<int>{newInterval[1] + 1, newInterval[1] + 1}) - intervals.begin();
        
        vector<vector<int>> newIntervals;
        copy(intervals.begin(), intervals.begin() + i, back_inserter(newIntervals));
        newIntervals.push_back(newInterval);
        copy(intervals.begin() + j, intervals.end(), back_inserter(newIntervals));

        return newIntervals;
    }
};