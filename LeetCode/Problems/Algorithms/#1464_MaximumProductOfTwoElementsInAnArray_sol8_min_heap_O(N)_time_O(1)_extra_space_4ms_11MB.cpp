class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        const int K = 2;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num: nums){
            minHeap.push(num);
            if((int)minHeap.size() > K){
                minHeap.pop();
            }
        }

        int res = 1;
        while(!minHeap.empty()){
            int num = minHeap.top();
            minHeap.pop();

            res *= (num - 1);
        }

        return res;
    }
};