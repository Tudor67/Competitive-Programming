class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        const int N = s.length();
        const int M = words.size();
        
        vector<queue<pair<int, int>>> wordPositionsOf(130);
        for(int j = 0; j < M; ++j){
            wordPositionsOf[words[j][0]].emplace(j, 0);
        }
        
        int matchingSubsequences = 0;
        for(int i = 0; i < N; ++i){
            for(int step = (int)wordPositionsOf[s[i]].size(); step >= 1; --step){
                int j = wordPositionsOf[s[i]].front().first;
                int k = wordPositionsOf[s[i]].front().second;
                wordPositionsOf[s[i]].pop();
                
                if(k + 1 < (int)words[j].length()){
                    wordPositionsOf[words[j][k + 1]].emplace(j, k + 1);
                }else{
                    matchingSubsequences += 1;
                }
            }
        }
        
        return matchingSubsequences;
    }
};