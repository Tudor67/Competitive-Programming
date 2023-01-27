class Solution {
private:
    enum BridgeSide {LEFT = 0, RIGHT = 1};
    using T3 = tuple<int, int, int>;
    using MaxHeap = priority_queue<T3, vector<T3>, less<T3>>;
    using MinHeap = priority_queue<T3, vector<T3>, greater<T3>>;

    void removeRedundantWorkers(MaxHeap& freeHeap, MinHeap& busyHeap, int& n){
        while(n == 0 && !freeHeap.empty() && get<0>(freeHeap.top()) == BridgeSide::LEFT){
            freeHeap.pop();
        }
        while(n == 0 && !busyHeap.empty() && get<1>(busyHeap.top()) == BridgeSide::LEFT){
            busyHeap.pop();
        }
    }

    void updateBridgeActiveTime(MaxHeap& freeHeap, MinHeap& busyHeap, int& bridgeActiveTime){
        if(freeHeap.empty()){
            bridgeActiveTime = max(bridgeActiveTime, get<0>(busyHeap.top()));
        }
    }

    void updateHeaps(MaxHeap& freeHeap, MinHeap& busyHeap, int& bridgeActiveTime, vector<vector<int>>& time){
        while(!busyHeap.empty() && get<0>(busyHeap.top()) <= bridgeActiveTime){
            int currentBridgeSide = get<1>(busyHeap.top());
            int i = get<2>(busyHeap.top());
            int lrTime = time[i][0];
            int rlTime = time[i][2];

            busyHeap.pop();
            freeHeap.push({currentBridgeSide, lrTime + rlTime, i});
        }
    }
    
    void crossTheBridge(MaxHeap& freeHeap, MinHeap& busyHeap, int& bridgeActiveTime, vector<vector<int>>& time, int& n){
        int currentBridgeSide = get<0>(freeHeap.top());
        int i = get<2>(freeHeap.top());
        int lrTime = time[i][0];
        int pickTime = time[i][1];
        int rlTime = time[i][2];
        int putTime = time[i][3];
        freeHeap.pop();

        if(currentBridgeSide == BridgeSide::LEFT){
            n -= 1;
            busyHeap.push({bridgeActiveTime + lrTime + pickTime, BridgeSide::RIGHT, i});
            bridgeActiveTime += lrTime;
        }else{
            busyHeap.push({bridgeActiveTime + rlTime + putTime, BridgeSide::LEFT, i});
            bridgeActiveTime += rlTime;
        }
    }

public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        MaxHeap freeHeap;
        for(int i = 0; i < k; ++i){
            int lrTime = time[i][0];
            int rlTime = time[i][2];
            freeHeap.push({BridgeSide::LEFT, lrTime + rlTime, i});
        }

        MinHeap busyHeap;
        int bridgeActiveTime = 0;
        while(!freeHeap.empty() || !busyHeap.empty()){
            updateBridgeActiveTime(freeHeap, busyHeap, bridgeActiveTime);
            updateHeaps(freeHeap, busyHeap, bridgeActiveTime, time);
            crossTheBridge(freeHeap, busyHeap, bridgeActiveTime, time, n);
            removeRedundantWorkers(freeHeap, busyHeap, n);
        }

        return bridgeActiveTime;
    }
};