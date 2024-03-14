class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        const int N = nums.size();

        int maxFreq = 0;
        int totalMaxFreq = 0;
        unordered_map<int, int> freq;

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