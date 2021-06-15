class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        const int N = stations.size();
        stations.push_back({target, 0});
        priority_queue<int> maxHeap;
        int gas = startFuel;
        int minStops = 0;
        for(int i = 0; i <= N; ++i){
            int dist = stations[i][0];
            while(gas < dist && !maxHeap.empty()){
                gas += maxHeap.top();
                maxHeap.pop();
                minStops += 1;
            }
            if(gas < dist){
                minStops = -1;
                break;
            }
            maxHeap.push(stations[i][1]);
        }
        return minStops;
    }
};