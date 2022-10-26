class Solution {
private:
    const int INF = 1e9;
    
    int maxOperations(string& s, int startPos, vector<int>& memo) {
        const int N = s.length();
        
        if(N - startPos <= 1){
            return N - startPos;
        }
        
        if(memo[startPos] != INF){
            return memo[startPos];
        }
        
        int res = 1;
        for(int len = 1; startPos + 2 * len - 1 < N; ++len){
            if(equal(s.begin() + startPos, s.begin() + startPos + len, s.begin() + startPos + len)){
                res = max(res, 1 + maxOperations(s, startPos + len, memo));
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
        vector<int> memo(N, INF);
        return maxOperations(s, 0, memo);
    }
};