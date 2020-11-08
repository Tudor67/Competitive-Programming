class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        map<int, int> posChips;
        for(int pos: position){
            posChips[pos] += 1;
        }
        
        int minCost = INT_MAX;
        for(int targetPos = 0; targetPos <= 1; ++targetPos){
            int cost = 0;
            for(const pair<int, int>& P2: posChips){
                int pos = P2.first;
                int chips = P2.second;
                cost += (abs(pos - targetPos) % 2) * chips;
            }
            minCost = min(cost, minCost);
        }
        
        return minCost;
    }
};