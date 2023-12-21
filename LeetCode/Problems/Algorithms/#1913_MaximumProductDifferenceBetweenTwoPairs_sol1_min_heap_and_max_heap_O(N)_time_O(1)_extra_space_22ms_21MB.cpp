class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        const int N = nums.size();

        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int, vector<int>, less<int>> maxHeap;
        for(int num: nums){
            minHeap.push(num);
            maxHeap.push(num);
            if((int)minHeap.size() > 2){
                minHeap.pop();
            }
            if((int)maxHeap.size() > 2){
                maxHeap.pop();
            }
        }

        int min2 = maxHeap.top(); maxHeap.pop();
        int min1 = maxHeap.top(); maxHeap.pop();

        int max2 = minHeap.top(); minHeap.pop();
        int max1 = minHeap.top(); minHeap.pop();

        return max2 * max1 - min2 * min1;
    }
};