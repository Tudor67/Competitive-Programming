class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int N = heights.size();
        
        int maxIdx = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i + 1 < N; ++i){
            if(heights[i] < heights[i + 1]){
                minHeap.push(heights[i + 1] - heights[i]);
                if((int)minHeap.size() == ladders + 1){
                    bricks -= minHeap.top();
                    minHeap.pop();
                }
                if(bricks < 0){
                    break;
                }
            }
            maxIdx = i + 1;
        }
        
        return maxIdx;
    }
};