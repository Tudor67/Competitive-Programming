class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        const int N = arr.size();

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        int res = 0;
        for(int i = 0; i < N; ++i){
            if(res + 1 <= sortedArr[i]){
                res += 1;
            }
        }

        return res;
    }
};