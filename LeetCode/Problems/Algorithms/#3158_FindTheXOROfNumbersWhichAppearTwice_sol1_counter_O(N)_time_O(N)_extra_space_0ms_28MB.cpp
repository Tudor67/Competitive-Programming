class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> freqOf;
        for(int num: nums){
            freqOf[num] += 1;
        }

        int res = 0;
        for(auto& [num, numFreq]: freqOf){
            if(numFreq == 2){
                res ^= num;
            }
        }

        return res;
    }
};