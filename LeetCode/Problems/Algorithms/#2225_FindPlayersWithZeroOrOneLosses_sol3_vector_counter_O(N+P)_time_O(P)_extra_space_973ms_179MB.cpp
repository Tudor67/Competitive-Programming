class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int maxPlayer = 0;
        for(const vector<int>& MATCH: matches){
            int player0 = MATCH[0];
            int player1 = MATCH[1];
            maxPlayer = max(maxPlayer, max(player0, player1));
        }
        
        vector<bool> vis(maxPlayer + 1, false);
        vector<int> lossesCount(maxPlayer + 1);
        for(const vector<int>& MATCH: matches){
            int winner = MATCH[0];
            int loser = MATCH[1];
            vis[winner] = true;
            vis[loser] = true;
            lossesCount[loser] += 1;
        }
        
        vector<vector<int>> res(2);
        for(int player = 0; player <= maxPlayer; ++player){
            if(vis[player] && lossesCount[player] <= 1){
                res[lossesCount[player]].push_back(player);
            }
        }
        
        return res;
    }
};