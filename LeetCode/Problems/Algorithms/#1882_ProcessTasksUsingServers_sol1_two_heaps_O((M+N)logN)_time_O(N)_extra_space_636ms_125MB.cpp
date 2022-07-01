class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        const int N = servers.size();
        const int M = tasks.size();
        
        using T3 = tuple<long long, int, int>;
        using P2 = pair<int, int>;
        priority_queue<T3, vector<T3>, greater<T3>> busyServers;
        priority_queue<P2, vector<P2>, greater<P2>> activeServers;
        for(int i = 0; i < N; ++i){
            activeServers.emplace(servers[i], i);
        }
        
        vector<int> ans(M);
        long long t = -1;
        for(int j = 0; j < M; ++j){
            if(activeServers.empty()){
                t = 1 + get<0>(busyServers.top());
            }else if(t < j){
                t += 1;
            }
            
            while(!busyServers.empty() && get<0>(busyServers.top()) < t){
                int i = get<2>(busyServers.top());
                busyServers.pop();
                activeServers.emplace(servers[i], i);
            }
            
            int i = activeServers.top().second;
            activeServers.pop();
            
            ans[j] = i;
            
            busyServers.emplace(t + tasks[j] - 1, servers[i], i);
        }
        
        return ans;
    }
};