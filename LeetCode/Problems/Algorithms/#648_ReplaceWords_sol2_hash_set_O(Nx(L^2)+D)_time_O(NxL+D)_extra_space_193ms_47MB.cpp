class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string resSentence;

        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        istringstream iss(sentence);
        string word;
        while(iss >> word){
            string prefix;
            for(char c: word){
                prefix += c;
                if(dictSet.count(prefix)){
                    break;
                }
            }
            resSentence += prefix;
            resSentence += " ";
        }

        resSentence.pop_back();

        return resSentence;
    }
};