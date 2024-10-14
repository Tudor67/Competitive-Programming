class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        const int N = intervals.size();

        map<int, int> delta;
        for(const vector<int>& INTERVAL: intervals){
            delta[INTERVAL[0]] += 1;
            delta[INTERVAL[1] + 1] -= 1;
        }

        int maxActiveIntervals = 0;
        int activeIntervals = 0;
        for(const pair<const int, int>& P: delta){
            activeIntervals += P.second;
            maxActiveIntervals = max(maxActiveIntervals, activeIntervals);
        }

        return maxActiveIntervals;
    }
};