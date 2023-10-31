class Solution {
private:
    int countNonZeroBits(int num){
        int nonZeroBits = 0;
        while(num > 0){
            num &= (num - 1);
            nonZeroBits += 1;
        }
        return nonZeroBits;
    }

public:
    vector<int> sortByBits(vector<int>& arr) {
        const int N = arr.size();
        const int MAX_NUM = *max_element(arr.begin(), arr.end());
        const int MAX_BIT = log2(MAX_NUM + 1);

        vector<int> sortedArr(N);
        for(int i = 0; i < N; ++i){
            sortedArr[i] = (countNonZeroBits(arr[i]) << (MAX_BIT + 1)) | arr[i];
        }

        sort(sortedArr.begin(), sortedArr.end());

        for(int i = 0; i < N; ++i){
            sortedArr[i] = sortedArr[i] & ((1 << MAX_BIT + 1) - 1);
        }

        return sortedArr;
    }
};