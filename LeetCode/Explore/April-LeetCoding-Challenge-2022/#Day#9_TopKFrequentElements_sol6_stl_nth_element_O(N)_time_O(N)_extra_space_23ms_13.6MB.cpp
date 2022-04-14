class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_map<int, int> freqOf;
        for(int num: nums){
            freqOf[num] += 1;
        }
        
        vector<pair<int, int>> v;
        for(const pair<int, int>& P: freqOf){
            int num = P.first;
            int numFreq = P.second;
            v.emplace_back(numFreq, num);
        }
        
        nth_element(v.begin(), v.end() - k, v.end());
        
        vector<int> res(k);
        for(int i = 0; i < k; ++i){
            res[i] = v[(int)v.size() - 1 - i].second;
        }
        
        return res;
    }
};