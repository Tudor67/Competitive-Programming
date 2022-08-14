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
        
        // use sliding window to check if a window contains all target indices
        vector<int> targetCount(wordToIdx.size());
        for(const string& WORD: words){
            targetCount[wordToIdx[WORD]] += 1;
        }
        
        vector<int> startingIndices;
        vector<int> currentCount(wordToIdx.size());
        for(int i = 0; i + W * L - 1 < N; ++i){
            fill(currentCount.begin(), currentCount.end(), 0);
            for(int j = i; j + L - 1 <= i + W * L - 1; j += L){
                if(matchIdxAt[j] >= 0){
                    currentCount[matchIdxAt[j]] += 1;
                }
            }
            if(currentCount == targetCount){
                startingIndices.push_back(i);
            }
        }
        
        return startingIndices;
    }
};