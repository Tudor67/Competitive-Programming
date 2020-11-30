class Solution {
public:
    int longestSubstring(string s, int k) {
        const int N = s.length();
        const int MIN_CHAR = 'a';
        const int MAX_CHAR = 'z';
        const int DISTINCT_CHARS_COUNT = MAX_CHAR - MIN_CHAR + 1;
        
        vector<vector<int>> prefCount(N, vector<int>(DISTINCT_CHARS_COUNT, 0));
        prefCount[0][s[0] - MIN_CHAR] = 1;
        for(int i = 1; i < N; ++i){
            prefCount[i] = prefCount[i - 1];
            prefCount[i][s[i] - MIN_CHAR] += 1;
        }
        
        int answer = 0;
        vector<int> lastPos(DISTINCT_CHARS_COUNT, -1);
        for(int pos2 = 0; pos2 < N; ++pos2){
            lastPos[s[pos2] - MIN_CHAR] = pos2;
            
            int pos1 = -1;
            for(char c = MIN_CHAR; c <= MAX_CHAR; ++c){
                int cCount = prefCount[pos2][c - MIN_CHAR];
                if(1 <= cCount && cCount < k){
                    pos1 = max(lastPos[c - MIN_CHAR], pos1);
                }
            }
            
            bool isValid = true;
            for(char c = MIN_CHAR; isValid && c <= MAX_CHAR; ++c){
                int cCount = prefCount[pos2][c - MIN_CHAR] - (pos1 < 0 ? 0 : prefCount[pos1][c - MIN_CHAR]);
                if(1 <= cCount && cCount < k){
                    isValid = false;
                }
            }
            
            if(isValid){
                answer = max(pos2 - pos1, answer);
            }
        }
        
        return answer;
    }
};