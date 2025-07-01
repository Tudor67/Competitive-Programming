class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freqOf;
        for(int num: nums){
            freqOf[num] += 1;
        }

        int maxLen = 0;
        for(auto [minElem, minElemFreq]: freqOf){
            if(freqOf.count(minElem + 1)){
                maxLen = max(maxLen, freqOf[minElem] + freqOf[minElem + 1]);
            }
        }

        return maxLen;
    }
};