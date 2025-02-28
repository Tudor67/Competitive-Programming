class Solution {
private:
    int computeMaxFibLen(int a, int b, unordered_set<int>& numsSet){
        int maxFibLen = 2;
        while(a <= INT_MAX - b && numsSet.count(a + b)){
            maxFibLen += 1;
            int c = a + b;
            a = b;
            b = c;
        }
        return maxFibLen;
    }

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        const int N = arr.size();

        unordered_set<int> numsSet(arr.begin(), arr.end());

        int maxFibLen = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                maxFibLen = max(maxFibLen, computeMaxFibLen(arr[i], arr[j], numsSet));
            }
        }

        if(maxFibLen <= 2){
            maxFibLen = 0;
        }

        return maxFibLen;
    }
};