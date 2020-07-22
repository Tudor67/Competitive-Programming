class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int num: nums){
            cnt[num] += 1;
        }
        
        vector<pair<int, int>> v;
        for(const pair<int, int>& p: cnt){
            int freq = p.second;
            int elem = p.first;
            v.push_back({freq, elem});
        }
        
        nth_element(v.begin(), v.begin() + (int)v.size() - k, v.end());
        
        vector<int> answer;
        for(int i = (int)v.size() - 1; i >= (int)v.size() - k; --i){
            answer.push_back(v[i].second);
        }
        
        return answer;
    }
};