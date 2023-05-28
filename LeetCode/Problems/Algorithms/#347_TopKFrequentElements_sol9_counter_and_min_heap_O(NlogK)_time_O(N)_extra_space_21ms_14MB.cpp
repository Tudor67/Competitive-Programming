class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int N = nums.size();

        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(const pair<int, int>& P: count){
            int num = P.first;
            int numCount = P.second;
            minHeap.push({numCount, num});
            if((int)minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> res;
        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};