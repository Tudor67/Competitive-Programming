class Solution {
private:
    int getMinNonOverlappingStringLength(const string& S1, const string& S2){
        int bestPosition = 0;
        for(int i = (int)S1.length() - 1, j = 0; i >= 0 && j < (int)S2.length(); --i, ++j){
            bool isValid = true;
            for(int k = 0; isValid && k <= j; ++k){
                if(S1[i + k] != S2[k]){
                    isValid = false;
                }
            }
            if(isValid){
                bestPosition = j + 1;
            }
        }
        return (int)S2.length() - bestPosition;
    }
    
public:
    string shortestSuperstring(vector<string>& words) {
        const int N = words.size();
        const int FULL_MASK = (1 << N) - 1;
        const int INF = 1e7;
        
        vector<vector<int>> minNonOverlappingStringLength(N, vector<int>(N, INF));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                minNonOverlappingStringLength[i][j] = getMinNonOverlappingStringLength(words[i], words[j]);
            }
        }
            
        vector<vector<pair<int, int>>> dp(FULL_MASK + 1, vector<pair<int, int>>(N, {INF, -1}));
        // dp[mask][i].first: length of the shortest string that contains all words[bit],
        //                    where ((mask >> bit) & 1) is 1 and last added word is words[i]
        // dp[mask][i].second: index of previous added word (i.e., before words[i])
        
        for(int i = 0; i < N; ++i){
            dp[1 << i][i] = {words[i].length(), -1};
        }
        
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    if(i != j && ((mask >> i) & 1) && ((mask >> j) & 1)){
                        int candidateLength = dp[mask ^ (1 << i)][j].first + minNonOverlappingStringLength[j][i];
                        if(candidateLength < dp[mask][i].first){
                            dp[mask][i] = {candidateLength, j};
                        }
                    }
                }
            }
        }
        
        vector<int> indices;
        int mask = FULL_MASK;
        int idx = min_element(dp[FULL_MASK].begin(), dp[FULL_MASK].end()) - dp[FULL_MASK].begin();
        while(idx != -1){
            indices.push_back(idx);
            mask ^= (1 << idx);
            idx = dp[mask ^ (1 << idx)][idx].second;
        }
        
        string answer = words[indices[N - 1]];
        for(int i = N - 2; i >= 0; --i){
            int startPos = (int)words[indices[i]].length() - minNonOverlappingStringLength[indices[i + 1]][indices[i]];
            answer += words[indices[i]].substr(startPos);
        }
        
        return answer;
    }
};