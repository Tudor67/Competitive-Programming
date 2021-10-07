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
    
    int computeMaxLen(const string& S, int startPos, int endPos,
                      vector<vector<int>>& prefCountLow, vector<vector<int>>& prefCountUp){
        if(startPos >= endPos){
            return 0;
        }
        
        int lowMask = getRangeMask(startPos, endPos, prefCountLow);
        int upMask = getRangeMask(startPos, endPos, prefCountUp);
        if(lowMask == upMask){
            return endPos - startPos + 1;
        }
        
        int maxLen = 0;
        for(int i = startPos; i <= endPos; ++i){
            if((((lowMask >> (tolower(S[i]) - 'a')) & 1) ^ ((upMask >> (toupper(S[i]) - 'A')) & 1)) == 1){
                maxLen = max(computeMaxLen(S, startPos, i - 1, prefCountLow, prefCountUp),
                             computeMaxLen(S, i + 1, endPos, prefCountLow, prefCountUp));
                break;
            }
        }
        
        return maxLen;
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
        int maxLen = computeMaxLen(s, 0, N - 1, prefCountLow, prefCountUp);
        if(maxLen == 0){
            return "";
        }
        
        // sliding window
        int startPos = 0;
        for(int i = maxLen - 1; i < N; ++i){
            int lowMask = getRangeMask(i - maxLen + 1, i, prefCountLow);
            int upMask = getRangeMask(i - maxLen + 1, i, prefCountUp);
            if(lowMask == upMask){
                startPos = i - maxLen + 1;
                break;
            }
        }
        
        return s.substr(startPos, maxLen);
    }
};