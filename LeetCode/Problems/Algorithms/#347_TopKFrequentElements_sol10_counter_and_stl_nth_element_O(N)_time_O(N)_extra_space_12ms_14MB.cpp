class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int N = nums.size();

        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }

        vector<pair<int, int>> v;
        for(const pair<int, int>& P: count){
            int num = P.first;
            int numCount = P.second;
            v.push_back({numCount, num});
        }

        nth_element(v.begin(), v.end() - k, v.end());

        vector<int> res(k);
        for(int i = 0; i < k; ++i){
            res[i] = v[(int)v.size() - 1 - i].second;
        }

        return res;
    }
};