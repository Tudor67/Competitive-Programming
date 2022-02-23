class Solution {
private:
    int countPrefixCommonWords(const string& SENTENCE1, const string& SENTENCE2){
        istringstream ss1(SENTENCE1);
        istringstream ss2(SENTENCE2);
        string word1;
        string word2;
        
        int prefixCommonWords = 0;
        while((ss1 >> word1) && (ss2 >> word2) && (word1 == word2)){
            prefixCommonWords += 1;
        }
        
        return prefixCommonWords;
    }
    
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        const int WORDS1_COUNT = 1 + count(sentence1.begin(), sentence1.end(), ' ');
        const int WORDS2_COUNT = 1 + count(sentence2.begin(), sentence2.end(), ' ');
        
        int prefixCommonWords = countPrefixCommonWords(sentence1, sentence2);
        int suffixCommonWords = countPrefixCommonWords(string(sentence1.rbegin(), sentence1.rend()),
                                                       string(sentence2.rbegin(), sentence2.rend()));
        
        return (prefixCommonWords + suffixCommonWords >= min(WORDS1_COUNT, WORDS2_COUNT));
    }
};