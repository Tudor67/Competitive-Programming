class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});
        
        const int N = stations.size();
        
        int minRefStops = 0;
        int currentPos = 0;
        int currentGas = startFuel;
        priority_queue<int> gasMaxHeap;
        
        for(int i = 0; i < N; ++i){
            int stationPos = stations[i][0];
            int stationGas = stations[i][1];
            while(!gasMaxHeap.empty() && currentPos + currentGas < stationPos){
                currentGas += gasMaxHeap.top();
                gasMaxHeap.pop();
                minRefStops += 1;
            }
            
            if(currentPos + currentGas >= stationPos){
                currentGas -= (stationPos - currentPos);
                currentPos = stationPos;
                gasMaxHeap.push(stationGas);
            }else{
                minRefStops = -1;
                break;
            }
        }
        
        stations.pop_back();
        
        return minRefStops;
    }
};