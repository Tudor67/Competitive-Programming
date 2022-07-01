struct DecEnqueueTimeComp{
    const vector<vector<int>>& TASKS;
    
    DecEnqueueTimeComp(vector<vector<int>>& tasks): TASKS(tasks){
        
    }
    
    bool operator()(const int& LHS_IDX, const int& RHS_IDX) const{
        const int& LHS_ENQUEUE_TIME = TASKS[LHS_IDX][0];
        const int& RHS_ENQUEUE_TIME = TASKS[RHS_IDX][0];
        return LHS_ENQUEUE_TIME > RHS_ENQUEUE_TIME;
    };
};

struct DecProcessingTimeIdxComp{
    const vector<vector<int>>& TASKS;
    
    DecProcessingTimeIdxComp(vector<vector<int>>& tasks): TASKS(tasks){
        
    }
    
    bool operator()(const int& LHS_IDX, const int& RHS_IDX) const{
        const int& LHS_PROCESSING_TIME = TASKS[LHS_IDX][1];
        const int& RHS_PROCESSING_TIME = TASKS[RHS_IDX][1];
        return pair<int, int>{LHS_PROCESSING_TIME, LHS_IDX} > pair<int, int>{RHS_PROCESSING_TIME, RHS_IDX};
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        const int N = tasks.size();
        
        priority_queue<int, vector<int>, DecEnqueueTimeComp> unavailableTaskIDs(DecEnqueueTimeComp{tasks});
        priority_queue<int, vector<int>, DecProcessingTimeIdxComp> availableTaskIDs(DecProcessingTimeIdxComp{tasks});
        
        for(int i = 0; i < N; ++i){
            unavailableTaskIDs.push(i);
        }
        
        vector<int> order(N);
        long long t = -1;
        for(int j = 0; j < N; ++j){
            if(availableTaskIDs.empty()){
                if(t < tasks[unavailableTaskIDs.top()][0]){
                    t = tasks[unavailableTaskIDs.top()][0];
                }
            }
            
            while(!unavailableTaskIDs.empty() && tasks[unavailableTaskIDs.top()][0] <= t){
                int i = unavailableTaskIDs.top();
                unavailableTaskIDs.pop();
                availableTaskIDs.emplace(i);
            }
            
            int i = availableTaskIDs.top();
            availableTaskIDs.pop();
            
            order[j] = i;
            
            t += tasks[i][1];
        }
        
        return order;
    }
};