class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int N = heights.size();
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i + 1 < N; ++i){
            if(heights[i] >= heights[i + 1]){
                continue;
            }
            minHeap.push(heights[i + 1] - heights[i]);
            if(ladders >= 1){
                ladders -= 1;
            }else{
                if(bricks >= minHeap.top()){
                    bricks -= minHeap.top();
                    minHeap.pop();
                }else{
                    return i;
                }
            }
        }
        
        return N - 1;
    }
};