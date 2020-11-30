class Solution {
private:
    void zeroInit(vector<int>& count, const string& S, const int& START_POS, const int& END_POS){
        for(int i = START_POS; i <= END_POS; ++i){
            count[S[i]] = 0;
        }
    }
    
public:
    int longestSubstring(string s, int k) {
        const int N = s.length();
        const char MIN_LETTER = 'a';
        const char MAX_LETTER = 'z';
        const int COUNT_SIZE = MAX_LETTER + 1;
        
        vector<int> globalCount(COUNT_SIZE, 0);
        for(char c: s){
            globalCount[c] += 1;
        }
        
        vector<bool> isGlobalCandidate(N);
        for(int i = 0; i < N; ++i){
            isGlobalCandidate[i] = (globalCount[s[i]] >= k);
        }
        
        int answer = 0;
        vector<int> windowCount(COUNT_SIZE, 0);
        vector<int> subWindowCount(COUNT_SIZE, 0);
        for(int i = 0, j = 0; j <= N; ++j){
            if(j < N && isGlobalCandidate[j]){
                windowCount[s[j]] += 1;
            }else{
                int prevI = i;
                int subWindowSize = 0;
                int distinctChars = 0;
                int validChars = 0;
                while(i <= j){
                    if(i < j && windowCount[s[i]] >= k){
                        subWindowSize += 1;
                        subWindowCount[s[i]] += 1;
                        distinctChars += (subWindowCount[s[i]] == 1);
                        validChars += (subWindowCount[s[i]] == k);
                        if(distinctChars == validChars){
                            answer = max(subWindowSize, answer);
                        }
                    }else{
                        subWindowSize = 0;
                        distinctChars = 0;
                        validChars = 0;
                        zeroInit(subWindowCount, s, prevI, j);
                    }
                    i += 1;
                }
                zeroInit(windowCount, s, prevI, j);
            }
        }
        
        return answer;
    }
};