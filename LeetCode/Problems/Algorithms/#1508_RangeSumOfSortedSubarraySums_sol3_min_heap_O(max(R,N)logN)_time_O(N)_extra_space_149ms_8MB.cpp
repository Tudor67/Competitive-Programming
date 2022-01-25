class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;
        
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> minHeap;
        
        for(int i = 0; i < N; ++i){
            minHeap.emplace(nums[i], i);
        }
        
        int answer = 0;
        for(int sumIdx = 1; sumIdx <= right; ++sumIdx){
            int currentSum = minHeap.top().first;
            int currentIdx = minHeap.top().second;
            minHeap.pop();
            
            if(sumIdx >= left){
                answer += currentSum;
                answer %= MODULO;
            }
            
            if(currentIdx + 1 < N){
                minHeap.emplace(currentSum + nums[currentIdx + 1], currentIdx + 1);
            }
        }
        
        return answer;
    }
};