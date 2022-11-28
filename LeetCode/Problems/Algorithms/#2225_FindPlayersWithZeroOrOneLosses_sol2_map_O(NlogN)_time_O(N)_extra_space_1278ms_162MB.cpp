class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        const int N = matches.size();
        
        map<int, int> lostMatchesCount;
        for(const vector<int>& MATCH: matches){
            int winner = MATCH[0];
            int loser = MATCH[1];
            if(!lostMatchesCount.count(winner)){
                lostMatchesCount[winner] = 0;
            }
            lostMatchesCount[loser] += 1;
        }
        
        vector<vector<int>> res(2);
        for(const pair<int, int>& P: lostMatchesCount){
            int player = P.first;
            int playerLostMatches = P.second;
            if(playerLostMatches <= 1){
                res[playerLostMatches].push_back(player);
            }
        }
        
        return res;
    }
};