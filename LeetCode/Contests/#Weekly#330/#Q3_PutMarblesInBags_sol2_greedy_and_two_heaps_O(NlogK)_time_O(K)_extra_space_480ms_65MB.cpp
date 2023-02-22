class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        const int N = weights.size();

        int splitOperations = k - 1;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int, vector<int>, less<int>> maxHeap;
        
        for(int i = 0; i + 1 < N; ++i){
            int splitCost = weights[i] + weights[i + 1];
            minHeap.push(splitCost);
            maxHeap.push(splitCost);
            if((int)minHeap.size() > splitOperations){
                minHeap.pop();
                maxHeap.pop();
            }
        }

        long long minScore = weights[0] + weights[N - 1];
        long long maxScore = weights[0] + weights[N - 1];
        while(!minHeap.empty()){
            minScore += maxHeap.top(); maxHeap.pop();
            maxScore += minHeap.top(); minHeap.pop();
        }
        
        return maxScore - minScore;
    }
};