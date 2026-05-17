class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        const int N = tasks.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (tasks[lhs][1] - tasks[lhs][0] > tasks[rhs][1] - tasks[rhs][0]);
             });

        int startEnergy = 0;
        int currEnergy = 0;
        for(int i: p){
            int taskActualEnergy = tasks[i][0];
            int taskMinimumEnergy = tasks[i][1];
            if(currEnergy < taskMinimumEnergy){
                int delta = taskMinimumEnergy - currEnergy;
                startEnergy += delta;
                currEnergy  += delta;
            }
            currEnergy -= taskActualEnergy;
        }

        return startEnergy;
    }
};