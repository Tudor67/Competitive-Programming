class Solution {
private:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const int N = words.size();
        const int Q = queries.size();
        
        vector<int> prefSum(N);
        for(int i = 0; i < N; ++i){
            if(isVowel(words[i].front()) && isVowel(words[i].back())){
                prefSum[i] = 1;
            }
            if(i >= 1){
                prefSum[i] += prefSum[i - 1];
            }
        }
        
        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            res[i] = prefSum[r];
            if(l >= 1){
                res[i] -= prefSum[l - 1];
            }
        }
        
        return res;
    }
};