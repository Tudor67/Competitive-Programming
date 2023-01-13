class Solution {
public:
    string sortSentence(string s) {
        vector<string> words;

        string currentWord;
        for(char c: s){
            if(isdigit(c)){
                int index = (c - '0') - 1;
                if(index >= (int)words.size()){
                    words.resize(index + 1);
                }
                words[index] = currentWord;
                currentWord.clear();
            }else if(c != ' '){
                currentWord += c;
            }
        }

        string sentence;
        for(const string& WORD: words){
            sentence += WORD;
            sentence += " ";
        }
        sentence.pop_back();

        return sentence;
    }
};