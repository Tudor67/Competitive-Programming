class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int remApples = accumulate(apple.begin(), apple.end(), 0);
        priority_queue<int> maxHeap(capacity.begin(), capacity.end());

        int boxes = 0;
        while(remApples >= 1 && !maxHeap.empty()){
            boxes += 1;
            remApples -= maxHeap.top();
            maxHeap.pop();
        }
        
        return boxes;
    }
};