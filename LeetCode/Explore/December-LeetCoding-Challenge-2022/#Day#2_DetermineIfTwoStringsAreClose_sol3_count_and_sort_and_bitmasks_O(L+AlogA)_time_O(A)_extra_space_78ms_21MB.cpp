class Solution {
private:
    const int A = 26;
    const int FIRST_CHAR = 'a';
    
    pair<vector<int>, int> getSortedFrequenciesAndCharsMask(const string& WORD){
        vector<int> freqOf(A);
        int charsMask = 0;
        for(char c: WORD){
            freqOf[c - FIRST_CHAR] += 1;
            charsMask |= (1 << (c - FIRST_CHAR));
        }
        
        vector<int> sortedFreqs = freqOf;
        sort(sortedFreqs.begin(), sortedFreqs.end());
        
        return {sortedFreqs, charsMask};
    }
    
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()){
            return false;
        }
        return (getSortedFrequenciesAndCharsMask(word1) ==
                getSortedFrequenciesAndCharsMask(word2));
    }
};