class Solution {
public:
    int minDifference(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 4){
            return 0;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int, vector<int>, less<int>> maxHeap;
        for(int num: nums){
            minHeap.push(num);
            maxHeap.push(num);
            if((int)minHeap.size() > 4){
                minHeap.pop();
                maxHeap.pop();
            }
        }

        vector<int> smallNums;
        vector<int> largeNums;
        while(!minHeap.empty()){
            smallNums.push_back(maxHeap.top());
            largeNums.push_back(minHeap.top());
            maxHeap.pop();
            minHeap.pop();
        }

        reverse(smallNums.begin(), smallNums.end());

        int minDiff = largeNums.back() - smallNums.front();
        for(int i = 0; i < (int)smallNums.size(); ++i){
            minDiff = min(minDiff, largeNums[i] - smallNums[i]);
        }

        return minDiff;
    }
};