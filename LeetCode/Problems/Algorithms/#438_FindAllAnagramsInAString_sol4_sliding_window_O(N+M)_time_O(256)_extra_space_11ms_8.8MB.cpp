class Solution {    
public:
    vector<int> findAnagrams(string s, string p) {
        const int N = s.length();
        const int M = p.length();
        const char MIN_CHAR = 'a';
        const char MAX_CHAR = 'z';
        
        vector<int> pCount(MAX_CHAR + 1);
        for(char c: p){
            pCount[c] += 1;
        }
        
        int targetMatches = 0;
        for(char c = MIN_CHAR; c <= MAX_CHAR; ++c){
            if(pCount[c] > 0){
                targetMatches += 1;
            }
        }
        
        vector<int> answer;
        int matches = 0;
        vector<int> wCount(MAX_CHAR + 1);
        for(int i = 0; i < N; ++i){
            wCount[s[i]] += 1;
            matches += (int)(wCount[s[i]] == pCount[s[i]]);
            if(i >= M){
                matches -= (int)(wCount[s[i - M]] == pCount[s[i - M]]);
                wCount[s[i - M]] -= 1;
            }
            if(i >= M - 1){
                if(matches == targetMatches){
                    answer.push_back(i - M + 1);
                }
            }
        }
        
        return answer;
    }
};