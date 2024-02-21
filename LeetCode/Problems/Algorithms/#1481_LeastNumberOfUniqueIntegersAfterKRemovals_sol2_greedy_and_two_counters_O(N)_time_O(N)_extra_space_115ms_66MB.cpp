class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        const int N = arr.size();

        unordered_map<int, int> freqOf;
        for(int num: arr){
            freqOf[num] += 1;
        }

        vector<int> counter(N + 1);
        for(const pair<const int, int>& P: freqOf){
            int numFreq = P.second;
            counter[numFreq] += 1;
        }

        int res = freqOf.size();
        for(int numFreq = 1; numFreq <= N; ++numFreq){
            while(counter[numFreq] >= 1 && numFreq <= k){
                k -= numFreq;
                counter[numFreq] -= 1;
                res -= 1;
            }
        }

        return res;
    }
};