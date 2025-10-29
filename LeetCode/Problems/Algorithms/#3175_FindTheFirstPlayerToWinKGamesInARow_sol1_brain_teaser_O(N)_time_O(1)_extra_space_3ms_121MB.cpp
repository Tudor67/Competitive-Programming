class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        const int N = skills.size();

        int winner = 0;
        int gamesWon = 0;

        for(int i = 1; i < N; ++i){
            if(skills[winner] > skills[i]){
                gamesWon += 1;
            }else{
                winner = i;
                gamesWon = 1;
            }

            if(gamesWon == k){
                break;
            }
        }

        return winner;
    }
};