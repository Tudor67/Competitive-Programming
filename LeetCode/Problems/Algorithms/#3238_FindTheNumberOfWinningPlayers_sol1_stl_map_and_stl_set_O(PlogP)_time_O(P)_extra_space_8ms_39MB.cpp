class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<pair<int, int>, int> count;
        for(vector<int>& pc: pick){
            int player = pc[0];
            int color = pc[1];
            count[{player, color}] += 1;
        }

        set<int> winners;
        for(const auto& [pc, pcCount]: count){
            int player = pc.first;
            if(player < pcCount){
                winners.insert(player);
            }
        }

        return winners.size();
    }
};