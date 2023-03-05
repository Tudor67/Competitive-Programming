class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        const int N = nums.size();

        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int, vector<int>, less<int>> maxHeap;
        for(int num: nums){
            minHeap.push(num);
            maxHeap.push(num);
            if((int)minHeap.size() > 3){
                minHeap.pop();
                maxHeap.pop();
            }
        }

        vector<int> minNums(3);
        vector<int> maxNums(3);
        for(int i = 2; i >= 0; --i){
            minNums[i] = maxHeap.top(); maxHeap.pop();
            maxNums[i] = minHeap.top(); minHeap.pop();
        }

        int score1 = maxNums[0] - minNums[2];
        int score2 = maxNums[1] - minNums[1];
        int score3 = maxNums[2] - minNums[0];

        return min({score1, score2, score3});
    }
};