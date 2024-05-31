class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int N = arr.size();

        int res = 0;
        int prefXOR = 0;
        unordered_map<int, int> freq = {{0, 1}};
        unordered_map<int, int> indicesSum = {{0, -1}};

        for(int i = 0; i < N; ++i){
            prefXOR ^= arr[i];
            res += freq[prefXOR] * (i - 1) - indicesSum[prefXOR];
            freq[prefXOR] += 1;
            indicesSum[prefXOR] += i;
        }

        return res;
    }
};