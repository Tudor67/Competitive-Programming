class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        const int N = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int heapMaxNum = 0;
        for(int num: nums){
            int startNum = num;
            int endNum = (num % 2 == 0 ? num : 2 * num);
            while(startNum % 2 == 0){
                startNum /= 2;
            }
            minHeap.push({startNum, endNum});
            heapMaxNum = max(heapMaxNum, startNum);
        }

        int res = heapMaxNum - minHeap.top().first;
        while((int)minHeap.size() == N && res > 0){
            res = min(res, heapMaxNum - minHeap.top().first);

            int startNum = minHeap.top().first;
            int endNum = minHeap.top().second;
            minHeap.pop();

            if(2 * startNum <= endNum){
                minHeap.push({2 * startNum, endNum});
                heapMaxNum = max(heapMaxNum, 2 * startNum);
            }
        }

        return res;
    }
};