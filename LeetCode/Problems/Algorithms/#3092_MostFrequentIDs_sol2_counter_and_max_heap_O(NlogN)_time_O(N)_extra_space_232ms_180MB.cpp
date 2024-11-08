class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        const int N = nums.size();
        
        vector<long long> res(N);
        map<int, long long> numToFreq;
        priority_queue<pair<long long, int>> maxHeap;
        
        for(int i = 0; i < N; ++i){
            numToFreq[nums[i]] += freq[i];
            maxHeap.push({numToFreq[nums[i]], nums[i]});
            while(maxHeap.top().first != numToFreq[maxHeap.top().second]){
                maxHeap.pop();
            }
            res[i] = maxHeap.top().first;
        }
        
        return res;
    }
};