class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int, vector<int>, less<int>> maxHeap;

        for(int num: nums){
            minHeap.push(num);
            if((int)minHeap.size() > 3){
                minHeap.pop();
            }

            maxHeap.push(num);
            if((int)maxHeap.size() > 2){
                maxHeap.pop();
            }
        }

        int max3 = minHeap.top(); minHeap.pop();
        int max2 = minHeap.top(); minHeap.pop();
        int max1 = minHeap.top(); minHeap.pop();

        int min2 = maxHeap.top(); maxHeap.pop();
        int min1 = maxHeap.top(); maxHeap.pop();

        return max(min1 * min2 * max1,
                   max3 * max2 * max1);
    }
};