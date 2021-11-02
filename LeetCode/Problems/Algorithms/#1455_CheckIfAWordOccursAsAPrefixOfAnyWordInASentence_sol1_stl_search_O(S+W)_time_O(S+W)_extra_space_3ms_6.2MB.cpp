class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence = " " + sentence;
        searchWord = " " + searchWord;
        string::iterator it = search(sentence.begin(), sentence.end(), searchWord.begin(), searchWord.end());
        if(it == sentence.end()){
            return -1;
        }
        return count(sentence.begin(), it + 1, ' ');
    }
};