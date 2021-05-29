class Solution {
private:
    string minNonOverlappingString(const string& S1, const string& S2){
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
        return S2.substr(bestPosition);
    }
    
public:
    string shortestSuperstring(vector<string>& words) {
        const int N = words.size();
        const int FULL_MASK = (1 << N) - 1;
            
        vector<vector<string>> dp(FULL_MASK + 1, vector<string>(N));
        // dp[mask][i]: shortest string that contains all words[bit],
        //              where ((mask >> bit) & 1) is 1 and last added word is words[i]
        
        for(int i = 0; i < N; ++i){
            dp[1 << i][i] = words[i];
        }
        
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    if(i != j && ((mask >> i) & 1) && ((mask >> j) & 1)){
                        string candidate = dp[mask ^ (1 << i)][j] +
                                           minNonOverlappingString(dp[mask ^ (1 << i)][j], words[i]);
                        if(dp[mask][i].empty() || candidate.length() < dp[mask][i].length()){
                            dp[mask][i] = candidate;
                        }
                    }
                }
            }
        }
        
        string answer;
        for(int i = 0; i < N; ++i){
            if(dp[FULL_MASK][i].length() < answer.length() || answer.empty()){
                answer = dp[FULL_MASK][i];
            }
        }
        
        return answer;
    }
};