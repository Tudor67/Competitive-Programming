class Solution {
private:
    int countPrefixCommonWords(const string& SENTENCE1, const string& SENTENCE2){
        const int N1 = SENTENCE1.length();
        const int N2 = SENTENCE2.length();
        
        int i1 = 0;
        int i2 = 0;
        int prefixCommonWords = 0;
        while(i1 < N1 && i2 < N2 && SENTENCE1[i1] == SENTENCE2[i2]){
            prefixCommonWords += (int)(SENTENCE1[i1] == ' ');
            i1 += 1;
            i2 += 1;
        }
        
        if((i1 == N1 && i2 == N2) ||
           (i1 == N1 && SENTENCE2[i2] == ' ') || (i2 == N2 && SENTENCE1[i1] == ' ')){
            prefixCommonWords += 1;
        }
        
        return prefixCommonWords;
    }
    
    int countSuffixCommonWords(const string& SENTENCE1, const string& SENTENCE2){
        const int N1 = SENTENCE1.length();
        const int N2 = SENTENCE2.length();
        
        int i1 = N1 - 1;
        int i2 = N2 - 1;
        int suffixCommonWords = 0;
        while(i1 >= 0 && i2 >= 0 && SENTENCE1[i1] == SENTENCE2[i2]){
            suffixCommonWords += (int)(SENTENCE1[i1] == ' ');
            i1 -= 1;
            i2 -= 1;
        }
        
        if((i1 == -1 && i2 == -1) ||
           (i1 == -1 && SENTENCE2[i2] == ' ') || (i2 == -1 && SENTENCE1[i1] == ' ')){
            suffixCommonWords += 1;
        }
        
        return suffixCommonWords;
    }
    
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        const int WORDS1_COUNT = 1 + count(sentence1.begin(), sentence1.end(), ' ');
        const int WORDS2_COUNT = 1 + count(sentence2.begin(), sentence2.end(), ' ');
        
        int prefixCommonWords = countPrefixCommonWords(sentence1, sentence2);
        int suffixCommonWords = countSuffixCommonWords(sentence1, sentence2);
        
        return (prefixCommonWords + suffixCommonWords >= min(WORDS1_COUNT, WORDS2_COUNT));
    }
};