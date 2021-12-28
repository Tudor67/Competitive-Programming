class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int N = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        for(const vector<int>& INTERVAL: intervals){
            if(merged.empty() || merged.back()[1] < INTERVAL[0]){
                merged.push_back(INTERVAL);
            }else{
                merged.back()[1] = max(merged.back()[1], INTERVAL[1]);
            }
        }
        
        return merged;
    }
};