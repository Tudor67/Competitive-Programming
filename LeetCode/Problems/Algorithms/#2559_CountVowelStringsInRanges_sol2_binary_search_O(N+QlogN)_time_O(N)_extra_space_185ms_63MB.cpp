class Solution {
private:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const int N = words.size();
        const int Q = queries.size();
        
        vector<int> goodPositions;
        for(int i = 0; i < N; ++i){
            if(isVowel(words[i].front()) && isVowel(words[i].back())){
                goodPositions.push_back(i);
            }
        }
        
        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            res[i] = upper_bound(goodPositions.begin(), goodPositions.end(), r) -
                     lower_bound(goodPositions.begin(), goodPositions.end(), l);
        }
        
        return res;
    }
};