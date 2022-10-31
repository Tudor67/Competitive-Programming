class Solution {
public:
    string minWindow(string s, string t) {
        const int S_LEN = s.length();
        const int T_LEN = t.length();
        const int FIRST_CHAR = 'A';
        const int LAST_CHAR = 'z';
        
        vector<int> tCount(LAST_CHAR + 1);
        for(char c: t){
            tCount[c] += 1;
        }
        
        int bestStartPos = 0;
        int bestLen = 0;
        
        int startPos = 0;
        vector<int> sCount(LAST_CHAR + 1);
        for(int i = 0; i < S_LEN; ++i){
            sCount[s[i]] += 1;
            while(sCount[s[startPos]] > tCount[s[startPos]]){
                sCount[s[startPos]] -= 1;
                startPos += 1;
            }
            
            bool isValid = true;
            for(char c = FIRST_CHAR; isValid && c <= LAST_CHAR; ++c){
                if(sCount[c] < tCount[c]){
                    isValid = false;
                }
            }
            
            int len = i - startPos + 1;
            if(isValid && (bestLen == 0 || len < bestLen)){
                bestStartPos = startPos;
                bestLen = len;
            }
        }
        
        return s.substr(bestStartPos, bestLen);
    }
};