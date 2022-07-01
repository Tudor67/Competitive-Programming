struct Task{
    int enqueueTime;
    int processingTime;
    int idx;
    
    Task(int enqueueTime, int processingTime, int idx){
        this->enqueueTime = enqueueTime;
        this->processingTime = processingTime;
        this->idx = idx;
    }
    
    struct DecEnqueueTimeComp{
        bool operator()(const Task& LHS, const Task& RHS) const{
            return LHS.enqueueTime > RHS.enqueueTime;
        }
    };
    
    struct DecProcessingTimeIdxComp{
        bool operator()(const Task& LHS, const Task& RHS) const{
            return pair<int, int>(LHS.processingTime, LHS.idx) >
                   pair<int, int>(RHS.processingTime, RHS.idx);
        }
    };
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        const int N = tasks.size();
        
        priority_queue<Task, vector<Task>, Task::DecEnqueueTimeComp> unavailableTasks;
        priority_queue<Task, vector<Task>, Task::DecProcessingTimeIdxComp> availableTasks;
        for(int i = 0; i < N; ++i){
            unavailableTasks.push(Task(tasks[i][0], tasks[i][1], i));
        }
        
        vector<int> order(N);
        long long currentTime = -1;
        for(int j = 0; j < N; ++j){
            if(availableTasks.empty()){
                if(currentTime < unavailableTasks.top().enqueueTime){
                    currentTime = unavailableTasks.top().enqueueTime;
                }
            }
            
            while(!unavailableTasks.empty() && unavailableTasks.top().enqueueTime <= currentTime){
                Task task = unavailableTasks.top();
                unavailableTasks.pop();
                availableTasks.push(task);
            }
            
            Task currentTask = availableTasks.top();
            availableTasks.pop();
            
            order[j] = currentTask.idx;
            
            currentTime += currentTask.processingTime;
        }
        
        return order;
    }
};