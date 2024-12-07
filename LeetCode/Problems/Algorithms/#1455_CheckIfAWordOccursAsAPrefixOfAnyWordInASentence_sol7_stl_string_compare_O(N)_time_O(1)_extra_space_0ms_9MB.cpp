class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        const int N = sentence.length();

        int wordIndex = 1;
        for(int i = 0; i < N; ++i){
            if(i == 0 || sentence[i - 1] == ' '){
                if(sentence.compare(i, searchWord.length(), searchWord) == 0){
                    return wordIndex;
                }
                wordIndex += 1;
            }
        }

        return -1;
    }
};