class Solution {
public:
    string minWindow(string s, string t) {
        const int N = s.length();
        const int M = t.length();
        
        unordered_map<char, int> targetCount;
        for(char c: t){
            targetCount[c] += 1;
        }
        
        int answerStart = 0;
        int answerLength = 0;
        int matches = 0;
        int targetMatches = targetCount.size();
        unordered_map<char, int> count;
        for(int i = 0, j = 0; j < N; ++j){
            count[s[j]] += 1;
            matches += (count[s[j]] == targetCount[s[j]]);
            if(matches == targetMatches){
                while(count[s[i]] > targetCount[s[i]]){
                    count[s[i]] -= 1;
                    i += 1;
                }
                if(answerLength == 0 || (j - i + 1 < answerLength)){
                    answerStart = i;
                    answerLength = j - i + 1;
                }
            }
        }
        
        return s.substr(answerStart, answerLength);
    }
};