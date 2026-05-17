class Solution {
private:
    bool isPossible(vector<pair<int, int>>& sortedTasks, int startEnergy){
        int currEnergy = startEnergy;
        for(auto& [taskActualEnergy, taskMinimumEnergy]: sortedTasks){
            if(currEnergy >= taskMinimumEnergy){
                currEnergy -= taskActualEnergy;
            }else{
                return false;
            }
        }
        return true;
    }

public:
    int minimumEffort(vector<vector<int>>& tasks) {
        const int N = tasks.size();

        vector<pair<int, int>> sortedTasks(N);
        int aSum = 0;
        int mSum = 0;
        for(int i = 0; i < N; ++i){
            sortedTasks[i] = {tasks[i][0], tasks[i][1]};
            aSum += tasks[i][0];
            mSum += tasks[i][1];
        }

        sort(sortedTasks.begin(), sortedTasks.end(),
             [](const pair<int, int>& LHS, const pair<int, int>& RHS){
                return (LHS.second - LHS.first > RHS.second - RHS.first);
             });

        int l = aSum;
        int r = mSum;
        while(l != r){
            int mid = (l + r) / 2;
            if(isPossible(sortedTasks, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return r;
    }
};