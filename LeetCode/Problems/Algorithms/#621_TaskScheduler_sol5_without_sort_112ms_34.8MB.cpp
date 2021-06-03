class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskCnt(128, 0);
        for(char task: tasks){
            taskCnt[task] += 1;
        }
        
        int remainingTasks = tasks.size();
        int pos = 0;
        for(int iteration = 1; remainingTasks > 0; ++iteration){
            for(char task = 'A'; task <= 'Z'; ++task){
                if(taskCnt[task] > 0){
                    taskCnt[task] -= 1;
                    pos += 1;
                    remainingTasks -= 1;
                }
            }
            if(remainingTasks > 0){
                pos = max(iteration * (n + 1), pos);
            }
        }
        
        return pos;
    }
};