class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int N = nums.size();

        unordered_map<int, int> count;
        int maxCount = 0;
        for(int num: nums){
            count[num] += 1;
            maxCount = max(maxCount, count[num]);
        }

        vector<vector<int>> buckets(maxCount + 1);
        for(const pair<int, int>& P: count){
            int num = P.first;
            int numCount = P.second;
            buckets[numCount].push_back(num);
        }

        vector<int> res;
        res.reserve(k);
        for(int numCount = maxCount; numCount >= 1 && (int)res.size() < k; --numCount){
            while(!buckets[numCount].empty() && (int)res.size() < k){
                res.push_back(buckets[numCount].back());
                buckets[numCount].pop_back();
            }
        }

        return res;
    }
};