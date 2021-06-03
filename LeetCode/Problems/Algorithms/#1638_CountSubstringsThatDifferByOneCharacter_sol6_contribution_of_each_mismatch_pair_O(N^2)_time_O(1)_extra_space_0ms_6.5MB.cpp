class Solution {
private:
    int countValidSubstrings(const string& S, const int& S_START_POS,
                             const string& T, const int& T_START_POS){
        int validSubstringsCnt = 0;
        int leftCnt = 0;
        int continuousMatches = 0;
        for(int i = S_START_POS, j = T_START_POS; i < S.length() && j < T.length(); ++i, ++j){
            continuousMatches += 1;
            if(S[i] != T[j]){
                leftCnt = continuousMatches;
                continuousMatches = 0;
            }
            validSubstringsCnt += leftCnt;
        }
        return validSubstringsCnt;
    }
    
public:
    int countSubstrings(string s, string t) {
        int answer = 0;
        for(int i = 0; i < s.length(); ++i){
            answer += countValidSubstrings(s, i, t, 0);
        }
        for(int j = 1; j < t.length(); ++j){
            answer += countValidSubstrings(s, 0, t, j);
        }
        return answer;
    }
};