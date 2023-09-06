class Solution {
private:
    int computeScore(vector<int>& player){
        const int N = player.size();

        int score = 0;
        int distTo10 = 1e9;
        
        for(int i = 0; i < N; ++i){
            distTo10 += 1;
            
            if(distTo10 <= 2){
                score += 2 * player[i];
            }else{
                score += player[i];
            }

            if(player[i] == 10){
                distTo10 = 0;
            }
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