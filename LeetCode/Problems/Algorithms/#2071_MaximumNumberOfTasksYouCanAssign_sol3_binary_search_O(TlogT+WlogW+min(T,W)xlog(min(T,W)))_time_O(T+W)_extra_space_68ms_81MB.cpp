class Solution {
private:
    bool isPossible(vector<int>& sortedTasks, vector<int>& sortedWorkers, int pills, int strength, int tasksToComplete){
        const int W = sortedWorkers.size();

        deque<int> dq;
        int j = W - 1;

        for(int i = tasksToComplete - 1; i >= 0; --i){
            while(W - tasksToComplete <= j && sortedWorkers[j] + strength >= sortedTasks[i]){
                dq.push_front(j);
                j -= 1;
            }

            if(!dq.empty() && sortedWorkers[dq.back()] >= sortedTasks[i]){
                dq.pop_back();
            }else if(!dq.empty() && pills >= 1){
                dq.pop_front();
                pills -= 1;
            }else{
                return false;
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