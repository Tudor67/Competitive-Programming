class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60, 0);
        for(int t: time){
            count[t % 60] += 1;
        }
        
        int pairs = (long long)count[0] * (count[0] - 1) / 2 + (long long)count[30] * (count[30] - 1) / 2;
        for(int t = 1; t < 30; ++t){
            pairs += count[t] * count[60 - t];
        }
        
        return pairs;
    }
};