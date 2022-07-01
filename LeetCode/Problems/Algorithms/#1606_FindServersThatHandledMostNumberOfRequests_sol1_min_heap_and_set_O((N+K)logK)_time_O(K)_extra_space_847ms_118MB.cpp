class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        const int N = arrival.size();
        
        set<int> freeServerIndices;
        for(int serverIndex = 0; serverIndex < k; ++serverIndex){
            freeServerIndices.insert(serverIndex);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyTimeAndServerIndices;
        vector<int> count(k);
        for(int i = 0; i < N; ++i){
            int t = arrival[i];
            while(!busyTimeAndServerIndices.empty() && busyTimeAndServerIndices.top().first < t){
                int serverIndex = busyTimeAndServerIndices.top().second;
                freeServerIndices.insert(serverIndex);
                busyTimeAndServerIndices.pop();
            }
            
            if(freeServerIndices.empty()){
                continue;
            }
            
            int targetServerIndex = i % k;
            auto it = freeServerIndices.lower_bound(targetServerIndex);
            if(it == freeServerIndices.end()){
                it = freeServerIndices.begin();
            }
            int serverIndex = *it;
            count[serverIndex] += 1;
            freeServerIndices.erase(serverIndex);
            busyTimeAndServerIndices.emplace(arrival[i] + load[i] - 1, serverIndex);
        }
        
        vector<int> busiestServerIndices;
        int maxCount = *max_element(count.begin(), count.end());
        for(int serverIndex = 0; serverIndex < k; ++serverIndex){
            if(count[serverIndex] == maxCount){
                busiestServerIndices.push_back(serverIndex);
            }
        }
        
        return busiestServerIndices;
    }
};