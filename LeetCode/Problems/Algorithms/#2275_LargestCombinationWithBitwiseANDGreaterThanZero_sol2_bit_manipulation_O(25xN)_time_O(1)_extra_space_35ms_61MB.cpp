class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        const int N = candidates.size();
        const int MAX_NUM = *max_element(candidates.begin(), candidates.end());
        const int MAX_BIT = log2(MAX_NUM) + 1;

        int res = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            int bitFreq = 0;
            for(int candidate: candidates){
                if((candidate >> bit) & 1){
                    bitFreq += 1;
                }
            }
            res = max(res, bitFreq);
        }

        return res;
    }
};