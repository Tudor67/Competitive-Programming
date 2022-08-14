class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int N = s.length();
        const int W = words.size();
        const int L = words[0].length();
        
        if(N < W * L){
            return {};
        }
        
        unordered_map<string, int> targetCount;
        for(const string& WORD: words){
            targetCount[WORD] += 1;
        }
        
        vector<int> startingIndices;
        unordered_map<string, int> currentCount;
        for(int i = 0; i < L; ++i){
            int l = i;
            int r = i;
            int matches = 0;
            currentCount.clear();
            while(r + L - 1 < N){
                string rWord = s.substr(r, L);
                if(targetCount.count(rWord)){
                    currentCount[rWord] += 1;
                    matches += (int)(currentCount[rWord] == targetCount[rWord]);
                }
                while(l <= r && (!targetCount.count(rWord) || currentCount[rWord] > targetCount[rWord])){
                    string lWord = s.substr(l, L);
                    if(targetCount.count(lWord)){
                        currentCount[lWord] -= 1;
                        matches -= (int)(currentCount[lWord] == targetCount[lWord] - 1);
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