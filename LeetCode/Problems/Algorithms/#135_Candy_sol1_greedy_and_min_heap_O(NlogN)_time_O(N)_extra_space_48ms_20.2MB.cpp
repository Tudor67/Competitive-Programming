class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i < N; ++i){
            minHeap.push({ratings[i], i});
        }
        
        vector<int> candies(N, 1);
        while(!minHeap.empty()){
            int idx = minHeap.top().second;
            minHeap.pop();
            
            for(int neighIdx: {idx - 1, idx + 1}){
                if(0 <= neighIdx && neighIdx < N && ratings[idx] < ratings[neighIdx] && candies[idx] >= candies[neighIdx]){
                    candies[neighIdx] = 1 + candies[idx];
                }
            }
        }
        
        int totalCandies = 0;
        for(int i = 0; i < N; ++i){
            totalCandies += candies[i];
        }
        
        return totalCandies;
    }
};