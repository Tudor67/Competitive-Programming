class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.insert(stations.begin(), {0, 0});
        stations.push_back({target, 0});
        
        priority_queue<int> maxHeap;
        int gas = startFuel;
        int cost = 0;
        for(int i = 1; i < stations.size(); ++i){
            gas -= (stations[i][0] - stations[i - 1][0]);
            while(gas < 0 && !maxHeap.empty()){
                gas += maxHeap.top();
                cost += 1;
                maxHeap.pop();
            }
            
            maxHeap.push(stations[i][1]);
            
            if(gas < 0){
                cost = -1;
                break;
            }
        }
        
        return cost;
    }
};