class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> freq(MAX_NUM + 1);
        for(int num: nums){
            freq[num] += 1;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxFreqCount = count(freq.begin(), freq.end(), maxFreq);

        return maxFreq * maxFreqCount;
    }
};