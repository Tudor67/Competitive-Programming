class Solution {
private:
    bool isPossible(vector<int>& sortedTasks, vector<int>& sortedWorkers, int pills, int strength, int tasksToComplete){
        multiset<int> workersMultiset(sortedWorkers.end() - tasksToComplete, sortedWorkers.end());

        for(int i = tasksToComplete - 1; i >= 0; --i){
            auto it = workersMultiset.lower_bound(sortedTasks[i]);
            if(it == workersMultiset.end() && pills >= 1){
                it = workersMultiset.lower_bound(sortedTasks[i] - strength);
                pills -= 1;
            }

            if(it == workersMultiset.end()){
                return false;
            }else{
                workersMultiset.erase(it);
            }
        }

        return true;
    }

public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        const int T = tasks.size();
        const int W = workers.size();

        vector<int> sortedTasks = tasks;
        sort(sortedTasks.begin(), sortedTasks.end());

        vector<int> sortedWorkers = workers;
        sort(sortedWorkers.begin(), sortedWorkers.end());

        int l = 0;
        int r = min(T, W);
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(sortedTasks, sortedWorkers, pills, strength, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};