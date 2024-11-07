class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        const int N = candidates.size();
        const int MAX_NUM = *max_element(candidates.begin(), candidates.end());
        const int MAX_BIT = log2(MAX_NUM) + 1;

        vector<int> freq(MAX_BIT + 1);
        for(int candidate: candidates){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((candidate >> bit) & 1){
                    freq[bit] += 1;
                }
            }
        }

        return *max_element(freq.begin(), freq.end());
    }
};