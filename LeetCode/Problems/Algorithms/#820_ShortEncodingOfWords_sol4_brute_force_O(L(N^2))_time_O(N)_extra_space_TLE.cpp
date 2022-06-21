class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        const int N = words.size();
        
        vector<bool> isRemoved(N, false);
        for(int i = 0; i < N; ++i){
            if(isRemoved[i]){
                continue;
            }
            for(int j = 0; j < N; ++j){
                if(i != j && !isRemoved[j] && words[i].length() <= words[j].length()){
                    if(equal(words[i].rbegin(), words[i].rend(), words[j].rbegin())){
                        isRemoved[i] = true;
                        break;
                    }
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            if(!isRemoved[i]){
                res += words[i].length();
                res += 1;
            }
        }
        
        return res;
    }
};