class TaskManager {
private:
    unordered_map<int, int> taskToUser;
    unordered_map<int, int> taskToPriority;
    set<pair<int, int>> tasksSet;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for(vector<int>& task: tasks){
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskToUser[taskId] = userId;
        taskToPriority[taskId] = priority;
        tasksSet.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        tasksSet.erase({taskToPriority[taskId], taskId});
        taskToPriority[taskId] = newPriority;
        tasksSet.insert({taskToPriority[taskId], taskId});
    }
    
    void rmv(int taskId) {
        tasksSet.erase({taskToPriority[taskId], taskId});
        taskToUser.erase(taskId);
        taskToPriority.erase(taskId);
    }
    
    int execTop() {
        if(tasksSet.empty()){
            return -1;
        }
        int taskId = tasksSet.rbegin()->second;
        int userId = taskToUser[taskId];
        rmv(taskId);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */