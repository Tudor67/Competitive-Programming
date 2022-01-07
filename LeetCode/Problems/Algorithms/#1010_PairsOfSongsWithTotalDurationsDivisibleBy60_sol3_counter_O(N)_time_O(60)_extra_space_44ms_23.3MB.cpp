class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        const int N = time.size();
        
        vector<int> count(60, 0);
        for(int t: time){
            count[t % 60] += 1;
        }
        
        int validPairs = 0;
        for(int t: time){
            count[t % 60] -= 1;
            validPairs += count[(60 - t % 60) % 60];
        }
        
        return validPairs;
    }
};