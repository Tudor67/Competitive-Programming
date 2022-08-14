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
        for(int i = 0; i + W * L - 1 < N; ++i){
            currentCount.clear();
            bool isValid = true;
            for(int j = i; isValid && j + L - 1 <= i + W * L - 1; j += L){
                string word = s.substr(j, L);
                if(targetCount.count(word) && targetCount[word] > currentCount[word]){
                    currentCount[word] += 1;
                }else{
                    isValid = false;
                }
            }
            if(isValid){
                startingIndices.push_back(i);
            }
        }
        
        return startingIndices;
    }
};