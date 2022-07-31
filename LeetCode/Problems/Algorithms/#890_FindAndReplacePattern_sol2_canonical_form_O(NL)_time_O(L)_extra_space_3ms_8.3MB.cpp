class Solution {
private:
    string getCanonicalForm(const string& WORD){
        const int L = WORD.length();
        string canonicalForm(L, '.');
        unordered_map<char, char> p;
        char c = 'a';
        for(int i = 0; i < L; ++i){
            if(!p.count(WORD[i])){
                p[WORD[i]] = c;
                c += 1;
            }
            canonicalForm[i] = p[WORD[i]];
        }
        return canonicalForm;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        string patternCanonicalForm = getCanonicalForm(pattern);
        for(const string& WORD: words){
            string wordCanonicalForm = getCanonicalForm(WORD);
            if(wordCanonicalForm == patternCanonicalForm){
                res.push_back(WORD);
            }
        }
        return res;
    }
};