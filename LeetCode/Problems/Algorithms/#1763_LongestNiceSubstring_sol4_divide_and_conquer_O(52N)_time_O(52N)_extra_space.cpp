class Solution {
private:
    int getRangeMask(int startPos, int endPos, vector<vector<int>>& prefCount){
        int rangeMask = 0;
        for(int k = 0; k < 26; ++k){
            int rangeCount = prefCount[k][endPos];
            if(startPos > 0){
                rangeCount -= prefCount[k][startPos - 1];
            }
            if(rangeCount > 0){
                rangeMask |= (1 << k);
            }
        }
        return rangeMask;
    }
    
    pair<int, int> solve(const string& S, int startPos, int endPos,
                         vector<vector<int>>& prefCountLow, vector<vector<int>>& prefCountUp){
        if(startPos >= endPos){
            return {0, 0};
        }
        
        int lowMask = getRangeMask(startPos, endPos, prefCountLow);
        int upMask = getRangeMask(startPos, endPos, prefCountUp);
        if(lowMask == upMask){
            return {endPos - startPos + 1, -startPos};
        }
        
        pair<int, int> answer = {0, 0};
        for(int i = startPos; i <= endPos; ++i){
            if((((lowMask >> (tolower(S[i]) - 'a')) & 1) ^ ((upMask >> (toupper(S[i]) - 'A')) & 1)) == 1){
                answer = max(solve(S, startPos, i - 1, prefCountLow, prefCountUp),
                             solve(S, i + 1, endPos, prefCountLow, prefCountUp));
                break;
            }
        }
        
        return answer;
    }
    
public:
    string longestNiceSubstring(string s) {
        const int N = s.length();
        
        // pre-process
        vector<vector<int>> prefCountLow(26, vector<int>(N, 0));
        vector<vector<int>> prefCountUp(26, vector<int>(N, 0));
        for(int i = 0; i < N; ++i){
            if(i > 0){
                for(int k = 0; k < 26; ++k){
                    prefCountLow[k][i] = prefCountLow[k][i - 1];
                    prefCountUp[k][i] = prefCountUp[k][i - 1];
                }
            }
            if(islower(s[i])){
                prefCountLow[s[i] - 'a'][i] += 1;
            }else{
                prefCountUp[s[i] - 'A'][i] += 1;
            }
        }
        
        // divide and conquer
        pair<int, int> p = solve(s, 0, N - 1, prefCountLow, prefCountUp);
        int maxLen = p.first;
        int startPos = -p.second;
        
        return s.substr(startPos, maxLen);
    }
};