class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int answer = 0;
        
        if(!intervals.empty()){
            const int N = intervals.size();
            sort(intervals.begin(), intervals.end());
            
            vector<int> dp(N, 1);
            for(int i = 1; i < N; ++i){
                for(int j = 0; j < i; ++j){
                    if(intervals[j][1] <= intervals[i][0]){
                        dp[i] = max(1 + dp[j], dp[i]);
                    }
                }
            }
            
            answer = N - *max_element(dp.begin(), dp.end());
        }
        
        return answer;
    }
};