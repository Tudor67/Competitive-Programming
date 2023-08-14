class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int N = nums.size();

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num: nums){
            minHeap.push(num);
            if((int)minHeap.size() > k){
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};