class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        unordered_map<int, int> freq;
        int maxFreq = 0;
        for(int num: nums){
            freq[num] += 1;
            maxFreq = max(maxFreq, freq[num]);
        }

        vector<vector<int>> buckets(maxFreq + 1);
        for(int num = MAX_NUM; num >= MIN_NUM; --num){
            if(freq.count(num)){
                for(int f = 1; f <= freq[num]; ++f){
                    buckets[freq[num]].push_back(num);
                }
            }
        }

        vector<int> res;
        for(int f = 1; f <= maxFreq; ++f){
            for(int num: buckets[f]){
                res.push_back(num);
            }
        }

        return res;
    }
};