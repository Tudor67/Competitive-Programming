class Solution {
private:
    static string getCanonicalForm(const string& S){
        string sCanonicalForm;
        unordered_map<char, int> idxOf;
        for(char c: S){
            if(!idxOf.count(c)){
                idxOf[c] = 1 + idxOf.size();
            }
            sCanonicalForm += char(idxOf[c] + 'a');
        }
        return sCanonicalForm;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> answer;
        string patternCanonicalForm = getCanonicalForm(pattern);
        for(const string& WORD: words){
            if(getCanonicalForm(WORD) == patternCanonicalForm){
                answer.push_back(WORD);
            }
        }
        return answer;
    }
};