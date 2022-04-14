class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int maxFreq = 0;
        unordered_map<int, int> freqOf;
        for(int num: nums){
            freqOf[num] += 1;
            maxFreq = max(maxFreq, freqOf[num]);
        }
        
        vector<vector<int>> buckets(maxFreq + 1);
        for(const pair<int, int>& P: freqOf){
            int num = P.first;
            int numFreq = P.second;
            buckets[numFreq].push_back(num);
        }
        
        vector<int> res;
        for(int numFreq = maxFreq; numFreq >= 1; --numFreq){
            while((int)res.size() < k && !buckets[numFreq].empty()){
                res.push_back(buckets[numFreq].back());
                buckets[numFreq].pop_back();
            }
        }
        
        return res;
    }
};