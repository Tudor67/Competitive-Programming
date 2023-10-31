class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        const int N = arr.size();
        const int MAX_NUM = *max_element(arr.begin(), arr.end());
        const int MAX_NON_ZERO_BITS = log2(MAX_NUM + 1) + 1;

        vector<int> count(MAX_NUM + 1);
        for(int num: arr){
            count[num] += 1;
        }

        vector<vector<int>> buckets(MAX_NON_ZERO_BITS + 1);
        for(int num = 0; num <= MAX_NUM; ++num){
            while(count[num] > 0){
                buckets[__builtin_popcount(num)].push_back(num);
                count[num] -= 1;
            }
        }

        vector<int> sortedArr;
        sortedArr.reserve(N);
        for(int nonZeroBits = 0; nonZeroBits <= MAX_NON_ZERO_BITS; ++nonZeroBits){
            for(int num: buckets[nonZeroBits]){
                sortedArr.push_back(num);
            }
        }

        return sortedArr;
    }
};