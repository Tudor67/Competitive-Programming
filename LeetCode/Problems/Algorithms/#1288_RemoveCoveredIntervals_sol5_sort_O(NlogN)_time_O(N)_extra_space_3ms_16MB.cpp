class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        const int N = intervals.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (intervals[lhs][0] < intervals[rhs][0]) ||
                       (intervals[lhs][0] == intervals[rhs][0] && intervals[lhs][1] > intervals[rhs][1]);
             });

        int remainingIntervals = N;
        int maxEnd = INT_MIN;
        for(int i: p){
            if(intervals[i][1] <= maxEnd){
                --remainingIntervals;
            }else{
                maxEnd = intervals[i][1];
            }
        }

        return remainingIntervals;
    }
};