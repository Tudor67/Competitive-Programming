class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        const int N = time.size();
        
        vector<int> count(60, 0);
        for(int t: time){
            count[t % 60] += 1;
        }
        
        int validPairs = 0;
        for(int t = 1; t <= 29; ++t){
            validPairs += (count[t] * count[60 - t]);
        }
        
        validPairs += (count[0] * (count[0] - 1LL)) / 2;
        validPairs += (count[30] * (count[30] - 1LL)) / 2;
        
        return validPairs;
    }
};