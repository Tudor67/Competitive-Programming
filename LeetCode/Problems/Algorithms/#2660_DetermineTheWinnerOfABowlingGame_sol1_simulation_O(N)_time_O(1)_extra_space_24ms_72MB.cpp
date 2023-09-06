class Solution {
private:
    int computeScore(vector<int>& player){
        const int N = player.size();

        int score = 0;
        for(int i = 0; i < N; ++i){
            int coef = 1;
            for(int j = max(0, i - 2); j <= i - 1; ++j){
                if(player[j] == 10){
                    coef = 2;
                }
            }
            score += coef * player[i];
        }

        return score;
    }

public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = computeScore(player1);
        int score2 = computeScore(player2);
        
        if(score1 > score2){
            return 1;
        }
        if(score2 > score1){
            return 2;
        }
        return 0;
    }
};