class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        const int N = nums.size();

        priority_queue<int> maxHeap;
        int heapMinNum = INT_MAX;
        for(int num: nums){
            if(num % 2 == 1){
                num *= 2;
            }
            maxHeap.push(num);
            heapMinNum = min(heapMinNum, num);
        }

        int res = INT_MAX;
        while((int)maxHeap.size() == N && res > 0){
            res = min(res, maxHeap.top() - heapMinNum);

            int num = maxHeap.top();
            maxHeap.pop();

            if(num % 2 == 0){
                maxHeap.push(num / 2);
                heapMinNum = min(heapMinNum, num / 2);
            }
        }

        return res;
    }
};