class Solution {
private:
    int computeMaxFibLen(int a, int b, vector<int>& arr){
        int maxFibLen = 2;
        while(a <= INT_MAX - b && binary_search(arr.begin(), arr.end(), a + b)){
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

        int maxFibLen = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                maxFibLen = max(maxFibLen, computeMaxFibLen(arr[i], arr[j], arr));
            }
        }

        if(maxFibLen <= 2){
            maxFibLen = 0;
        }

        return maxFibLen;
    }
};