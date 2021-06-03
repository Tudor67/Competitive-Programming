class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        const int N = s.length();
        const int MAX_LETTER = 'z';
        
        unordered_map<string, int> validSubstringCnt;
        vector<int> letterCnt(MAX_LETTER + 1, 0);
        for(int i = 0; i + minSize - 1 < N; ++i){
            fill(letterCnt.begin(), letterCnt.end(), 0);
            int uniqueLetters = 0;
            for(int size = 1; size <= minSize; ++size){
                uniqueLetters += (letterCnt[s[i + size - 1]] == 0);
                letterCnt[s[i + size - 1]] += 1;
            }
            if(uniqueLetters <= maxLetters){
                validSubstringCnt[s.substr(i, minSize)] += 1;
            }
        }
        
        int answer = 0;
        for(const pair<string, int>& P: validSubstringCnt){
            int cnt = P.second;
            answer = max(cnt, answer);
        }
        
        return answer;
    }
};