class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        priority_queue<int> maxHeap(capacity.begin(), capacity.end());

        int remApples = accumulate(apple.begin(), apple.end(), 0);
        while(remApples > 0 && !maxHeap.empty()){
            remApples -= maxHeap.top();
            maxHeap.pop();
        }

        return (int)capacity.size() - (int)maxHeap.size();
    }
};