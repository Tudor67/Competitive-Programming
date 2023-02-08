class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        const int N = gain.size();

        int res = 0;
        int prefixSum = 0;
        for(int i = 0; i < N; ++i){
            prefixSum += gain[i];
            res = max(res, prefixSum);
        }
        
        return res;
    }
};