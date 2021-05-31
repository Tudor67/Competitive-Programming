class Solution {
private:
    bool prefixMatch(const string& PREFIX, const string& S){
        for(int i = 0; i < (int)PREFIX.length(); ++i){
            if(i >= (int)S.length() || PREFIX[i] != S[i]){
                return false;
            }
        }
        return true;
    }
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int i = 0;
        for(int j = 0; j < (int)products.size(); ++j){
            if(products[j][0] == searchWord[0]){
                products[i] = products[j];
                i += 1;
            }
        }
        products.resize(i);
        
        const int N = products.size();
        const int WORD_LENGTH = searchWord.length();
        
        sort(products.begin(), products.end());
        
        vector<vector<string>> allSuggestions(WORD_LENGTH);
        for(int i = 0, j = 0; i < WORD_LENGTH; ++i){
            string prefix = searchWord.substr(0, i + 1);
            while(j < N && !prefixMatch(prefix, products[j])){
                j += 1;
            }
            for(int k = j; k < min(j + 3, N) && prefixMatch(prefix, products[k]); ++k){
                allSuggestions[i].push_back(products[k]);
            }
        }
        
        return allSuggestions;
    }
};