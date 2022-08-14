class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int N = s.length();
        const int W = words.size();
        const int L = words[0].length();
        
        if(N < W * L){
            return {};
        }
        
        // reduce the initial problem where we have strings
        // to the problem where we have integers (using wordToIdx map)
        unordered_map<string, int> wordToIdx;
        int idx = 0;
        for(const string& WORD: words){
            if(!wordToIdx.count(WORD)){
                wordToIdx[WORD] = idx;
                idx += 1;
            }
        }
        
        // matchIdxAt[i]: idx of word that matches s[i .. i + L - 1]
        // matchIdxAt[i] == -1 <=> we don't have any match
        vector<int> matchIdxAt(N, -1);
        for(int i = 0; i + L - 1 < N; ++i){
            string word = s.substr(i, L);
            if(wordToIdx.count(word)){
                matchIdxAt[i] = wordToIdx[word];
            }
        }
        
        // use sliding window (with two pointers) to check if a window contains all target indices
        vector<int> targetCount(wordToIdx.size());
        for(const string& WORD: words){
            targetCount[wordToIdx[WORD]] += 1;
        }
        
        vector<int> startingIndices;
        vector<int> currentCount(wordToIdx.size());
        for(int i = 0; i < L; ++i){
            int l = i;
            int r = i;
            int matches = 0;
            fill(currentCount.begin(), currentCount.end(), 0);
            while(r + L - 1 < N){
                if(matchIdxAt[r] >= 0){
                    currentCount[matchIdxAt[r]] += 1;
                    matches += (int)(currentCount[matchIdxAt[r]] == targetCount[matchIdxAt[r]]);
                }
                while(l <= r && (matchIdxAt[r] < 0 || currentCount[matchIdxAt[r]] > targetCount[matchIdxAt[r]])){
                    if(matchIdxAt[l] >= 0){
                        currentCount[matchIdxAt[l]] -= 1;
                        matches -= (int)(currentCount[matchIdxAt[l]] == targetCount[matchIdxAt[l]] - 1);
                    }
                    l += L;
                }
                if(matches == (int)targetCount.size()){
                    startingIndices.push_back(l);
                }
                r += L;
            }
        }
        
        return startingIndices;
    }
};