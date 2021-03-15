class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MODULO = 1e9 + 7;
        const int N = arr.size();
        
        sort(arr.begin(), arr.end());
        
        map<int, int> dp;
        for(int i = 0; i < N; ++i){
            dp[arr[i]] = 1;
        }
        
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(arr[i] % arr[j] == 0 && dp.count(arr[i] / arr[j])){
                    int f1 = arr[j];
                    int f2 = arr[i] / arr[j];
                    dp[arr[i]] = (dp[arr[i]] + 1LL * dp[f1] * dp[f2]) % MODULO;
                }
            }
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            answer += dp[arr[i]];
            answer %= MODULO;
        }
        
        return answer;
    }
};