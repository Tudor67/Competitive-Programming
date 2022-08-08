class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num: nums){
            if(num > 0){
                minHeap.push(num);
            }
        }
        
        int res = 0;
        while(!minHeap.empty()){
            int num = minHeap.top();
            minHeap.top();
            
            while(!minHeap.empty() && minHeap.top() == num){
                minHeap.pop();
            }
            
            res += 1;
        }
        
        return res;
    }
};