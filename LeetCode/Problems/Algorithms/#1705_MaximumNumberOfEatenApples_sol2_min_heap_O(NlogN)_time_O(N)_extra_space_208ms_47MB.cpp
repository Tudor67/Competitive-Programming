class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        const int N = apples.size();
        
        int res = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i < N; ++i){
            if(apples[i] >= 1){
                int lastDay = i + days[i] - 1;
                int applesCount = apples[i];
                minHeap.emplace(lastDay, applesCount);
            }
            
            while(!minHeap.empty() && minHeap.top().first < i){
                minHeap.pop();
            }
            
            if(!minHeap.empty()){
                int lastDay = minHeap.top().first;
                int applesCount = minHeap.top().second;
                minHeap.pop();
                
                if(applesCount - 1 >= 1){
                    minHeap.emplace(lastDay, applesCount - 1);
                }
                
                res += 1;
            }
        }
        
        int i = N;
        while(!minHeap.empty()){
            int lastDay = minHeap.top().first;
            int applesCount = minHeap.top().second;
            minHeap.pop();
            
            int takenApples = min(applesCount, lastDay - i + 1);
            res += takenApples;
            i += takenApples;
        }
        
        return res;
    }
};