class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int J = profit.size();
        const int W = worker.size();

        auto incJobProfitComp = [&](int lhs, int rhs){
            return (profit[lhs] < profit[rhs]);
        };
        auto incWorkerDifficultyComp = [&](int lhs, int rhs){
            return (worker[lhs] < worker[rhs]);
        };
        priority_queue<int, vector<int>, decltype(incJobProfitComp)> jobProfitMaxHeap(incJobProfitComp);
        priority_queue<int, vector<int>, decltype(incWorkerDifficultyComp)> workerDifficultyMaxHeap(incWorkerDifficultyComp);

        for(int i = 0; i < J; ++i){
            jobProfitMaxHeap.push(i);
        }

        for(int i = 0; i < W; ++i){
            workerDifficultyMaxHeap.push(i);
        }

        int totalProfit = 0;
        while(!jobProfitMaxHeap.empty() && !workerDifficultyMaxHeap.empty()){
            if(worker[workerDifficultyMaxHeap.top()] >= difficulty[jobProfitMaxHeap.top()]){
                totalProfit += profit[jobProfitMaxHeap.top()];
                workerDifficultyMaxHeap.pop();
            }else{
                jobProfitMaxHeap.pop();
            }
        }

        return totalProfit;
    }
};