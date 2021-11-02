class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIdx = 0;
        for(int i = 0; i + (int)searchWord.length() - 1 < (int)sentence.length(); ++i){
            if(i == 0 || sentence[i - 1] == ' '){
                wordIdx += 1;
                if(searchWord.compare(0, searchWord.length(), sentence, i, searchWord.length()) == 0){
                    return wordIdx;
                }
            }
        }
        return -1;
    }
};