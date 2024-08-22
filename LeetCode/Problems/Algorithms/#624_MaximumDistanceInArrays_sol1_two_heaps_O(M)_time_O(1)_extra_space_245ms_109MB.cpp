class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        const int M = arrays.size();

        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> minHeap;
        priority_queue<PII, vector<PII>, less<PII>> maxHeap;

        for(int i = 0; i < M; ++i){
            minHeap.push({arrays[i].back(), i});
            maxHeap.push({arrays[i].front(), i});
            if((int)minHeap.size() > 2){
                minHeap.pop();
                maxHeap.pop();
            }
        }

        vector<PII> mins(2);
        vector<PII> maxs(2);
        for(int i = 0; i < 2; ++i){
            mins[i] = maxHeap.top(); maxHeap.pop();
            maxs[i] = minHeap.top(); minHeap.pop();
        }

        int maxDist = 0;
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 2; ++j){
                if(maxs[i].second != mins[j].second){
                    int dist = maxs[i].first - mins[j].first;
                    maxDist = max(maxDist, dist);
                }
            }
        }

        return maxDist;
    }
};