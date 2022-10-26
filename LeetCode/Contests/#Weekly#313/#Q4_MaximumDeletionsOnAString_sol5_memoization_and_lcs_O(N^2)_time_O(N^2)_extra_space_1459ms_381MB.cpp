class Solution {
private:
    const int INF = 1e9;
    
    int maxOperations(string& s, int startPos, vector<vector<int>>& lcs, vector<int>& memo) {
        const int N = s.length();
        
        if(N - startPos <= 1){
            return N - startPos;
        }
        
        if(memo[startPos] != INF){
            return memo[startPos];
        }
        
        int res = 1;
        for(int len = 1; startPos + 2 * len - 1 < N; ++len){
            if(lcs[startPos][startPos + len] >= len){
                res = max(res, 1 + maxOperations(s, startPos + len, lcs, memo));
            }
            if(res == N - startPos){
                break;
            }
        }
        
        memo[startPos] = res;
        return memo[startPos];
    }
    
public:
    int deleteString(string s) {
        const int N = s.length();
        
        vector<vector<int>> lcs(N + 1, vector<int>(N + 1));
        for(int i = N - 1; i >= 0; --i){
            for(int j = N - 1; j >= i; --j){
                if(s[i] == s[j]){
                    lcs[i][j] = 1 + lcs[i + 1][j + 1];
                }
            }
        }
        
        vector<int> memo(N, INF);
        return maxOperations(s, 0, lcs, memo);
    }
};