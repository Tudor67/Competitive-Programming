class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> es(n);
        for(int i = 0; i < n; ++i){
            es[i] = {efficiency[i], speed[i]};
        }
        
        sort(es.begin(), es.end());
        
        const int MODULO = 1e9 + 7;
        long long maxPerformance = 0;
        long long maxSpeedSum = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = n - 1; i >= 0; --i){
            int curEfficiency = es[i].first;
            int curSpeed = es[i].second;
            maxSpeedSum += curSpeed;
            minHeap.push(curSpeed);
            if((int)minHeap.size() > k){
                maxSpeedSum -= minHeap.top();
                minHeap.pop();
            }
            maxPerformance = max(curEfficiency * maxSpeedSum, maxPerformance);
        }
        
        return maxPerformance % MODULO;
    }
};