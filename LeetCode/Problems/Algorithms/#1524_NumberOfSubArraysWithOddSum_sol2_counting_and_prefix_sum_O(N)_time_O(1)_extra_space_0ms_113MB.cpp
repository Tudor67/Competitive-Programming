class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int N = arr.size();
        const int MODULO = 1'000'000'007;

        vector<int> freq(2);
        freq[0] = 1;

        int prefSumParity = 0;
        for(int elem: arr){
            prefSumParity = (prefSumParity + elem) % 2;
            freq[prefSumParity] += 1;
        }

        return (long long)freq[0] * (long long)freq[1] % MODULO;
    }
};