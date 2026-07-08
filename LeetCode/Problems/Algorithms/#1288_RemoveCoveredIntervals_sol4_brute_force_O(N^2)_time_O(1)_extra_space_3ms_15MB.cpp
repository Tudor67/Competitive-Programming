class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        const int N = intervals.size();

        int remainingIntervals = N;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(i != j && intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1]){
                    --remainingIntervals;
                    break;
                }
            }
        }

        return remainingIntervals;
    }
};