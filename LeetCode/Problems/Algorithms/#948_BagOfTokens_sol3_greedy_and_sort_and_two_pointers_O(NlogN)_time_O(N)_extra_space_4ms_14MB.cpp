class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        const int N = tokens.size();

        vector<int> sortedTokens = tokens;
        sort(sortedTokens.begin(), sortedTokens.end());

        int l = 0;
        int r = N - 1;
        int score = 0;
        int maxScore = 0;
        while(l <= r){
            if(sortedTokens[l] <= power){
                power -= sortedTokens[l];
                l += 1;
                score += 1;
                maxScore = max(maxScore, score);
            }else if(score >= 1){
                power += sortedTokens[r];
                r -= 1;
                score -= 1;
            }else{
                break;
            }
        }

        return maxScore;
    }
};