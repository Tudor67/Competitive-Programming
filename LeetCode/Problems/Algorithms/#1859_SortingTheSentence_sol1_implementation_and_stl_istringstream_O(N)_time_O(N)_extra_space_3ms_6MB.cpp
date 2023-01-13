class Solution {
public:
    string sortSentence(string s) {
        vector<string> words;

        istringstream iss(s);
        string currentWord;
        while(iss >> currentWord){
            int index = (currentWord.back() - '0') - 1;
            currentWord.pop_back();
            if(index >= (int)words.size()){
                words.resize(index + 1);
            }
            words[index] = currentWord;
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