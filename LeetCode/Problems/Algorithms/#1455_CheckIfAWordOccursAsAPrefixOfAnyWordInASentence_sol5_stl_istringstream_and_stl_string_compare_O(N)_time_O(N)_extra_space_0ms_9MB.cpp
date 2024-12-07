class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string word;
        int wordIndex = 1;

        while(iss >> word){
            if(word.compare(0, searchWord.length(), searchWord) == 0){
                return wordIndex;
            }
            wordIndex += 1;
        }

        return -1;
    }
};