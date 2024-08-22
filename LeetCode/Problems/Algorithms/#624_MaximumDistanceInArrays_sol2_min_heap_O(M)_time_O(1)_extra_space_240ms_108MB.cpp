class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        const int M = arrays.size();

        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> minHeap;
        for(int i = 0; i < M; ++i){
            minHeap.push({arrays[i].back(), i});
            if((int)minHeap.size() > 2){
                minHeap.pop();
            }
        }

        int indexOfSecondMax = minHeap.top().second; minHeap.pop();
        int indexOfFirstMax = minHeap.top().second; minHeap.pop();

        int maxDist = 0;
        for(int i = 0; i < M; ++i){
            if(i != indexOfFirstMax){
                maxDist = max(maxDist, arrays[indexOfFirstMax].back() - arrays[i].front());
            }
            if(i != indexOfSecondMax){
                maxDist = max(maxDist, arrays[indexOfSecondMax].back() - arrays[i].front());
            }
        }

        return maxDist;
    }
};