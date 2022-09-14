class Solution {
public:
    int maxPerformance(int N, vector<int>& speed, vector<int>& efficiency, int K) {
        const long long MODULO = 1e9 + 7;
        
        vector<pair<int, int>> es(N);
        for(int i = 0; i < N; ++i){
            es[i] = {efficiency[i], speed[i]};
        }
        
        sort(es.begin(), es.end());
        
        long long res = 0;
        long long maxKSpeedSum = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i = N - 1; i >= 0; --i){
            long long minEfficiency = es[i].first;
            long long currentSpeed = es[i].second;
            
            maxKSpeedSum += currentSpeed;
            minHeap.push(currentSpeed);
            if((int)minHeap.size() > K){
                maxKSpeedSum -= minHeap.top();
                minHeap.pop();
            }
            
            res = max(res, minEfficiency * maxKSpeedSum);
        }
        
        return res % MODULO;
    }
};