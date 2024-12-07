class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string word;
        int wordIndex = 1;

        while(iss >> word){
            if(searchWord.length() <= word.length() &&
               equal(searchWord.begin(), searchWord.end(), word.begin())){
                return wordIndex;
            }
            wordIndex += 1;
        }

        return -1;
    }
};