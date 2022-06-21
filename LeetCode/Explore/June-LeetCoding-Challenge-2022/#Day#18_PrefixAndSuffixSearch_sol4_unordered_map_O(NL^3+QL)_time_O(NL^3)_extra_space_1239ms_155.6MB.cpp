class WordFilter {
private:
    const string SPECIAL_STRING = "#";
    unordered_map<string, int> maxIdxOf;
    
public:
    WordFilter(vector<string>& words) {
        const int N = words.size();
        for(int i = 0; i < N; ++i){
            const int L = words[i].length();
            for(int prefixLength = 0; prefixLength <= L; ++prefixLength){
                string prefix(words[i].begin(), words[i].begin() + prefixLength);
                for(int suffixLength = 0; suffixLength <= L; ++suffixLength){
                    string reversedSuffix(words[i].rbegin(), words[i].rbegin() + suffixLength);
                    string encoding = prefix + SPECIAL_STRING + reversedSuffix;
                    maxIdxOf[encoding] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string encoding = prefix + SPECIAL_STRING + string(suffix.rbegin(), suffix.rend());
        if(maxIdxOf.count(encoding)){
            return maxIdxOf[encoding];
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */