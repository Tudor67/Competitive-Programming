class Solution {
public:
    int minimumCost(vector<int>& nums) {
        const int N = nums.size();
        const int K = 3;

        priority_queue<int> maxHeap;
        for(int i = 1; i < N; ++i){
            maxHeap.push(nums[i]);
            if((int)maxHeap.size() > K - 1){
                maxHeap.pop();
            }
        }

        int minCost = nums[0];
        while(!maxHeap.empty()){
            minCost += maxHeap.top();
            maxHeap.pop();
        }

        return minCost;
    }
};