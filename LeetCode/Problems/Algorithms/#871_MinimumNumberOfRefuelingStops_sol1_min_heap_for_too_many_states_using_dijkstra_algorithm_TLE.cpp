struct State{
    int refuelingStops;
    long long carGas;
    long long stationGas;
    int stationIdx;
    
    State(int refuelingStops, long long carGas, long long stationGas, int stationIdx){
        this->refuelingStops = refuelingStops;
        this->carGas = carGas;
        this->stationGas = stationGas;
        this->stationIdx = stationIdx;
    }
};

struct MinHeapStateComparator{
    bool operator()(const State& LHS, const State& RHS) const {
        return (LHS.refuelingStops > RHS.refuelingStops);
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // Step 1: add start and target stations
        stations.insert(stations.begin(), {0, 0});
        stations.push_back({target, 0});
        
        // Step 2: minCostAtStation[i][{carGas, stationGas}] - minimum number of refueling stops at the ith station
        //                                                     with remaining carGas and stationGas
        const int N = stations.size();
        vector<map<pair<long long, long long>, int>> minCostAtStation(N + 1);
        minCostAtStation[0][{startFuel, 0}] = 0;
        
        // Step 3: prepare minHeap
        priority_queue<State, vector<State>, MinHeapStateComparator> minHeap;
        minHeap.push(State(0, startFuel, 0, 0));
        
        // Step 4: extend the current states (using Dijkstra's algorithm) until the target state is reached
        while(!minHeap.empty()){
            State state = minHeap.top();
            minHeap.pop();
            
            if(state.stationIdx == N - 1){
                return state.refuelingStops;
            }
            
            // ignore states that have a better cost in minHeap
            bool stateVisited = minCostAtStation[state.stationIdx].count({state.carGas, state.stationGas});
            if(stateVisited && minCostAtStation[state.stationIdx][{state.carGas, state.stationGas}] < state.refuelingStops){
                continue;
            }
            
            bool continueExtension = true;
            for(int nextStationIdx = state.stationIdx + 1; continueExtension && nextStationIdx < N; ++nextStationIdx){
                continueExtension = false;
                long long transitionGas = stations[nextStationIdx][0] - stations[state.stationIdx][0];
                long long nextStationGas = stations[nextStationIdx][1];
                
                if(transitionGas <= state.carGas){
                    continueExtension = true;
                    int nextStateRefuelingStops = state.refuelingStops;
                    long long nextCarGas = state.carGas - transitionGas;
                    State nextState(nextStateRefuelingStops, nextCarGas, nextStationGas, nextStationIdx);
                    bool nextStateVisited = minCostAtStation[nextStationIdx].count({nextCarGas, nextStationGas});
                    if(!nextStateVisited ||
                       (nextStateVisited && minCostAtStation[nextStationIdx][{nextCarGas, nextStationGas}] > nextStateRefuelingStops)){
                        minCostAtStation[nextStationIdx][{nextCarGas, nextStationGas}] = nextStateRefuelingStops;
                        minHeap.push(nextState);
                    }
                }
                
                if(state.stationGas > 0 && transitionGas <= state.carGas + state.stationGas){
                    continueExtension = true;
                    int nextStateRefuelingStops = 1 + state.refuelingStops;
                    long long nextCarGas = state.carGas + state.stationGas - transitionGas;
                    State nextState(nextStateRefuelingStops, nextCarGas, nextStationGas, nextStationIdx);
                    bool nextStateVisited = minCostAtStation[nextStationIdx].count({nextCarGas, nextStationGas});
                    if(!nextStateVisited ||
                       (nextStateVisited && minCostAtStation[nextStationIdx][{nextCarGas, nextStationGas}] > nextStateRefuelingStops)){
                        minCostAtStation[nextStationIdx][{nextCarGas, nextStationGas}] = nextStateRefuelingStops;
                        minHeap.push(nextState);
                    }
                }
            }
        }
        
        return -1;
    }
};