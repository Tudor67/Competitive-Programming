class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        const int N = ranges.size();
        const int MODULO = 1e9 + 7;
        
        vector<pair<int, int>> sortedRanges(N);
        for(int i = 0; i < N; ++i){
            sortedRanges[i] = {ranges[i][0], ranges[i][1]};
        }

        sort(sortedRanges.begin(), sortedRanges.end());
        
        int groups = 1;
        int maxEnd = sortedRanges[0].second;
        for(int i = 1; i < N; ++i){
            if(maxEnd < sortedRanges[i].first){
                groups += 1;
            }
            maxEnd = max(maxEnd, sortedRanges[i].second);
        }
        
        int res = 1;
        for(int i = 1; i <= groups; ++i){
            res = (res * 2) % MODULO;
        }
        
        return res;
    }
};