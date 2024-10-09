class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        const int N = words.size();
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(words[i].length() <= words[j].length()){
                    if(equal(words[i].begin(), words[i].end(), words[j].begin()) &&
                       equal(words[i].rbegin(), words[i].rend(), words[j].rbegin())){
                        res += 1;
                    }
                }
            }
        }
        
        return res;
    }
};