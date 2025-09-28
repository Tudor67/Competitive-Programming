class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0;
        int maxFreqCount = 0;
        unordered_map<int, int> freqOf;
        
        for(int num: nums){
            freqOf[num] += 1;
            if(maxFreq == freqOf[num]){
                maxFreqCount += 1;
            }else if(maxFreq < freqOf[num]){
                maxFreq = freqOf[num];
                maxFreqCount = 1;
            }
        }

        return maxFreq * maxFreqCount;
    }
};