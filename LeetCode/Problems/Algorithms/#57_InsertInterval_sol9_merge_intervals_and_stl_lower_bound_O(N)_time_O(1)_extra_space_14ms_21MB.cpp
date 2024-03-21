class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.insert(upper_bound(intervals.begin(), intervals.end(), newInterval), newInterval);

        vector<vector<int>> res;
        for(const vector<int>& I: intervals){
            if(res.empty() || res.back()[1] < I[0]){
                res.push_back(I);
            }else{
                res.back()[1] = max(res.back()[1], I[1]);
            }
        }
        
        intervals.erase(lower_bound(intervals.begin(), intervals.end(), newInterval));

        return res;
    }
};