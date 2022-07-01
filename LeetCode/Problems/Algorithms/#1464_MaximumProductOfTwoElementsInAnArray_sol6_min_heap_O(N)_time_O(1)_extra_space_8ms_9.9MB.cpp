class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num: nums){
            minHeap.push(num);
            if(minHeap.size() == 3){
                minHeap.pop();
            }
        }
        
        int max2 = minHeap.top(); minHeap.pop();
        int max1 = minHeap.top(); minHeap.pop();
        
        return (max1 - 1) * (max2 - 1);
    }
};