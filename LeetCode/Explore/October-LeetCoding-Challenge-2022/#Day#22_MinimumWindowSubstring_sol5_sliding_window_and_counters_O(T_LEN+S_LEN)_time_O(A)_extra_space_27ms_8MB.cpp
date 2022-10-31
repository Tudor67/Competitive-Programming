class Solution {
public:
    string minWindow(string s, string t) {
        const int S_LEN = s.length();
        const int T_LEN = t.length();
        const int FIRST_CHAR = 'A';
        const int LAST_CHAR = 'z';
        
        vector<int> tCount(LAST_CHAR + 1);
        int tUniqueChars = 0;
        for(char c: t){
            tCount[c] += 1;
            tUniqueChars += (int)(tCount[c] == 1);
        }
        
        int bestStartPos = 0;
        int bestLen = 0;
        
        int startPos = 0;
        int matchedUniqueChars = 0;
        vector<int> sCount(LAST_CHAR + 1);
        for(int i = 0; i < S_LEN; ++i){
            sCount[s[i]] += 1;
            matchedUniqueChars += (int)(sCount[s[i]] == tCount[s[i]]);
            while(sCount[s[startPos]] > tCount[s[startPos]]){
                sCount[s[startPos]] -= 1;
                startPos += 1;
            }
            
            int len = i - startPos + 1;
            if(matchedUniqueChars == tUniqueChars && (bestLen == 0 || len < bestLen)){
                bestStartPos = startPos;
                bestLen = len;
            }
        }
        
        return s.substr(bestStartPos, bestLen);
    }
};