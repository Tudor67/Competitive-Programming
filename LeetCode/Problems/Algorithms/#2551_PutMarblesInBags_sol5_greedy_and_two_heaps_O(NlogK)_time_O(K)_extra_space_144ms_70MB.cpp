class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        const int N = weights.size();

        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int, vector<int>, less<int>> maxHeap;
        for(int i = 0; i + 1 < N; ++i){
            minHeap.push(weights[i] + weights[i + 1]);
            maxHeap.push(weights[i] + weights[i + 1]);
            if((int)minHeap.size() == k){
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

        return (maxScore - minScore);
    }
};