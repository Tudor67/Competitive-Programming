class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_map<int, int> cnt;
        for(int num: nums){
            cnt[num] += 1;
        }
        
        vector<vector<int>> buckets(N + 1);
        for(const pair<int, int>& p: cnt){
            int elem = p.first;
            int freq = p.second;
            buckets[freq].push_back(elem);
        }
        
        vector<int> answer;
        for(int freq = N; freq >= 1 && answer.size() < k; --freq){
            while(!buckets[freq].empty() && answer.size() < k){
                answer.push_back(buckets[freq].back());
                buckets[freq].pop_back();
            }
        }
        
        return answer;
    }
};