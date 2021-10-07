class Solution {
private:
    int computeMaxLen(const string& S, int startPos, int endPos){
        if(startPos >= endPos){
            return 0;
        }
        
        int lowMask = 0;
        int upMask = 0;
        for(int i = startPos; i <= endPos; ++i){
            if(islower(S[i])){
                lowMask |= (1 << (S[i] - 'a'));
            }else{
                upMask |= (1 << (S[i] - 'A'));
            }
        }
        
        if(lowMask == upMask){
            return endPos - startPos + 1;
        }
        
        int maxLen = 0;
        for(int i = startPos; i <= endPos; ++i){
            if((((lowMask >> (tolower(S[i]) - 'a')) & 1) ^ ((upMask >> (toupper(S[i]) - 'A')) & 1)) == 1){
                maxLen = max(computeMaxLen(S, startPos, i - 1), computeMaxLen(S, i + 1, endPos));
                break;
            }
        }
        
        return maxLen;
    }
    
public:
    string longestNiceSubstring(string s) {
        const int N = s.length();
        
        // divide and conquer
        int maxLen = computeMaxLen(s, 0, N - 1);
        
        // sliding window
        int startPos = 0;
        unordered_map<char, int> count;
        for(int i = 0; i < N; ++i){
            count[s[i]] += 1;
            if(i >= maxLen){
                count[s[i - maxLen]] -= 1;
            }
            if(i >= maxLen - 1){
                bool found = true;
                for(char c = 'a'; c <= 'z'; ++c){
                    if((count[c] == 0) != (count[toupper(c)] == 0)){
                        found = false;
                    }
                }
                if(found){
                    startPos = i - maxLen + 1;
                    break;
                }
            }
        }
        
        return s.substr(startPos, maxLen);
    }
};