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
        
        string ss = s.substr(startPos);
        const int M = ss.length();
        vector<int> z(M);
        int a = 0;
        int b = 0;
        for(int i = 1; i < M; ++i){
            if(i <= b){
                z[i] = min(z[i - a], b - i + 1);
            }
            while(i + z[i] < M && ss[z[i]] == ss[i + z[i]]){
                z[i] += 1;
            }
            if(i + z[i] - 1 >= b){
                a = i;
                b = i + z[i] - 1;
            }
        }
        
        int res = 1;
        for(int len = 1; startPos + 2 * len - 1 < N; ++len){
            if(z[len] >= len){
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