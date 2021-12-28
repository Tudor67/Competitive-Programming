class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int N = intervals.size();
        
        int maxEnd = 0;
        for(const vector<int>& INTERVAL: intervals){
            maxEnd = max(maxEnd, INTERVAL[1]);
        }
        
        vector<int> diff(maxEnd + 1);
        vector<bool> isSpecialInterval(maxEnd + 1, false);
        for(const vector<int>& INTERVAL: intervals){
            int start = INTERVAL[0];
            int end = INTERVAL[1];
            diff[start] += 1;
            diff[end] -= 1;
            if(start == end){
                isSpecialInterval[start] = true;
            }
        }
        
        vector<vector<int>> mergedIntervals;
        int start = -1;
        int end = -1;
        int activeIntervals = 0;
        for(int i = 0; i <= maxEnd; ++i){
            activeIntervals += diff[i];
            if(activeIntervals >= 1){
                if(start == -1){
                    start = i;
                }
                end = i;
            }else{
                if(start == -1){
                    if(isSpecialInterval[i]){
                        mergedIntervals.push_back({i, i});
                    }
                }else{
                    mergedIntervals.push_back({start, end + 1});
                    start = -1;
                    end = -1;
                }
            }
        }
        
        return mergedIntervals;
    }
};