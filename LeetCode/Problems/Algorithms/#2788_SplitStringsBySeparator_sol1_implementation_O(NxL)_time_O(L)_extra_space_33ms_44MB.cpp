class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        const int N = words.size();
        
        vector<string> res;

        for(const string& WORD: words){
            const int L = WORD.length();
            string s;
            for(int i = 0; i < L; ++i){
                if(WORD[i] != separator){
                    s += WORD[i];
                }
                if(i == L - 1 || WORD[i] == separator){
                    if(!s.empty()){
                        res.push_back(s);
                    }
                    s.clear();
                }
            }
        }
        
        return res;
    }
};