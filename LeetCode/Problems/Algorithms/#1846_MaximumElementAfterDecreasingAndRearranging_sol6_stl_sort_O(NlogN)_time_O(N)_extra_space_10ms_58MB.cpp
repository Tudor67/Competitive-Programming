class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        const int N = arr.size();

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        sortedArr[0] = 1;
        for(int i = 1; i < N; ++i){
            if(sortedArr[i] > sortedArr[i - 1] + 1){
                sortedArr[i] = sortedArr[i - 1] + 1;
            }
        }

        return sortedArr.back();
    }
};