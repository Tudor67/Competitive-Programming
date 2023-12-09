class Solution {
private:
    string concatenate(vector<string>& words){
        string s;
        for(const string& WORD: words){
            s += WORD;
        }
        return s;
    }

public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return concatenate(word1) == concatenate(word2);
    }
};