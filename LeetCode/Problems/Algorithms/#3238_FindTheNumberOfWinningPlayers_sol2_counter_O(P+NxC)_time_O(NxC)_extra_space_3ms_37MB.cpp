class Solution {
public:
    int winningPlayerCount(int N, vector<vector<int>>& pick) {
        const int COLORS = 11;

        vector<vector<int>> count(N, vector<int>(COLORS));
        for(vector<int>& pc: pick){
            int player = pc[0];
            int color = pc[1];
            count[player][color] += 1;
        }

        int winners = 0;
        for(int player = 0; player < N; ++player){
            for(int color = 0; color < COLORS; ++color){
                if(count[player][color] > player){
                    winners += 1;
                    break;
                }
            }
        }

        return winners;
    }
};