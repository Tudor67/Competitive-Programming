class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        const int N = tasks.size();
        
        using P2 = pair<int, int>;
        priority_queue<P2, vector<P2>, greater<P2>> unavailableTasks; // (enqueueTime, idx)
        priority_queue<P2, vector<P2>, greater<P2>> availableTasks;   // (processingTime, idx)
        for(int i = 0; i < N; ++i){
            unavailableTasks.emplace(tasks[i][0], i);
        }
        
        vector<int> order(N);
        long long t = -1;
        for(int j = 0; j < N; ++j){
            if(availableTasks.empty()){
                if(t < unavailableTasks.top().first){
                    t = unavailableTasks.top().first;
                }
            }
            
            while(!unavailableTasks.empty() && unavailableTasks.top().first <= t){
                int i = unavailableTasks.top().second;
                unavailableTasks.pop();
                availableTasks.emplace(tasks[i][1], i);
            }
            
            int i = availableTasks.top().second;
            availableTasks.pop();
            
            order[j] = i;
            
            t += tasks[i][1];
        }
        
        return order;
    }
};