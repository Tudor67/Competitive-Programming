class Solution {
private:
    string getNormFormOfWord(const string& WORD){
        string normForm;
        unordered_map<char, int> indexOf;
        for(char c: WORD){
            if(!indexOf.count(c)){
                int index = indexOf.size();
                indexOf[c] = index;
            }
            normForm += to_string(indexOf[c]) + "#";
        }
        return normForm;
    }

    string getNormFormOfSentence(const string& SENTENCE){
        string normForm;
        unordered_map<string, int> indexOf;
        int startPos = 0;
        for(int pos = 0; pos <= (int)SENTENCE.length(); ++pos){
            if(pos == (int)SENTENCE.length() || SENTENCE[pos] == ' '){
                string word = SENTENCE.substr(startPos, pos - startPos);
                startPos = pos + 1;
                if(!indexOf.count(word)){
                    int index = indexOf.size();
                    indexOf[word] = index;
                }
                normForm += to_string(indexOf[word]) + "#";
            }
        }
        return normForm;
    }

public:
    bool wordPattern(string pattern, string s) {
        return getNormFormOfWord(pattern) == getNormFormOfSentence(s);
    }
};