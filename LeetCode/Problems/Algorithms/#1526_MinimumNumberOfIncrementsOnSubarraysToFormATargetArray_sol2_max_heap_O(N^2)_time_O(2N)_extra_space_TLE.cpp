class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        vector<int> a = target;
        const int N = a.size();
        
        priority_queue<pair<int, int>> maxHeap;
        for(int i = 0; i < N; ++i){
            maxHeap.push({a[i], i});
        }
        
        int answer = 0;
        while(!maxHeap.empty()){
            int maxIdx = maxHeap.top().second;
            maxHeap.pop();
            
            if(a[maxIdx] != 0){
                answer += a[maxIdx];

                // range [maxIdx + 1, right]
                int limit = a[maxIdx];
                for(int i = maxIdx + 1; i < N && limit > 0; ++i){
                    limit = min(a[i], limit);
                    a[i] -= limit;
                }

                // range [left, maxIdx]
                limit = a[maxIdx];
                for(int i = maxIdx; i >= 0 && limit > 0; --i){
                    limit = min(a[i], limit);
                    a[i] -= limit;
                }
            }
        }
        
        return answer;
    }
};