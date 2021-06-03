class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(128, 0);
        for(char task: tasks){
            cnt[task] += 1;
        }
        
        vector<pair<int, char>> cntTask;
        for(char task = 'A'; task <= 'Z'; ++task){
            if(cnt[task] > 0){
                cntTask.push_back({cnt[task], task});
            }
        }
        
        int answer = 0;
        int remainingTasks = tasks.size();
        while(remainingTasks > 0){
            sort(cntTask.rbegin(), cntTask.rend());
            int timeUnits = 0;
            for(int i = 0; i < min(n + 1, (int)cntTask.size()); ++i){
                if(cntTask[i].first > 0){
                    cntTask[i].first -= 1;
                    remainingTasks -= 1;
                    timeUnits += 1;
                }
            }
            if(remainingTasks > 0){
                timeUnits = n + 1;
            }
            answer += timeUnits;
        }
        
        return answer;
    }
};