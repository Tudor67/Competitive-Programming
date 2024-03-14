class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        int maxFreq = 0;
        int totalMaxFreq = 0;
        vector<int> freq(MAX_NUM + 1);

        for(int num: nums){
            freq[num] += 1;
            if(maxFreq < freq[num]){
                maxFreq = freq[num];
                totalMaxFreq = maxFreq;
            }else if(maxFreq == freq[num]){
                totalMaxFreq += maxFreq;
            }
        }

        return totalMaxFreq;
    }
};