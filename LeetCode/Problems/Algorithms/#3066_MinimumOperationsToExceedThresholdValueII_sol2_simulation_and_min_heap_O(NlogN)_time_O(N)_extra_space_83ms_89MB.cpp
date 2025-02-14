class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalOps = 0;
        priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> minHeap(nums.begin(), nums.end());

        while((int)minHeap.size() >= 2 && minHeap.top() < k){
            unsigned int a = minHeap.top(); minHeap.pop();
            unsigned int b = minHeap.top(); minHeap.pop();

            totalOps += 1;

            minHeap.push(2 * a + b);
        }

        return totalOps;
    }
};