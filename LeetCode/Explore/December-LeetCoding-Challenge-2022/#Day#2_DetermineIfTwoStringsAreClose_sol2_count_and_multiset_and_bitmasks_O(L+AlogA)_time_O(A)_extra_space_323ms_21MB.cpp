class Solution {
private:
    const int A = 26;
    const int FIRST_CHAR = 'a';
    
    int getCharsMask(const string& WORD){
        int charsMask = 0;
        for(char c: WORD){
            charsMask |= (1 << (c - FIRST_CHAR));
        }
        return charsMask;
    }
    
    multiset<int> getFrequencyMultiset(const string& WORD){
        unordered_map<char, int> freqOf;
        for(char c: WORD){
            freqOf[c] += 1;
        }
        
        multiset<int> freqMultiset;
        for(const pair<char, int>& P: freqOf){
            freqMultiset.insert(P.second);
        }
        
        return freqMultiset;
    }
    
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()){
            return false;
        }
        return (getCharsMask(word1) == getCharsMask(word2)) &&
               (getFrequencyMultiset(word1) == getFrequencyMultiset(word2));
    }
};