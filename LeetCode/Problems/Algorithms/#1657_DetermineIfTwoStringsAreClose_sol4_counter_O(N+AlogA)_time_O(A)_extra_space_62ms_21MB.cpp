class Solution {
private:
    const int A = 26;
    const char FIRST_CHAR = 'a';

    int getCharMask(const string& S){
        int charMask = 0;
        for(char c: S){
            charMask |= (1 << (c - FIRST_CHAR));
        }
        return charMask;
    }

    vector<int> getSortedFrequencies(const string& S){
        vector<int> freqOf(A);
        for(char c: S){
            freqOf[c - FIRST_CHAR] += 1;
        }
        sort(freqOf.begin(), freqOf.end());
        return freqOf;
    }

public:
    bool closeStrings(string word1, string word2) {
        return word1.length() == word2.length() &&
               getCharMask(word1) == getCharMask(word2) &&
               getSortedFrequencies(word1) == getSortedFrequencies(word2);
    }
};