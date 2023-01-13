class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        const int R = ranges.size();

        vector<pair<int, int>> intersections;
        for(const vector<int>& RANGE: ranges){
            int l = max(RANGE[0], left);
            int r = min(RANGE[1], right);
            if(l <= r){
                intersections.push_back({l, r});
            }
        }

        sort(intersections.begin(), intersections.end());
        
        if(intersections.empty() || intersections[0].first != left){
            return false;
        }

        int maxVal = intersections[0].second;
        for(const pair<int, int>& I: intersections){
            int l = I.first;
            int r = I.second;
            if(maxVal + 1 < l){
                return false;
            }
            maxVal = max(maxVal, r);
        }

        return (maxVal == right);
    }
};