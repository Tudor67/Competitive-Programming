class SuffixArray{
private:
    const int N;
    const int LOG_N;
    vector<vector<int>> c;
    
public:
    SuffixArray(const string& S): N(S.length()), LOG_N(floor(log2(N))){
        c.assign(LOG_N + 2, vector<int>(N));
        for(int i = 0; i < N; ++i){
            c[0][i] = S[i] - 'a';
        }
        
        vector<pair<pair<int, int>, int>> v(N);
        for(int k = 1; k <= LOG_N + 1; ++k){
            int len = (1 << k);
            for(int i = 0; i < N; ++i){
                int l = c[k - 1][i];
                int r = (i + len / 2 < N ? c[k - 1][i + len / 2] : -1);
                v[i].first = {l, r};
                v[i].second = i;
            }
            
            sort(v.begin(), v.end());
            
            int classID = 0;
            for(int i = 0; i < N; ++i){
                if(i >= 1 && v[i - 1].first != v[i].first){
                    classID += 1;
                }
                c[k][v[i].second] = classID;
            }
        }
    }
    
    int computeLCP(int i, int j){
        int lcp = 0;
        for(int k = LOG_N + 1; k >= 0 && max(i, j) < N; --k){
            if(c[k][i] == c[k][j]){
                i += (1 << k);
                j += (1 << k);
                lcp += (1 << k);
            }
        }
        return lcp;
    }
};

class Solution {
private:
    const int INF = 1e9;
    
    int maxOperations(string& s, int startPos, SuffixArray& suffixArray, vector<int>& memo) {
        const int N = s.length();
        
        if(N - startPos <= 1){
            return N - startPos;
        }
        
        if(memo[startPos] != INF){
            return memo[startPos];
        }
        
        int res = 1;
        for(int len = 1; startPos + 2 * len - 1 < N; ++len){
            if(suffixArray.computeLCP(startPos, startPos + len) >= len){
                res = max(res, 1 + maxOperations(s, startPos + len, suffixArray, memo));
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
        
        SuffixArray suffixArray(s);
        vector<int> memo(N, INF);
        
        return maxOperations(s, 0, suffixArray, memo);
    }
};