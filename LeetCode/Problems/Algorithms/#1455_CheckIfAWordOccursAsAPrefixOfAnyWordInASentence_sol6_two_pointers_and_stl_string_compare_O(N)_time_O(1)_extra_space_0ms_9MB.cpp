class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        const int N = sentence.length();

        int wordIndex = 1;
        int l = 0;
        for(int r = 0; r < N; ++r){
            if(r == N - 1 || sentence[r + 1] == ' '){
                if(sentence.compare(l, searchWord.length(), searchWord) == 0){
                    return wordIndex;
                }
                l = r + 2;
                wordIndex += 1;
            }
        }

        return -1;
    }
};