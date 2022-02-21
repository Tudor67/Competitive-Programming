class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        const int N = nums.size();
        
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> minHeap;
        int currentMax = INT_MIN;
        for(int i = 0; i < N; ++i){
            if(nums[i] % 2 == 0){
                int maxNum = nums[i];
                int minNum = nums[i];
                while(minNum % 2 == 0){
                    minNum /= 2;
                }
                minHeap.emplace(minNum, maxNum);
                currentMax = max(currentMax, minNum);
            }else{
                minHeap.emplace(nums[i], 2 * nums[i]);
                currentMax = max(currentMax, nums[i]);
            }
        }
        
        int minDiff = currentMax - minHeap.top().first;
        while((int)minHeap.size() == N && minDiff > 0){
            int diff = currentMax - minHeap.top().first;
            minDiff = min(minDiff, diff);
            
            int x = minHeap.top().first;
            int y = minHeap.top().second;
            minHeap.pop();
            
            if(x < y){
                minHeap.emplace(2 * x, y);
                currentMax = max(currentMax, 2 * x);
            }
        }
        
        return minDiff;
    }
};