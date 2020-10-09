class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> profitDifficulty(profit.size());
        for(int i = 0; i < profitDifficulty.size(); ++i){
            profitDifficulty[i] = {profit[i], difficulty[i]};
        }
        
        sort(profitDifficulty.rbegin(), profitDifficulty.rend());
        sort(worker.rbegin(), worker.rend());
        
        int answer = 0;
        for(int profitIdx = 0, workerIdx = 0; profitIdx < profitDifficulty.size() && workerIdx < worker.size(); ++profitIdx){
            if(profitDifficulty[profitIdx].second <= worker[workerIdx]){
                answer += profitDifficulty[profitIdx].first;
                workerIdx += 1;
                profitIdx -= 1;
            }
        }
        
        return answer;
    }
};