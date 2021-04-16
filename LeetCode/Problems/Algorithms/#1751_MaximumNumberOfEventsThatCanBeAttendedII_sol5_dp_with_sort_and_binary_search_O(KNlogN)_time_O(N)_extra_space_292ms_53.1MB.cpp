class Solution {
private:
    static bool incEndComp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] < RHS[1]);
    }
    
public:
    int maxValue(vector<vector<int>>& events, int k) {
        const int N = events.size();
        
        sort(events.begin(), events.end(), incEndComp);
        
        // compressed version: at step i we need only values from step i - 1
        // dp[i][j]: max sum of values by attending maximum i events and the last attended event is events[j]
        vector<vector<int>> dp(2, vector<int>(N, 0));
        
        // compressed version: at step i we need only values from step i - 1
        // prefMaxDP[i][j]: max sum of values by attending maximum i events and the last attended event is from events[0..j]
        // prefMaxDP[i][j] = max({dp[i][0], dp[i][1], dp[i][2], ..., dp[i][j]})
        vector<vector<int>> prefMaxDP(2, vector<int>(N, 0));
        
        dp[1][0] = events[0][2];
        prefMaxDP[1][0] = events[0][2];
        for(int j = 1; j < N; ++j){
            dp[1][j] = events[j][2];
            prefMaxDP[1][j] = max(prefMaxDP[1][j - 1], dp[1][j]);
        }
        
        for(int i = 2; i <= k; ++i){
            copy(dp[(i - 1) % 2].begin(), dp[(i - 1) % 2].end(), dp[i % 2].begin());
            copy(prefMaxDP[(i - 1) % 2].begin(), prefMaxDP[(i - 1) % 2].end(), prefMaxDP[i % 2].begin());
            for(int j = i - 1; j < N; ++j){
                int l = 0;
                int r = j;
                while(l != r){
                    int mid = (l + r + 1) / 2;
                    if(events[mid][1] < events[j][0]){
                        l = mid;
                    }else{
                        r = mid - 1;
                    }
                }
                int k = r;
                if(0 <= k && events[k][1] < events[j][0]){
                    dp[i % 2][j] = max(prefMaxDP[(i - 1) % 2][k] + events[j][2], dp[i % 2][j]);
                }
                prefMaxDP[i % 2][j] = max(prefMaxDP[i % 2][j - 1], dp[i % 2][j]);
            }
        }
        
        int answer = *max_element(dp[k % 2].begin(), dp[k % 2].end());
        
        return answer;
    }
};