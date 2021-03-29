class Solution {
private:
    string getLowerForm(const string& WORD){
        string lowerWord = WORD;
        transform(WORD.begin(), WORD.end(), lowerWord.begin(), ::tolower);
        return lowerWord;
    }
    
    string getVowelForm(const string& WORD){
        string vowelWord;
        for(int i = 0; i < (int)WORD.length(); ++i){
            char c = tolower(WORD[i]);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                vowelWord += '#';
            }else{
                vowelWord += c;
            }
        }
        return vowelWord;
    }
    
public:
    vector<string> spellchecker(vector<string>& wordList, vector<string>& queries) {
        unordered_set<string> wordListSet(wordList.begin(), wordList.end());
        unordered_map<string, string> capitalWordMap;
        unordered_map<string, string> vowelWordMap;
        
        for(const string& WORD: wordList){
            string lowerWord = getLowerForm(WORD);
            if(!capitalWordMap.count(lowerWord)){
                capitalWordMap[lowerWord] = WORD;
            }
            string vowelWord = getVowelForm(WORD);
            if(!vowelWordMap.count(vowelWord)){
                vowelWordMap[vowelWord] = WORD;
            }
        }
        
        vector<string> answer;
        for(const string& QUERY: queries){
            string lowerQuery = getLowerForm(QUERY);
            string vowelQuery = getVowelForm(QUERY);
            if(wordListSet.count(QUERY)){
                answer.push_back(QUERY);
            }else if(capitalWordMap.count(lowerQuery)){
                answer.push_back(capitalWordMap[lowerQuery]);
            }else if(vowelWordMap.count(vowelQuery)){
                answer.push_back(vowelWordMap[vowelQuery]);
            }else{
                answer.push_back("");
            }
        }
        
        return answer;
    }
};