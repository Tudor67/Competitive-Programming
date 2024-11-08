class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        const int N = nums.size();
        
        vector<long long> res(N);
        map<int, long long> numToFreq;
        set<pair<long long, int>> s;
        
        for(int i = 0; i < N; ++i){
            s.erase({numToFreq[nums[i]], nums[i]});
            numToFreq[nums[i]] += freq[i];
            if(numToFreq[nums[i]] == 0){
                numToFreq.erase(nums[i]);
            }else{
                s.insert({numToFreq[nums[i]], nums[i]});
            }
            
            if(!s.empty()){
                res[i] = s.rbegin()->first;
            }
        }
        
        return res;
    }
};