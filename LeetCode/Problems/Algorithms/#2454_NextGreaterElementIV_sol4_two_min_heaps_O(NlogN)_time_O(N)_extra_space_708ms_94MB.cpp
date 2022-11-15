class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> answer(N, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap1;
        
        for(int i = 0; i < N; ++i){
            while(!minHeap1.empty() && minHeap1.top().first < nums[i]){
                int num = minHeap1.top().first;
                int numIndex = minHeap1.top().second;
                minHeap1.pop();
                answer[numIndex] = nums[i];
            }
            
            while(!minHeap0.empty() && minHeap0.top().first < nums[i]){
                int num = minHeap0.top().first;
                int numIndex = minHeap0.top().second;
                minHeap0.pop();
                minHeap1.emplace(num, numIndex);
            }
            
            minHeap0.emplace(nums[i], i);
        }
        
        return answer;
    }
};