class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        const int N = nums.size();

        unordered_map<int, int> freqOf;
        int maxFreq = 0;
        for(int num: nums){
            freqOf[num] += 1;
            maxFreq = max(maxFreq, freqOf[num]);
        }

        return N - maxFreq;
    }
};