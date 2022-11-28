class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        const int N = matches.size();
        
        set<int> playersSet;
        map<int, int> lostMatchesCount;
        for(const vector<int>& MATCH: matches){
            int winner = MATCH[0];
            int loser = MATCH[1];
            playersSet.insert(winner);
            playersSet.insert(loser);
            lostMatchesCount[loser] += 1;
        }
        
        vector<vector<int>> res(2);
        for(int player: playersSet){
            if(lostMatchesCount.count(player)){
                if(lostMatchesCount[player] == 1){
                    res[1].push_back(player);
                }
            }else{
                res[0].push_back(player);
            }
        }
        
        return res;
    }
};