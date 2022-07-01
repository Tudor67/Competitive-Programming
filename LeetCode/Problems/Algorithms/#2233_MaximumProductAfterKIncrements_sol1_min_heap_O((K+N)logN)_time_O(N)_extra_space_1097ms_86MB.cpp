class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int MODULO = 1e9 + 7;
        
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        for(int i = 1; i <= k; ++i){
            int num = minHeap.top();
            minHeap.pop();
            minHeap.push(num + 1);
        }
        
        long long p = 1;
        while(!minHeap.empty()){
            int num = minHeap.top();
            minHeap.pop();
            p *= num;
            p %= MODULO;
        }
        
        return p;
    }
};