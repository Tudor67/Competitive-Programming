class Solution {
private:
    const int INF = 1e9;
    using MaxHeap = priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>;
    using MinHeap = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;

    void updateBridgeActiveTime(MaxHeap& lFree, MinHeap& lBusy, MaxHeap& rFree, MinHeap& rBusy, int& bridgeActiveTime){
        if(lFree.empty() && rFree.empty()){
            int lMinTime = (lBusy.empty() ? INF : lBusy.top().first);
            int rMinTime = (rBusy.empty() ? INF : rBusy.top().first);
            bridgeActiveTime = max(bridgeActiveTime, min(lMinTime, rMinTime));
        }
    }

    void updateHeaps(MaxHeap& freeHeap, MinHeap& busyHeap, int& bridgeActiveTime, vector<vector<int>>& time){
        while(!busyHeap.empty() && busyHeap.top().first <= bridgeActiveTime){
            int i = busyHeap.top().second;
            int lrTime = time[i][0];
            int rlTime = time[i][2];

            busyHeap.pop();
            freeHeap.push({lrTime + rlTime, i});
        }
    }
    
    void moveFromRightToLeft(MinHeap& lBusy, MaxHeap& rFree, int& bridgeActiveTime, vector<vector<int>>& time){
        int i = rFree.top().second;
        int rlTime = time[i][2];
        int putTime = time[i][3];

        rFree.pop();
        lBusy.push({bridgeActiveTime + rlTime + putTime, i});

        bridgeActiveTime += rlTime;
    }

    void moveFromLeftToRight(MaxHeap& lFree, MinHeap& rBusy, int& bridgeActiveTime, vector<vector<int>>& time){
        int i = lFree.top().second;
        int lrTime = time[i][0];
        int pickTime = time[i][1];

        lFree.pop();
        rBusy.push({bridgeActiveTime + lrTime + pickTime, i});

        bridgeActiveTime += lrTime;
    }

    template <typename T>
    void clearHeap(T& h){
        while(!h.empty()){
            h.pop();
        }
    }

public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        MaxHeap lFree;
        MaxHeap rFree;
        for(int i = 0; i < k; ++i){
            int lrTime = time[i][0];
            int rlTime = time[i][2];
            lFree.push({lrTime + rlTime, i});
        }

        MinHeap lBusy;
        MinHeap rBusy;
        int bridgeActiveTime = 0;
        while(n > 0 || (int)rFree.size() + (int)rBusy.size() > 0){
            if(n == 0){
                clearHeap(lFree);
                clearHeap(lBusy);
            }

            updateBridgeActiveTime(lFree, lBusy, rFree, rBusy, bridgeActiveTime);
            updateHeaps(lFree, lBusy, bridgeActiveTime, time);
            updateHeaps(rFree, rBusy, bridgeActiveTime, time);

            if(rFree.empty()){
                moveFromLeftToRight(lFree, rBusy, bridgeActiveTime, time);
                n -= 1;
            }else{
                moveFromRightToLeft(lBusy, rFree, bridgeActiveTime, time);
            }
        }

        return bridgeActiveTime;
    }
};