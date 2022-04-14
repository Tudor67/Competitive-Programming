class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_map<int, int> freqOf;
        for(int num: nums){
            freqOf[num] += 1;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(const pair<int, int>& P: freqOf){
            int num = P.first;
            int numFreq = P.second;
            minHeap.emplace(numFreq, num);
            if((int)minHeap.size() == k + 1){
                minHeap.pop();
            }
        }
        
        vector<int> res(k);
        for(int i = 0; i < k; ++i){
            res[i] = minHeap.top().second;
            minHeap.pop();
        }
        
        return res;
    }
};