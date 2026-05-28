class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        const int N = arr.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (arr[lhs] < arr[rhs]);
             });
        
        // dp[i]: max number of indices we can visit when starting at index i
        vector<int> dp(N);
        for(int i: p){
            dp[i] = 1;
            for(int j = i + 1; j <= min(i + d, N - 1) && arr[i] > arr[j]; ++j){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            for(int j = i - 1; j >= max(i - d, 0) && arr[i] > arr[j]; --j){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};