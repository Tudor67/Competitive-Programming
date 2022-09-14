class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        const int N = tokens.size();
        
        vector<int> sortedTokens = tokens;
        sort(sortedTokens.begin(), sortedTokens.end());
        
        int maxScore = 0;
        int score = 0;
        int i = 0;
        int j = N - 1;
        while(i <= j){
            if(sortedTokens[i] <= power){
                power -= sortedTokens[i];
                score += 1;
                i += 1;
            }else if(score >= 1){
                power += sortedTokens[j];
                score -= 1;
                j -= 1;
            }else{
                i = N;
            }
            maxScore = max(maxScore, score);
        }
        
        return maxScore;
    }
};