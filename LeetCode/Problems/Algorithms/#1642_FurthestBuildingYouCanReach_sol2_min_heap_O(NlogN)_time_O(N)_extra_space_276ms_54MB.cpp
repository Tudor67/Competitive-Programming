class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int N = heights.size();
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i + 1 < N; ++i){
            int diff = (heights[i + 1] - heights[i]);
            if(diff > 0){
                minHeap.push(diff);
            }
            if(minHeap.size() > ladders){
                bricks -= minHeap.top();
                minHeap.pop();
            }
            if(bricks < 0){
                return i;
            }
        }
        
        return N - 1;
    }
};