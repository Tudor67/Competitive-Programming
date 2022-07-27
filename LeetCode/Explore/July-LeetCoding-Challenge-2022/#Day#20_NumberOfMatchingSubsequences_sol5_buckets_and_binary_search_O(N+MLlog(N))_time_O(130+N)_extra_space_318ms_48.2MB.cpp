class Solution {
private:
    bool isSubsequence(const string& WORD, vector<vector<int>>& sIndicesOf, const int& N){
        int i = 0;
        for(char c: WORD){
            vector<int>::iterator it  = lower_bound(sIndicesOf[c].begin(), sIndicesOf[c].end(), i);
            if(it == sIndicesOf[c].end()){
                return false;
            }else{
                i = *it + 1;
            }
        }
        return true;
    }
    
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        const int N = s.length();
        const int M = words.size();
        
        vector<vector<int>> sIndicesOf(130);
        for(int i = 0; i < N; ++i){
            sIndicesOf[s[i]].push_back(i);
        }
        
        int matchingSubsequences = 0;
        for(int j = 0; j < M; ++j){
            if(isSubsequence(words[j], sIndicesOf, N)){
                matchingSubsequences += 1;
            }
        }
        
        return matchingSubsequences;
    }
};