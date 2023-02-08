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

        unordered_map<int, vector<int>> buckets;
        for(int num = MAX_NUM; num >= MIN_NUM; --num){
            if(freq.count(num)){
                buckets[freq[num]].push_back(num);
            }
        }

        vector<int> sortedNums;
        sortedNums.reserve(N);
        for(int f = 1; f <= maxFreq; ++f){
            if(buckets.count(f)){
                const vector<int>& V = buckets[f];
                for(int num: V){
                    for(int i = 1; i <= f; ++i){
                        sortedNums.push_back(num);
                    }
                }
            }
        }

        return sortedNums;
    }
};