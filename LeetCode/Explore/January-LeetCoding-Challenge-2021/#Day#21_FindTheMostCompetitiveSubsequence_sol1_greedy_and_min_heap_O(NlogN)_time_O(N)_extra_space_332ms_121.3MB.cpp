class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        const int N = nums.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i < N - k; ++i){
            minHeap.push({nums[i], i});
        }
        
        vector<int> answer;
        int minPossiblePos = 0;
        for(int i = N - k; i < N; ++i){
            minHeap.push({nums[i], i});
            while(minHeap.top().second < minPossiblePos){
                minHeap.pop();
            }
            int num = minHeap.top().first;
            int pos = minHeap.top().second;
            minHeap.pop();
            answer.push_back(num);
            minPossiblePos = pos + 1;
        }
        
        return answer;
    }
};