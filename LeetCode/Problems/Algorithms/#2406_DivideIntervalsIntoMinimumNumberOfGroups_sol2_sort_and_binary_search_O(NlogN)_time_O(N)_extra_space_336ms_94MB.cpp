class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        const int N = intervals.size();

        vector<int> startPoints(N);
        vector<int> endPoints(N);
        for(int i = 0; i < N; ++i){
            startPoints[i] = intervals[i][0];
            endPoints[i] = intervals[i][1];
        }

        sort(startPoints.begin(), startPoints.end());
        sort(endPoints.begin(), endPoints.end());

        int res = 0;
        for(int i = 0; i < N; ++i){
            for(int point: intervals[i]){
                int starts = upper_bound(startPoints.begin(), startPoints.end(), point) - startPoints.begin();
                int ends = lower_bound(endPoints.begin(), endPoints.end(), point) - endPoints.begin();
                int overlappingIntervals = starts - ends;
                res = max(res, overlappingIntervals);
            }
        }

        return res;
    }
};