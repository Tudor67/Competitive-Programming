enum BridgeSide { LEFT = 0, RIGHT = 1};

class Worker{
public:
    int lrTime;
    int pickTime;
    int rlTime;
    int putTime;
    int index;
    int bridgeSide;
    int activeTime;

public:
    Worker(int lrTime, int pickTime, int rlTime, int putTime, int index, int bridgeSide, int activeTime):
          lrTime(lrTime), pickTime(pickTime), rlTime(rlTime), putTime(putTime), index(index),
          bridgeSide(bridgeSide), activeTime(activeTime){
        
    }

    static bool incBridgeSideAndEfficiencyAndIndexComp(const Worker& W1, const Worker& W2){
        return tuple<int, int, int>{W1.bridgeSide, W1.lrTime + W1.rlTime, W1.index} <
               tuple<int, int, int>{W2.bridgeSide, W2.lrTime + W2.rlTime, W2.index};
    }

    static bool decActiveTimeComp(const Worker& W1, const Worker& W2){
        return W1.activeTime > W2.activeTime;
    }
};

class Solution {
private:
    using MaxHeap = priority_queue<Worker, vector<Worker>, decltype(&Worker::incBridgeSideAndEfficiencyAndIndexComp)>;
    using MinHeap = priority_queue<Worker, vector<Worker>, decltype(&Worker::decActiveTimeComp)>;

    void removeRedundantWorkers(MaxHeap& freeHeap, MinHeap& busyHeap, int& n){
        while(n == 0 && !freeHeap.empty() && freeHeap.top().bridgeSide == BridgeSide::LEFT){
            freeHeap.pop();
        }
        while(n == 0 && !busyHeap.empty() && busyHeap.top().bridgeSide == BridgeSide::LEFT){
            busyHeap.pop();
        }
    }

    void updateBridgeActiveTime(MaxHeap& freeHeap, MinHeap& busyHeap, int& bridgeActiveTime){
        if(freeHeap.empty()){
            bridgeActiveTime = max(bridgeActiveTime, busyHeap.top().activeTime);
        }
    }

    void updateHeaps(MaxHeap& freeHeap, MinHeap& busyHeap, int& bridgeActiveTime){
        while(!busyHeap.empty() && busyHeap.top().activeTime <= bridgeActiveTime){
            Worker w = busyHeap.top();
            busyHeap.pop();
            freeHeap.push(w);
        }
    }
    
    void crossTheBridge(MaxHeap& freeHeap, MinHeap& busyHeap, int& bridgeActiveTime, int& n){
        Worker w = freeHeap.top();
        freeHeap.pop();

        if(w.bridgeSide == BridgeSide::LEFT){
            n -= 1;
            w.activeTime = bridgeActiveTime + w.lrTime + w.pickTime;
            w.bridgeSide = BridgeSide::RIGHT;
            busyHeap.push(w);
            bridgeActiveTime += w.lrTime;
        }else{
            w.activeTime = bridgeActiveTime + w.rlTime + w.putTime;
            w.bridgeSide = BridgeSide::LEFT;
            busyHeap.push(w);
            bridgeActiveTime += w.rlTime;
        }
    }

public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        MaxHeap freeHeap(Worker::incBridgeSideAndEfficiencyAndIndexComp);
        for(int i = 0; i < k; ++i){
            int lrTime = time[i][0];
            int pickTime = time[i][1];
            int rlTime = time[i][2];
            int putTime = time[i][3];
            freeHeap.push(Worker(lrTime, pickTime, rlTime, putTime, i, BridgeSide::LEFT, 0));
        }

        MinHeap busyHeap(Worker::decActiveTimeComp);
        int bridgeActiveTime = 0;
        while(!freeHeap.empty() || !busyHeap.empty()){
            updateBridgeActiveTime(freeHeap, busyHeap, bridgeActiveTime);
            updateHeaps(freeHeap, busyHeap, bridgeActiveTime);
            crossTheBridge(freeHeap, busyHeap, bridgeActiveTime, n);
            removeRedundantWorkers(freeHeap, busyHeap, n);
        }

        return bridgeActiveTime;
    }
};